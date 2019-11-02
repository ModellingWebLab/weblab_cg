#
# Functions related to generating model code for Chaste.
#

# TODO: apply unit conversions to state variables voltage, time, cytosolic_calcium_concentration and update equations accordingly



import logging
import os
import time
import sympy as sp
import weblab_cg as cg
from pint import errors

logging.getLogger().setLevel(logging.INFO)


class ChasteModel(object):
    _MEMBRANE_VOLTAGE_INDEX = 0
    _CYTOSOLIC_CALCIUM_CONCENTRATION_INDEX = 1
    _OXMETA = "https://chaste.comlab.ox.ac.uk/cellml/ns/oxford-metadata#"

    _UNIT_DEFINITIONS = {'uA_per_cm2': [{'prefix': 'micro', 'units': 'ampere'},
                                        {'exponent': '-2', 'prefix': 'centi', 'units': 'metre'}],
                         'uA_per_uF': [{'prefix': 'micro', 'units': 'ampere'},
                                       {'exponent': '-1', 'prefix': 'micro', 'units': 'farad'}],
                         'uA': [{'prefix': 'micro', 'units': 'ampere'}],
                         'uF': [{'prefix': 'micro', 'units': 'farad'}],
                         'millisecond': [{'prefix': 'milli', 'units': 'second'}],
                         'millimolar': [{'units': 'mole', 'prefix': 'milli'}, {'units': 'litre', 'exponent': '-1'}],
                         'millivolt': [{'prefix': 'milli', 'units': 'volt'}]}

    _STIMULUS_CURRENT = "membrane_stimulus_current"
    _STIMULUS_UNITS = {'membrane_stimulus_current_period': 'millisecond',
                       'membrane_stimulus_current_duration': 'millisecond',
                       'membrane_stimulus_current_amplitude': 'uA_per_cm2',
                       'membrane_stimulus_current_offset': 'millisecond',
                       'membrane_stimulus_current_end': 'millisecond',
                       'membrane_stimulus_current': 'uA_per_cm2',
                       'membrane_capacitance': 'uF'}
    _STIMULUS_SECONDARY_UNITS = {'membrane_stimulus_current_amplitude': 'uA_per_uF',
                                 'membrane_stimulus_current': 'uA'}
    _STIMULUS_TERTIARY_UNITS = {'membrane_stimulus_current_amplitude': 'uA'}
    _STIMULUS_RHS_MULTIPLIER = {'membrane_stimulus_current_amplitude': ' * HeartConfig::Instance()->GetCapacitance()'}

    def __init__(self, model, model_name_for_filename, class_name):
        """Initialise a ChasteModel instance
        Arguments

        ``model``
            A :class:`cellmlmanip.Model` object.
        ``output_path``
            The path to store the generated model code at.
            (Just the path, excluding the file name as file name will be determined by the model_name)
        ``model_name_for_filename``
            The model name as you want it to appear in generated cpp and hpp files.
        """
        self._logger = logging.getLogger(__name__)
        self._logger.setLevel(logging.INFO)


        # Store parameters for future reference
        self._model = model
        self._model_name_for_filename = model_name_for_filename
        self._class_name = class_name

        self._add_units()

        self._membrane_voltage_var = self._get_membrane_voltage_var()
        self._cytosolic_calcium_concentration_var = self._get_cytosolic_calcium_concentration_var()
        self._state_vars = self._get_state_variables()
        self._membrane_stimulus_current = self._get_membrane_stimulus_current()
        self._membrane_stimulus_current_units = self._get__membrane_stimulus_current_units()
        self._membrane_capacitance = self._get_membrane_capacitance()
        self._default_stimulus = self._get_stimulus_currents()
        self._desired_ionic_current_units, self._ionic_current_factor = self._get_stimulus_currents_desired_units()
        self._ionic_derivs = self._get_ionic_derivs()
        self._equations_for_ionic_vars = self._get_equations_for_ionic_vars()
        self._extended_equations_for_ionic_vars = self._get_extended_equations_for_ionic_vars()

        self._y_derivatives = self._get_y_derivatives()
        self._y_derivatives_voltage = self._get_y_derivatives_voltage()
        self._y_derivatives_excl_voltage = self._get_y_derivatives_excl_voltage()
        self._derivative_eqs_voltage = self._get_derivative_eqs_voltage()
        self._derivative_eqs_exlc_voltage = self._get_derivative_eqs_exlc_voltage()
        self._derivative_equations = self._get_derivative_equations()
        self._use_get_intracellular_calcium_concentration = self._get_use_get_intracellular_calcium_concentration()

        self._add_printers()
        self._formatted_state_vars = self._format_state_variables()
        self._formatted_default_stimulus = self._format_stimulus_currents()
        self._formatted_equations_for_ionic_vars = self._format_equations_for_ionic_vars()
        self._formatted_extended_equations_for_ionic_vars = self._format_extended_equations_for_ionic_vars()
        self._formatted_y_derivatives = self._format_y_derivatives()
        self._formatted_derivative_eqs = self._format_derivative_equations()
        self._format_system_info()

    def write_chaste_code(self, output_path):
        raise NotImplementedError("Should not be called directly, use the specific model types instead!")

    def _add_printers(self):
        # Initialise Printers for outputting chaste code
        # Printer for printing chaste state variable assignments (var_chaste_interface prefix)
        self._var_chaste_interface_printer =\
            cg.ChastePrinter(lambda symbol: 'var_chaste_interface_' + str(symbol).replace('$', '__'),
                             lambda deriv: 'd_dt_chaste_interface_' + (str(deriv.expr).replace('$', '__')
                             if isinstance(deriv, sp.Derivative) else str(deriv).replace('$', '__')))

        # Printer for printing chaste regular variable assignments (var_ prefix)
        self._printer = \
            cg.ChastePrinter(lambda symbol, state_vars=self._state_vars:
                             ('var_chaste_interface_' if symbol in state_vars else 'var')
                             + str(symbol).replace('$', '__'),
                             lambda deriv: 'd_dt_chaste_interface_' +
                                           (str(deriv.expr).replace('$', '__')
                                            if isinstance(deriv, sp.Derivative) else str(deriv).replace('$', '__')))

        # Printer for printing chaste regular variable assignments without the var_ prefix
        self._name_printer = cg.ChastePrinter(lambda symbol: str(symbol)[1:].replace('$', '__'))

    def _add_units(self):
        # Add all needed units to the model (for conversion) if they don't yet exist
        for unit_name in self._UNIT_DEFINITIONS:
            self._model.units.add_preferred_custom_unit_name(unit_name, self._UNIT_DEFINITIONS[unit_name])

    def _get_membrane_voltage_var(self):
        return self._model.get_symbol_by_ontology_term(self._OXMETA, "membrane_voltage")

    def _get_cytosolic_calcium_concentration_var(self):
        try:
            return self._model.get_symbol_by_ontology_term(self._OXMETA, "cytosolic_calcium_concentration")
        except KeyError:
            self._logger.debug(self._model.name + ' has no cytosolic_calcium_concentration')
            return None

    def _get_state_variables(self):
        # Sort the state variables, to make sure they have similar order to pycml
        return sorted(self._model.get_state_symbols(order_by_order_added=True),
                      key=lambda state_var: self._state_var_key_order(state_var))

    def _get_membrane_stimulus_current(self):
        try:
            return self._model.get_symbol_by_ontology_term(self._OXMETA, self._STIMULUS_CURRENT)
        except KeyError:
            self._logger.debug(self._model.name + ' has no membrane_stimulus_current')
            return None

    def _get__membrane_stimulus_current_units(self):
        if self._membrane_stimulus_current is not None:
            return self._model.units.summarise_units(self._membrane_stimulus_current)
        else:
            return None

    def _get_membrane_capacitance(self):
        if self._membrane_stimulus_current is not None:
            # add membrane_capacitance if the model has it
            try:
                membrane_capacitance = self._model.get_symbol_by_ontology_term(self._OXMETA, "membrane_capacitance")
                return self._model.get_equations_for([membrane_capacitance])[-1]
            except KeyError:
                return None

    def _get_stimulus_currents(self):
        # Store the stimulus current
        default_stimulus = dict()
        # Get stimulus current units
        # Get remaining stimulus current variables If they have metadata use that as key, ortherwise use the name
        # Exclude _membrane_stimulus_current itself so we can treat it seperately
        for eq in self._model.get_equations_for([self._membrane_stimulus_current]):
            if eq.lhs != self._membrane_stimulus_current:
                ontology_terms = self._model.get_ontology_terms_by_symbol(eq.lhs, self._OXMETA)
                key = ontology_terms[0] if len(ontology_terms) > 0 else eq.lhs
                default_stimulus[key] = eq
        return default_stimulus

    def _get_stimulus_currents_desired_units(self):
        # Get stimulus current and set up dictionary to store in other stimulus current variables
        try:
            desired_units = getattr(self._model.units.ureg, self._STIMULUS_UNITS['membrane_stimulus_current'])
            factor = self._model.units.get_conversion_factor(desired_units, from_unit=self._membrane_stimulus_current_units)
            self._use_capacitance_i_ionic = False
            return desired_units, factor
        except errors.DimensionalityError:
            desired_units = getattr(self._model.units.ureg, self._STIMULUS_SECONDARY_UNITS['membrane_stimulus_current'])
            factor = self._model.units.get_conversion_factor(desired_units, from_unit=self._membrane_stimulus_current_units)
            self._use_capacitance_i_ionic = True
            return desired_units, factor

    def _get_ionic_derivs(self):
        # Getting the equations for const definitions for GetIIonic
        # use the RHS of the ODE defining V
        return [x for x in self._model.get_derivative_symbols() if x.args[0] == self._membrane_voltage_var]

    def _get_equations_for_ionic_vars(self):
        # figure out the currents (by finding variables with the same units as the stimulus)
        # Only equations with the same (lhs) units as the STIMULUS_CURRENT are kept.
        # Also exclude membrane_stimulus_current variable itself, and default_stimulus equations (if he model has those)
        # Manually recurse down the equation graph (bfs style) if no currents are found

        equations_for_ionic_vars = []
        equations = self._ionic_derivs
        while len(equations_for_ionic_vars) == 0:
            equations = self._model.get_equations_for(equations, recurse=False)
            equations_for_ionic_vars = [eq for eq in equations
                                        if ((self._membrane_stimulus_current is None)
                                        or (eq.lhs != self._membrane_stimulus_current
                                            and eq not in self._default_stimulus.values()))
                                        and self._model.units.summarise_units(eq.lhs) ==
                                        self._membrane_stimulus_current_units]

        # reverse topological order is more similar (though not necessarily identical) to pycml
        equations_for_ionic_vars.reverse()
        return equations_for_ionic_vars

    def _get_extended_equations_for_ionic_vars(self):
        extended_equations_for_ionic_vars = self._model.get_equations_for([ionic_var_eq.lhs for ionic_var_eq in self._equations_for_ionic_vars])
        if self._use_capacitance_i_ionic:
            extended_equations_for_ionic_vars.insert(0, self._membrane_capacitance)
        return extended_equations_for_ionic_vars

    def _get_y_derivatives(self):
        # Get derivatives for voltage state variable
        return sorted(self._model.get_derivative_symbols(),
                      key=lambda state_var: self._state_var_key_order(state_var))

    def _get_y_derivatives_voltage(self):
        # Get derivatives for voltage state variable
        return [deriv for deriv in self._y_derivatives if deriv.args[0] == self._membrane_voltage_var]

    def _get_y_derivatives_excl_voltage(self):
        # Get derivatives for state variables in the same order, excluding voltage
        return [deriv for state_var in self._state_vars for deriv in self._y_derivatives
                if deriv.args[0] == state_var and deriv.args[0] != self._membrane_voltage_var]

    def _get_derivative_eqs_voltage(self):
        # Get equations for the derivatives for Voltage
        # Sort the derivative equations to get the derivaives themselves last
        return sorted(self._model.get_equations_for(self._y_derivatives_voltage),
                      key=lambda deriv: isinstance(deriv.lhs, sp.Derivative))

    def _get_derivative_eqs_exlc_voltage(self):
        # Get equations for the derivatives excluding voltage
        # Sort the derivative equations to get the derivaives themselves last
        return sorted(self._model.get_equations_for(self._y_derivatives_excl_voltage),
                      key=lambda deriv: isinstance(deriv.lhs, sp.Derivative))

    def _get_derivative_equations(self, excl_stimulus_current=False):
        return sorted(self._model.get_equations_for(self._y_derivatives),
                      key=lambda deriv: isinstance(deriv.lhs, sp.Derivative))

    def _get_use_get_intracellular_calcium_concentration(self):
        # Check if the model has cytosolic_calcium_concentration,
        # if so we need to add GetIntracellularCalciumConcentration, otherwise leave blank
        try:
            self._model.get_symbol_by_ontology_term(self._OXMETA, "cytosolic_calcium_concentration")
            return True
        except KeyError:
            return False

    def _format_state_variables(self):
        # Filter unused state vars for ionic variables
        ionic_var_symbols = self._model.get_symbols_for(self._extended_equations_for_ionic_vars)
        y_deriv_symbols = self._model.get_symbols_for(self._derivative_equations)
        return [{'var': self._printer.doprint(var),
                 'initial_value': str(self._model.get_initial_value(var)),
                 'units': str(self._model.units.summarise_units(var)),
                 'in_ionic': var in ionic_var_symbols,
                 'in_y_deriv': var in y_deriv_symbols}
                for var in self._state_vars]

    def _format_stimulus_currents(self):
        formatted_default_stimulus = dict()
        for key, eq in self._default_stimulus.items():
            # exclude (equations for) variables that don't have annotation
            if self._model.has_ontology_annotation(eq.lhs, self._OXMETA):
                formatted_default_stimulus[key] = []
                factor = 1.0
                rhs_multiplier = ''
                units = getattr(self._model.units.ureg, self._STIMULUS_UNITS[key]
                                ) if key in self._STIMULUS_UNITS else None
                current_units = self._model.units.summarise_units(eq.lhs)
                try:
                    # Try unit conversion -- ultimately this should be sorted in cellmlmanip?
                    if units is not None and current_units != units:
                        factor = self._model.units.get_conversion_factor(units, from_unit=current_units)
                except errors.DimensionalityError:
                    # This is likely the amplitude
                    try:
                        secondary_units =\
                            getattr(self._model.units.ureg,
                                    self._STIMULUS_SECONDARY_UNITS[key]
                                    ) if key in self._STIMULUS_SECONDARY_UNITS else None
                        if secondary_units is not None and current_units != secondary_units:
                            factor = self._model.units.get_conversion_factor(secondary_units, from_unit=current_units)
                            # Just so we can get the correct comment in the output
                            units = secondary_units
                            rhs_multiplier = \
                                self._STIMULUS_RHS_MULTIPLIER[key] if key in self._STIMULUS_RHS_MULTIPLIER else None
                    except errors.DimensionalityError:
                        tertiary_units =\
                            getattr(self._model.units.ureg,
                                    self._STIMULUS_TERTIARY_UNITS[key]
                                    ) if key in self._STIMULUS_SECONDARY_UNITS else None
                        if tertiary_units is not None and current_units != secondary_units \
                                and self._membrane_capacitance is not None:
                            dividend_factor = self._model.units.get_conversion_factor(tertiary_units, from_unit=current_units)

                            devisor_key = 'membrane_capacitance'
                            divisor_units = \
                                getattr(self._model.units.ureg, self._STIMULUS_UNITS[devisor_key]
                                        ) if devisor_key in self._STIMULUS_UNITS else None
                            divisor_eq = self._membrane_capacitance
                            divisor_current_units = self._model.units.summarise_units(divisor_eq.lhs)
                            divisor_factor = \
                                self._model.units.get_conversion_factor(divisor_units, from_unit=divisor_current_units)

                            factor = dividend_factor / divisor_factor
                            # Just so we can get the correct comment in the output

                            # update the equation by deviding rhs by devisor
                            eq = sp.Eq(eq.lhs, eq.rhs / divisor_eq.lhs)
                            rhs_multiplier = \
                                self._STIMULUS_RHS_MULTIPLIER[key] if key in self._STIMULUS_RHS_MULTIPLIER else None
                            formatted_default_stimulus[key].append({'lhs': self._printer.doprint(divisor_eq.lhs),
                                                                    'rhs': self._printer.doprint(divisor_eq.rhs),
                                                                    'units': str(divisor_current_units)})
                formatted_default_stimulus[key].append({'lhs': self._var_chaste_interface_printer.doprint(eq.lhs),
                                                        'rhs': self._printer.doprint(factor * eq.rhs) + rhs_multiplier,
                                                        'units': str(units if units is not None else current_units)
                                                        })
        return formatted_default_stimulus

    def _format_equations_for_ionic_vars(self):
        return [{'var': self._printer.doprint(eq.lhs),
                 'units': str(self._model.units.summarise_units(eq.lhs)),
                 'conversion_factor':
                     self._model.units.get_conversion_factor(self._desired_ionic_current_units, from_unit=self._model.units.summarise_units(eq.lhs))}
                for eq in self._equations_for_ionic_vars]

    def _format_extended_equations_for_ionic_vars(self):
        # Format the state ionic variables
        formated_extended_equations_for_ionic_vars = [{'lhs': self._printer.doprint(eq.lhs), 'rhs': self._printer.doprint(eq.rhs),
                 'units': self._model.units.summarise_units(eq.lhs)} for eq in self._extended_equations_for_ionic_vars]

        ionic_rhs = '((' if self._use_capacitance_i_ionic else ''
        for i in range(len(self._formatted_equations_for_ionic_vars)):
            if i !=0:
                ionic_rhs += ' + '
            if self._formatted_equations_for_ionic_vars[i]['conversion_factor'] != 1.0:
                ionic_rhs += str(self._formatted_equations_for_ionic_vars[i]['conversion_factor']) + ' * '
            ionic_rhs += self._formatted_equations_for_ionic_vars[i]['var']
        if self._use_capacitance_i_ionic:
            ionic_rhs += ') / '
            current_units = self._model.units.summarise_units(self._membrane_capacitance.lhs)
            try:
                units =  getattr(self._model.units.ureg, self._STIMULUS_UNITS['membrane_capacitance'])
                factor = self._model.units.get_conversion_factor(units, from_unit=current_units)
            except errors.DimensionalityError:
                try:
                    units =  getattr(self._model.units.ureg, self._STIMULUS_SECONDARY_UNITS['membrane_capacitance'])
                    factor = self._model.units.get_conversion_factor(units, from_unit=current_units)
                except errors.DimensionalityError:
                    units =  getattr(self._model.units.ureg, self._STIMULUS_TERTIARY_UNITS['membrane_capacitance'])
                    factor = self._model.units.get_conversion_factor(units, from_unit=current_units)
            if factor != 1.0:
                ionic_rhs += '(' + str(factor) + ' * '
            ionic_rhs += self._printer.doprint(self._membrane_capacitance.lhs)
            if factor != 1.0:
                ionic_rhs += ')'
            ionic_rhs += ')'
            ionic_rhs = str(sp.simplify(ionic_rhs))  # simplify
            ionic_rhs += ' * HeartConfig::Instance()->GetCapacitance()'
        formated_extended_equations_for_ionic_vars.append({'lhs': self._var_chaste_interface_printer.doprint(sp.sympify('_i_ionic')), 'rhs': ionic_rhs,
                                                           'units': 'uA_per_cm2'})
        return formated_extended_equations_for_ionic_vars

    def _format_y_derivatives(self):
        # Format y_derivatives for writing to chaste output
        return [self._var_chaste_interface_printer.doprint(deriv) for deriv in self._y_derivatives]

    def _get_desired_units_for_deriv(self, term):
        current_units = self._model.units.summarise_units(term)
        # Time in ms
        units = self._model.units.summarise_units(term)
        if term == self._model.get_free_variable_symbol():
            units = self._model.units.ureg.millisecond
        # calcium in millimolar (cytosolic_calcium_concentration)
        elif term == self._cytosolic_calcium_concentration_var:
            units = self._model.units.ureg.millimolar
        # voltage in mV
        elif term == self._membrane_voltage_var:
            units = self._model.units.ureg.millivolt
        return units

    def _format_derivative_equations(self):
        # exclude ionic currents
        equations = []
        d_eqs = [eq for eq in self._derivative_equations
                 if eq not in self._default_stimulus.values()]

        subs_dict = {eq.lhs: eq.rhs for eq in d_eqs}
        stimulus_sign = ''
        # loop through equations backwards as derivatives are last
        for i in range(len(d_eqs) - 1, - 1, - 1):
            is_voltage = False
            factor = 1.0
            units = self._model.units.summarise_units(d_eqs[i].lhs)
            if isinstance(d_eqs[i].lhs, sp.Derivative):
                # This is dV/dt
                # Assign temporary values to variables in order to check the stimulus sign.
                # This will process defining expressions in a breadth first search until the stimulus
                # current is found.  Each variable that doesn't have its definitions processed will
                # be given a value as follows:
                # - stimulus current = 1
                # - other currents = 0
                # - other variables = 1
                # The stimulus current is then negated from the sign expected by Chaste if evaluating
                # dV/dt gives a positive value.
                if d_eqs[i].lhs.args[0] == self._membrane_voltage_var:
                    is_voltage = True
                    for s in d_eqs[i].rhs.free_symbols:
                        if self._model.units.dimensionally_equivalent(self._membrane_stimulus_current, s):
                            subs_dict[s] = 0  # other currents = 0
                        else:
                            subs_dict[s] = 1  # other variables = 1
                    subs_dict[self._membrane_stimulus_current] = 1  # stimulus current = 1
                    if d_eqs[i].rhs.subs(subs_dict) > 0.0:
                        stimulus_sign = '-'
                # Convert voltage to mV, time to mS and calcium to millimolar
                dividend_unit = self._get_desired_units_for_deriv(d_eqs[i].lhs.args[0])
                divisor_unit = self._get_desired_units_for_deriv(d_eqs[i].lhs.args[1][0])
                units = dividend_unit / divisor_unit
                factor = self._model.units.get_conversion_factor(units, from_unit=self._model.units.summarise_units(d_eqs[i].lhs))
            if d_eqs[i].lhs == self._membrane_stimulus_current:
                d_eqs[i] = sp.Eq(d_eqs[i].lhs, 1 / self._ionic_current_factor *
                                 sp.sympify(stimulus_sign +
                                            'GetIntracellularAreaStimulus(_chaste_interface__environment__time)'))

            # Format the equation and put it at the front of the result list to keep order (we're looping backwards)
            equations.insert(0, {'lhs': d_eqs[i].lhs,
                                 'factor': factor,
                                 'rhs': d_eqs[i].rhs,
                                 'units': units,
                                 'in_membrane_voltage': d_eqs[i] not in self._derivative_eqs_exlc_voltage,
                                 'is_voltage': is_voltage})
                                 
        for i in range(len(equations)):
            if equations[i]['factor']  != 1.0:
                for j in range(i+1, len(equations)):
                    equations[j]['rhs'] = equations[j]['rhs'].subs({equations[i]['lhs']: (1/equations[i]['factor'] * equations[i]['lhs'])})
            equations[i]['rhs'] = self._printer.doprint(equations[i]['factor'] * equations[i]['rhs'])
            equations[i]['lhs'] = self._printer.doprint(equations[i]['lhs'])

        return equations

    def _format_system_info(self):
        self._free_variable = {'name': self._name_printer.doprint(self._model.get_free_variable_symbol()),
                               'units': self._model.units.summarise_units(self._model.get_free_variable_symbol()),
                               'system_name': self._model.name}
        self._ode_system_information = \
            [{'name': self._model.get_ontology_terms_by_symbol(var, self._OXMETA)[0]
              if self._model.has_ontology_annotation(var, self._OXMETA) else self._name_printer.doprint(var),
              'initial_value': str(self._model.get_initial_value(var)),
              'units': str(self._model.units.summarise_units(var))}
             for var in self._state_vars]

    # function used to order state variables in the same way as pycml does (for easy comparison)
    def _state_var_key_order(self, var):
        if isinstance(var, sp.Derivative):
            var = var.args[0]
        if var == self._membrane_voltage_var:
            return self._MEMBRANE_VOLTAGE_INDEX
        elif var == self._cytosolic_calcium_concentration_var:
            return self._CYTOSOLIC_CALCIUM_CONCENTRATION_INDEX
        else:
            return self._MEMBRANE_VOLTAGE_INDEX + self._CYTOSOLIC_CALCIUM_CONCENTRATION_INDEX + 1


class NormalChasteModel(ChasteModel):
    def __init__(self, model, model_name_for_filename, class_name):
        super().__init__(model, model_name_for_filename, class_name)

    def write_chaste_code(self, output_path):
        # Get full OS path to output models to and create it if it doesn't exist
        output_path = os.path.join(output_path)
        try:
            os.makedirs(output_path)
        except FileExistsError:
            pass

        hhp_file_path = os.path.join(output_path, self._model_name_for_filename + ".hpp")
        cpp_file_path = os.path.join(output_path, self._model_name_for_filename + ".cpp")

        # Generate hpp for model
        template = cg.load_template('chaste', 'normal_model.hpp')
        with open(hhp_file_path, 'w') as f:
            f.write(template.render({
                'model_name_from_file': self._model_name_for_filename,
                'class_name': self._class_name,
                'generation_date': time.strftime('%Y-%m-%d %H:%M:%S'),
                'default_stimulus_equations': self._formatted_default_stimulus,
                'use_get_intracellular_calcium_concentration': self._use_get_intracellular_calcium_concentration,
            }))

        # Generate cpp for model
        template = cg.load_template('chaste', 'normal_model.cpp')
        with open(cpp_file_path, 'w') as f:
            f.write(template.render({
                'model_name_from_file': self._model_name_for_filename,
                'class_name': self._class_name,
                'generation_date': time.strftime('%Y-%m-%d %H:%M:%S'),
                'default_stimulus_equations': self._formatted_default_stimulus,
                'use_get_intracellular_calcium_concentration': self._use_get_intracellular_calcium_concentration,
                'membrane_voltage_index': self._MEMBRANE_VOLTAGE_INDEX,
                'cytosolic_calcium_concentration_index': self._CYTOSOLIC_CALCIUM_CONCENTRATION_INDEX,
                'state_vars': self._formatted_state_vars,
                'ionic_interface_vars': self._formatted_equations_for_ionic_vars,
                'ionic_vars': self._formatted_extended_equations_for_ionic_vars,
                'y_derivative_equations': self._formatted_derivative_eqs,
                'y_derivatives': self._formatted_y_derivatives,
                'use_capacitance_i_ionic': self._use_capacitance_i_ionic,
                'free_variable': self._free_variable,
                'ode_system_information': self._ode_system_information
            }))


class OptChasteModel(ChasteModel):
    def __init__(self, model, model_name_for_filename, class_name):
        super().__init__(model, model_name_for_filename, class_name)

    def write_chaste_code(self, output_path):
        raise NotImplementedError("TODO Not yet implemented!")


class Analytic_jChasteModel(ChasteModel):
    def __init__(self, model, model_name_for_filename, class_name):
        super().__init__(model, model_name_for_filename, class_name)

    def write_chaste_code(self, output_path):
        raise NotImplementedError("TODO Not yet implemented!")


class Numerical_jChasteModel(ChasteModel):
    def __init__(self, model, model_name_for_filename, class_name):
        super().__init__(model, model_name_for_filename, class_name)

    def write_chaste_code(self, output_path):
        raise NotImplementedError("TODO Not yet implemented!")


class BEOptChasteModel(ChasteModel):
    def __init__(self, model, model_name_for_filename, class_name):
        super().__init__(model, model_name_for_filename, class_name)

    def write_chaste_code(self, output_path):
        raise NotImplementedError("TODO Not yet implemented!")
