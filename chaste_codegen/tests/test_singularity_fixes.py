import os

import pytest
from cellmlmanip.model import Quantity, Variable
from sympy import Piecewise, exp, log

from chaste_codegen import DATA_DIR, load_model_with_conversions
from chaste_codegen._math_functions import exp_
from chaste_codegen._singularity_fixes import fix_singularity_equations, new_expr
from chaste_codegen.model_with_conversions import get_equations_for


def to_quant(val):
    return Quantity(val, 'dimensionless')


V = Variable(name='V', units='millivolt')
Z = to_quant(6.2)
U = to_quant(2) * V + to_quant(5.0)
SP = (-(log(to_quant(6.2)) + to_quant(5.0)) / to_quant(2))


@pytest.fixture(scope='session')
def expr1():
    return (Z * V - Z * SP) / (exp_(U) * -Z + to_quant(1.0))


@pytest.fixture(scope='session')
def expr2():
    return (Z * V - Z * SP) / (exp_(U) * Z - to_quant(1.0))


def test_no_singularity():
    expr = 25.0 / (exp_(U) * -Z + to_quant(1.0))
    assert str(new_expr(expr, V)) == '(False, ' + str(expr) + ')'


def test_new_expr1(expr1):
    assert str(new_expr(expr1, V)) == ('(True, Piecewise(((-_-3.4122746960255230 + _V)*(-(_-3.4122746960255230*_6.2 - '
                                       '_6.2*(-_5 - log(_6.2))/_2)/(_1 - _6.2*exp_(_-3.4122746960255230*_2 + _5)) + (_'
                                       '-3.4122745960255229*_6.2 - _6.2*(-_5 - log(_6.2))/_2)/(_1 - _6.2*exp_(_-3.4122'
                                       '745960255229*_2 + _5)))/(_-3.4122745960255229 - _-3.4122746960255230) + (_-3.4'
                                       '122746960255230*_6.2 - _6.2*(-_5 - log(_6.2))/_2)/(_1 - _6.2*exp_(_-3.41227469'
                                       '60255230*_2 + _5)), Abs(_-3.4122746460255229 - _V) < Abs(_-3.4122745960255229/'
                                       '2 - _-3.4122746960255230/2)), ((_6.2*_V - _6.2*(-_5 - log(_6.2))/_2)/(_1 - _6.'
                                       '2*exp_(_2*_V + _5)), True)))')
    assert str(new_expr(expr1, V, U_offset=1e-5)) == ('(True, Piecewise(((-_-3.4122796460255230 + _V)*(-(_-3.412279646'
                                                      '0255230*_6.2 - _6.2*(-_5 - log(_6.2))/_2)/(_1 - _6.2*exp_(_-3.4'
                                                      '122796460255230*_2 + _5)) + (_-3.4122696460255229*_6.2 - _6.2*('
                                                      '-_5 - log(_6.2))/_2)/(_1 - _6.2*exp_(_-3.4122696460255229*_2 + '
                                                      '_5)))/(_-3.4122696460255229 - _-3.4122796460255230) + (_-3.4122'
                                                      '796460255230*_6.2 - _6.2*(-_5 - log(_6.2))/_2)/(_1 - _6.2*exp_('
                                                      '_-3.4122796460255230*_2 + _5)), Abs(_-3.4122746460255229 - _V) '
                                                      '< Abs(_-3.4122696460255229/2 - _-3.4122796460255230/2)), ((_6.2'
                                                      '*_V - _6.2*(-_5 - log(_6.2))/_2)/(_1 - _6.2*exp_(_2*_V + _5)), '
                                                      'True)))')
    assert str(new_expr(expr1, V, exp_function=exp)) == ('(False, (_6.2*_V - _6.2*(-_5 - log(_6.2))/_2)/(_1 - _6.2*exp_'
                                                         '(_2*_V + _5)))')
    expr = expr1.replace(exp_, exp)
    assert str(new_expr(expr, V, exp_function=exp)) == ('(True, Piecewise(((-_-3.4122746960255230 + _V)*(-(_-3.4122746'
                                                        '960255230*_6.2 - _6.2*(-_5 - log(_6.2))/_2)/(_1 - _6.2*exp(_-'
                                                        '3.4122746960255230*_2 + _5)) + (_-3.4122745960255229*_6.2 - _'
                                                        '6.2*(-_5 - log(_6.2))/_2)/(_1 - _6.2*exp(_-3.4122745960255229'
                                                        '*_2 + _5)))/(_-3.4122745960255229 - _-3.4122746960255230) + ('
                                                        '_-3.4122746960255230*_6.2 - _6.2*(-_5 - log(_6.2))/_2)/(_1 - '
                                                        '_6.2*exp(_-3.4122746960255230*_2 + _5)), Abs(_-3.412274646025'
                                                        '5229 - _V) < Abs(_-3.4122745960255229/2 - _-3.412274696025523'
                                                        '0/2)), ((_6.2*_V - _6.2*(-_5 - log(_6.2))/_2)/(_1 - _6.2*exp('
                                                        '_2*_V + _5)), True)))')


def test_new_expr2(expr2):
    assert str(new_expr(expr2, V)) == ('(True, Piecewise(((-_-3.4122746960255230 + _V)*(-(_-3.4122746960255230*_6.2 - '
                                       '_6.2*(-_5 - log(_6.2))/_2)/(-_1 + _6.2*exp_(_-3.4122746960255230*_2 + _5)) + ('
                                       '_-3.4122745960255229*_6.2 - _6.2*(-_5 - log(_6.2))/_2)/(-_1 + _6.2*exp_(_-3.41'
                                       '22745960255229*_2 + _5)))/(_-3.4122745960255229 - _-3.4122746960255230) + (_-3'
                                       '.4122746960255230*_6.2 - _6.2*(-_5 - log(_6.2))/_2)/(-_1 + _6.2*exp_(_-3.41227'
                                       '46960255230*_2 + _5)), Abs(_-3.4122746460255229 - _V) < Abs(_-3.41227459602552'
                                       '29/2 - _-3.4122746960255230/2)), ((_6.2*_V - _6.2*(-_5 - log(_6.2))/_2)/(-_1 +'
                                       ' _6.2*exp_(_2*_V + _5)), True)))')


def test_new_expr3(expr1):
    assert str(new_expr(1 / expr1, V)) == ('(True, Piecewise(((-_-3.4122746960255230 + _V)*((_1 - _6.2*exp_(_-3.412274'
                                           '5960255229*_2 + _5))/(_-3.4122745960255229*_6.2 - _6.2*(-_5 - log(_6.2))/_'
                                           '2) - (_1 - _6.2*exp_(_-3.4122746960255230*_2 + _5))/(_-3.4122746960255230*'
                                           '_6.2 - _6.2*(-_5 - log(_6.2))/_2))/(_-3.4122745960255229 - _-3.41227469602'
                                           '55230) + (_1 - _6.2*exp_(_-3.4122746960255230*_2 + _5))/(_-3.4122746960255'
                                           '230*_6.2 - _6.2*(-_5 - log(_6.2))/_2), Abs(_-3.4122746460255229 - _V) < Ab'
                                           's(_-3.4122745960255229/2 - _-3.4122746960255230/2)), ((_1 - _6.2*exp_(_2*_'
                                           'V + _5))/(_6.2*_V - _6.2*(-_5 - log(_6.2))/_2), True)))')


def test_new_expr4(expr2):
    assert str(new_expr(1 / expr2, V)) == ('(True, Piecewise(((-_-3.4122746960255230 + _V)*((-_1 + _6.2*exp_(_-3.41227'
                                           '45960255229*_2 + _5))/(_-3.4122745960255229*_6.2 - _6.2*(-_5 - log(_6.2))/'
                                           '_2) - (-_1 + _6.2*exp_(_-3.4122746960255230*_2 + _5))/(_-3.412274696025523'
                                           '0*_6.2 - _6.2*(-_5 - log(_6.2))/_2))/(_-3.4122745960255229 - _-3.412274696'
                                           '0255230) + (-_1 + _6.2*exp_(_-3.4122746960255230*_2 + _5))/(_-3.4122746960'
                                           '255230*_6.2 - _6.2*(-_5 - log(_6.2))/_2), Abs(_-3.4122746460255229 - _V) <'
                                           ' Abs(_-3.4122745960255229/2 - _-3.4122746960255230/2)), ((-_1 + _6.2*exp_('
                                           '_2*_V + _5))/(_6.2*_V - _6.2*(-_5 - log(_6.2))/_2), True)))')


def test_new_expr5(expr1):  # Try with numbers in place of Quantity Dummies
    expr = expr1.xreplace({v: float(str(v)) for v in expr1.atoms(Quantity)})
    print(new_expr(expr, V))
    assert str(new_expr(expr, V)) == ('(True, Piecewise(((-_-3.41227469602552 + _V)*(-(6.2*_-3.41227469602552 + 21.156'
                                      '1028053582)/(1.0 - 6.2*exp_(2.0*_-3.41227469602552 + 5.0)) + (6.2*_-3.412274596'
                                      '02552 + 21.1561028053582)/(1.0 - 6.2*exp_(2.0*_-3.41227459602552 + 5.0)))/(_-3.'
                                      '41227459602552 - _-3.41227469602552) + (6.2*_-3.41227469602552 + 21.15610280535'
                                      '82)/(1.0 - 6.2*exp_(2.0*_-3.41227469602552 + 5.0)), Abs(_-3.41227464602552 - _V'
                                      ') < Abs(_-3.41227459602552/2 - _-3.41227469602552/2)), ((6.2*_V + 21.1561028053'
                                      '582)/(1.0 - 6.2*exp_(2.0*_V + 5.0)), True)))')


def test_fix_singularity_equations():
    # Using a fixture would make other tests fail since we're modifying the equations
    model = load_model_with_conversions(os.path.join(DATA_DIR, 'tests', 'cellml', 'FaberRudy2000.cellml'),
                                        fix_singularities=False)
    assert len(model.derivative_equations) == 206

    fix_singularity_equations(model, model.membrane_voltage_var, model.modifiable_parameters)
    deqs = get_equations_for(model, model.y_derivatives)

    assert len(deqs) == 201
    eqs_not_in_fixed = [eq.lhs for eq in model.derivative_equations if eq.lhs not in [e.lhs for e in deqs]]
    assert str((eqs_not_in_fixed)) == \
        ('[_L_type_Ca_channel$P_Ca, _L_type_Ca_channel$P_K, _L_type_Ca_channel$P_Na, _L_type_Ca_channel$gamma_Cai, '
         '_L_type_Ca_channel$gamma_Cao]'), str(eqs_not_in_fixed)

    new_eqs = ([eq for eq in deqs if str(eq) not in [str(e) for e in model.derivative_equations]])
    new_eqs_lhs = [eq.lhs for eq in new_eqs]
    assert str(new_eqs_lhs) == ('[_L_type_Ca_channel$I_CaCa, _L_type_Ca_channel$I_CaK, _L_type_Ca_channel$I_CaNa, '
                                '_rapid_delayed_rectifier_potassium_current_xr_gate$tau_xr, '
                                '_slow_delayed_rectifier_potassium_current_xs1_gate$tau_xs1, '
                                '_slow_delayed_rectifier_potassium_current_xs2_gate$tau_xs2]'), str(new_eqs_lhs)

    eq_without_original_piecewsies = [eq for eq in deqs if str(eq.lhs) not in (str(eq.lhs)
                                      for eq in model.derivative_equations if eq.rhs.has(Piecewise))]

    expected_piecewise_lhs = set({'L_type_Ca_channel$I_CaCa',
                                  'L_type_Ca_channel$I_CaK',
                                  'L_type_Ca_channel$I_CaNa',
                                  'rapid_delayed_rectifier_potassium_current_xr_gate$tau_xr',
                                  'slow_delayed_rectifier_potassium_current_xs1_gate$tau_xs1',
                                  'slow_delayed_rectifier_potassium_current_xs2_gate$tau_xs2'})

    # New piecewsies exactly match expected ones
    assert all([eq.rhs.has(Piecewise) == (str(eq.lhs) in expected_piecewise_lhs)
                for eq in eq_without_original_piecewsies])


def test_fix_singularity_equations3():
    # Using a fixture would make other tests fail since we're modifying the equations
    model = load_model_with_conversions(os.path.join(DATA_DIR, 'tests', 'cellml', 'bondarenko_model_2004_apex.cellml'),
                                        fix_singularities=False)
    assert len(model.derivative_equations) == 180

    fix_singularity_equations(model, model.membrane_voltage_var, model.modifiable_parameters)
    deqs = get_equations_for(model, model.y_derivatives)
    assert len(deqs) == 180

    print([old.lhs for old, new in zip(model.derivative_equations, deqs) if str(old.rhs) != str(new.rhs)])

    assert all([str(old.lhs) == str(new.lhs) and
                str(old.lhs) == 'slow_delayed_rectifier_potassium_current$alpha_n' and
                not old.rhs.has(Piecewise) and new.rhs.has(Piecewise)
                for old, new in zip(model.derivative_equations, deqs) if str(old.rhs) != str(new.rhs)])