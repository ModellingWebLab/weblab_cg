//! @file
//!
//! This source file was generated from CellML by chaste_codegen version (version omitted as unimportant)
//!
//! Model: sachse_model_2007
//!
//! Processed by chaste_codegen: https://github.com/ModellingWebLab/chaste-codegen
//!     (translator: chaste_codegen, model type: BackwardEuler)
//! on (date omitted as unimportant)
//!
//! <autogenerated>

#include "sachse_moreno_abildskov_2008_b.hpp"
#include <cmath>
#include <cassert>
#include <memory>
#include "Exception.hpp"
#include "OdeSystemInformation.hpp"
#include "RegularStimulus.hpp"
#include "HeartConfig.hpp"
#include "IsNan.hpp"
#include "MathsCustomFunctions.hpp"
#include "CardiacNewtonSolver.hpp"

class Cellsachse_moreno_abildskov_2008_bFromCellMLBackwardEuler_LookupTables : public AbstractLookupTableCollection
{
public:
    static Cellsachse_moreno_abildskov_2008_bFromCellMLBackwardEuler_LookupTables* Instance()
    {
        if (mpInstance.get() == NULL)
        {
            mpInstance.reset(new Cellsachse_moreno_abildskov_2008_bFromCellMLBackwardEuler_LookupTables);
        }
        return mpInstance.get();
    }

    void FreeMemory()
    {

        mNeedsRegeneration.assign(mNeedsRegeneration.size(), true);
    }

    // Row lookup methods
    // using linear-interpolation



    ~Cellsachse_moreno_abildskov_2008_bFromCellMLBackwardEuler_LookupTables()
    {

    }

protected:
    Cellsachse_moreno_abildskov_2008_bFromCellMLBackwardEuler_LookupTables(const Cellsachse_moreno_abildskov_2008_bFromCellMLBackwardEuler_LookupTables&);
    Cellsachse_moreno_abildskov_2008_bFromCellMLBackwardEuler_LookupTables& operator= (const Cellsachse_moreno_abildskov_2008_bFromCellMLBackwardEuler_LookupTables&);
    Cellsachse_moreno_abildskov_2008_bFromCellMLBackwardEuler_LookupTables()
    {
        assert(mpInstance.get() == NULL);
        mKeyingVariableNames.resize(0);
        mNumberOfTables.resize(0);
        mTableMins.resize(0);
        mTableSteps.resize(0);
        mTableStepInverses.resize(0);
        mTableMaxs.resize(0);
        mNeedsRegeneration.resize(0);

        Cellsachse_moreno_abildskov_2008_bFromCellMLBackwardEuler_LookupTables::RegenerateTables();
    }

    void RegenerateTables()
    {
        AbstractLookupTableCollection::EventHandler::BeginEvent(AbstractLookupTableCollection::EventHandler::GENERATE_TABLES);

        AbstractLookupTableCollection::EventHandler::EndEvent(AbstractLookupTableCollection::EventHandler::GENERATE_TABLES);
    }

private:
    /** The single instance of the class */
    static std::shared_ptr<Cellsachse_moreno_abildskov_2008_bFromCellMLBackwardEuler_LookupTables> mpInstance;

};

std::shared_ptr<Cellsachse_moreno_abildskov_2008_bFromCellMLBackwardEuler_LookupTables> Cellsachse_moreno_abildskov_2008_bFromCellMLBackwardEuler_LookupTables::mpInstance;

    boost::shared_ptr<RegularStimulus> Cellsachse_moreno_abildskov_2008_bFromCellMLBackwardEuler::UseCellMLDefaultStimulus()
    {
        // Use the default stimulus specified by CellML metadata
        const double var_chaste_interface__I_stim__stim_duration_converted = 1.0; // millisecond
        const double var_chaste_interface__I_stim__stim_period_converted = 1000.0; // millisecond
        const double var_chaste_interface__I_stim__stim_start_converted = 100.0; // millisecond
        const double var_chaste_interface__I_stim__stim_amplitude_converted = 0.0001 * HeartConfig::Instance()->GetCapacitance() / mParameters[2]; // uA_per_cm2
        boost::shared_ptr<RegularStimulus> p_cellml_stim(new RegularStimulus(
                -fabs(var_chaste_interface__I_stim__stim_amplitude_converted),
                var_chaste_interface__I_stim__stim_duration_converted,
                var_chaste_interface__I_stim__stim_period_converted,
                var_chaste_interface__I_stim__stim_start_converted
                ));
        mpIntracellularStimulus = p_cellml_stim;
        return p_cellml_stim;
    }

    Cellsachse_moreno_abildskov_2008_bFromCellMLBackwardEuler::Cellsachse_moreno_abildskov_2008_bFromCellMLBackwardEuler(boost::shared_ptr<AbstractIvpOdeSolver> /* unused; should be empty */, boost::shared_ptr<AbstractStimulusFunction> pIntracellularStimulus)
        : AbstractBackwardEulerCardiacCell<6>(
                7,
                0,
                pIntracellularStimulus)
    {
        // Time units: millisecond
        //
        this->mpSystemInfo = OdeSystemInformation<Cellsachse_moreno_abildskov_2008_bFromCellMLBackwardEuler>::Instance();
        Init();

        // We have a default stimulus specified in the CellML file metadata
        this->mHasDefaultStimulusFromCellML = true;
        
        this->mParameters[0] = 140.0; // (var_model_parameters__Ki) [millimolar]
        this->mParameters[1] = 5.0; // (var_model_parameters__Ko) [millimolar]
        this->mParameters[2] = 4.5000000000000001e-6; // (var_membrane__Cm) [microfarad]
        this->mParameters[3] = 5.4000000000000004e-9; // (var_I_Shkr__PShkr) [microlitre_per_second]
        this->mParameters[4] = 0.001; // (var_I_Kir__GKir) [microsiemens]
        this->mParameters[5] = 6.9e-6; // (var_I_b__Gb) [microsiemens]
        this->mParameters[6] = 295.0; // (var_model_parameters__T) [kelvin]
    }

    Cellsachse_moreno_abildskov_2008_bFromCellMLBackwardEuler::~Cellsachse_moreno_abildskov_2008_bFromCellMLBackwardEuler()
    {
    }

    AbstractLookupTableCollection* Cellsachse_moreno_abildskov_2008_bFromCellMLBackwardEuler::GetLookupTableCollection()
    {
        return Cellsachse_moreno_abildskov_2008_bFromCellMLBackwardEuler_LookupTables::Instance();
    }
    
    double Cellsachse_moreno_abildskov_2008_bFromCellMLBackwardEuler::GetIIonic(const std::vector<double>* pStateVariables)
    {
        // For state variable interpolation (SVI) we read in interpolated state variables,
        // otherwise for ionic current interpolation (ICI) we use the state variables of this model (node).
        if (!pStateVariables) pStateVariables = &rGetStateVariables();
        const std::vector<double>& rY = *pStateVariables;
        double var_chaste_interface__membrane__Vm = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : rY[0]);
        // Units: millivolt; Initial value: -58.0
        double var_chaste_interface__I_Shkr__OShkr = rY[6];
        // Units: dimensionless; Initial value: 0.0
        
        const double var_I_b__I_b_converted = 0.001 * HeartConfig::Instance()->GetCapacitance() * mParameters[5] * var_chaste_interface__membrane__Vm / mParameters[2]; // uA_per_cm2
        const double var_I_Kir__EK = 0.086113989637305696 * mParameters[6] * log(mParameters[1] / mParameters[0]); // millivolt
        const double var_I_Kir__I_Kir_converted = 3.1622776601683795e-5 * sqrt(mParameters[1]) * (-var_I_Kir__EK + var_chaste_interface__membrane__Vm) * HeartConfig::Instance()->GetCapacitance() * mParameters[4] / ((0.93999999999999995 + exp(14.631768953068592 * (-var_I_Kir__EK + var_chaste_interface__membrane__Vm) / mParameters[6])) * mParameters[2]); // uA_per_cm2
        const double var_I_Shkr__I_Shkr_converted = 1120.6077015643802 * (-mParameters[1] * exp(-11.612515042117931 * var_chaste_interface__membrane__Vm / mParameters[6]) + mParameters[0]) * HeartConfig::Instance()->GetCapacitance() * var_chaste_interface__I_Shkr__OShkr * mParameters[3] * var_chaste_interface__membrane__Vm / ((1.0 - exp(-11.612515042117931 * var_chaste_interface__membrane__Vm / mParameters[6])) * mParameters[2] * mParameters[6]); // uA_per_cm2
        const double var_chaste_interface__i_ionic = var_I_Kir__I_Kir_converted + var_I_Shkr__I_Shkr_converted + var_I_b__I_b_converted; // uA_per_cm2

        const double i_ionic = var_chaste_interface__i_ionic;
        EXCEPT_IF_NOT(!std::isnan(i_ionic));
        return i_ionic;
    }

    void Cellsachse_moreno_abildskov_2008_bFromCellMLBackwardEuler::ComputeResidual(double var_chaste_interface__environment__time_converted, const double rCurrentGuess[6], double rResidual[6])
    {
        std::vector<double>& rY = rGetStateVariables();
        double var_chaste_interface__membrane__Vm = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : rY[0]);
        // Units: millivolt; Initial value: -58.0
        
        //output_nonlinear_state_assignments
        double var_chaste_interface__I_Shkr__C0Shkr = rCurrentGuess[0];
        double var_chaste_interface__I_Shkr__C1Shkr = rCurrentGuess[1];
        double var_chaste_interface__I_Shkr__C2Shkr = rCurrentGuess[2];
        double var_chaste_interface__I_Shkr__C3Shkr = rCurrentGuess[3];
        double var_chaste_interface__I_Shkr__C4Shkr = rCurrentGuess[4];
        double var_chaste_interface__I_Shkr__OShkr = rCurrentGuess[5];
        
        //output_equations
        const double d_dt_chaste_interface_var_I_Shkr__OShkr = 0.076999999999999999 * var_chaste_interface__I_Shkr__C4Shkr - 0.017999999999999999 * var_chaste_interface__I_Shkr__OShkr; // 1 / millisecond
        const double var_I_Shkr__k_v = 2.0 * exp(-17.767148014440433 * var_chaste_interface__membrane__Vm / mParameters[6]); // first_order_rate_constant
        const double var_I_Shkr__kv = 30.0 * exp(14.864019253910952 * var_chaste_interface__membrane__Vm / mParameters[6]); // first_order_rate_constant
        const double d_dt_chaste_interface_var_I_Shkr__C0Shkr = 0.001 * var_chaste_interface__I_Shkr__C1Shkr * var_I_Shkr__k_v - 0.0040000000000000001 * var_chaste_interface__I_Shkr__C0Shkr * var_I_Shkr__kv; // 1 / millisecond
        const double d_dt_chaste_interface_var_I_Shkr__C1Shkr = 0.002 * var_chaste_interface__I_Shkr__C2Shkr * var_I_Shkr__k_v + 0.0040000000000000001 * var_chaste_interface__I_Shkr__C0Shkr * var_I_Shkr__kv - 0.001 * (3.0 * var_I_Shkr__kv + var_I_Shkr__k_v) * var_chaste_interface__I_Shkr__C1Shkr; // 1 / millisecond
        const double d_dt_chaste_interface_var_I_Shkr__C2Shkr = 0.0030000000000000001 * var_chaste_interface__I_Shkr__C1Shkr * var_I_Shkr__kv + 0.0030000000000000001 * var_chaste_interface__I_Shkr__C3Shkr * var_I_Shkr__k_v - 0.001 * (2.0 * var_I_Shkr__k_v + 2.0 * var_I_Shkr__kv) * var_chaste_interface__I_Shkr__C2Shkr; // 1 / millisecond
        const double d_dt_chaste_interface_var_I_Shkr__C3Shkr = 0.002 * var_chaste_interface__I_Shkr__C2Shkr * var_I_Shkr__kv + 0.0040000000000000001 * var_chaste_interface__I_Shkr__C4Shkr * var_I_Shkr__k_v - 0.001 * (3.0 * var_I_Shkr__k_v + var_I_Shkr__kv) * var_chaste_interface__I_Shkr__C3Shkr; // 1 / millisecond
        const double d_dt_chaste_interface_var_I_Shkr__C4Shkr = 0.017999999999999999 * var_chaste_interface__I_Shkr__OShkr + 0.001 * var_chaste_interface__I_Shkr__C3Shkr * var_I_Shkr__kv - 0.001 * (77.0 + 4.0 * var_I_Shkr__k_v) * var_chaste_interface__I_Shkr__C4Shkr; // 1 / millisecond
        
        rResidual[0] = rCurrentGuess[0] - rY[1] - mDt*d_dt_chaste_interface_var_I_Shkr__C0Shkr;
        rResidual[1] = rCurrentGuess[1] - rY[2] - mDt*d_dt_chaste_interface_var_I_Shkr__C1Shkr;
        rResidual[2] = rCurrentGuess[2] - rY[3] - mDt*d_dt_chaste_interface_var_I_Shkr__C2Shkr;
        rResidual[3] = rCurrentGuess[3] - rY[4] - mDt*d_dt_chaste_interface_var_I_Shkr__C3Shkr;
        rResidual[4] = rCurrentGuess[4] - rY[5] - mDt*d_dt_chaste_interface_var_I_Shkr__C4Shkr;
        rResidual[5] = rCurrentGuess[5] - rY[6] - mDt*d_dt_chaste_interface_var_I_Shkr__OShkr;
    }

    void Cellsachse_moreno_abildskov_2008_bFromCellMLBackwardEuler::ComputeJacobian(double var_chaste_interface__environment__time_converted, const double rCurrentGuess[6], double rJacobian[6][6])
    {
        std::vector<double>& rY = rGetStateVariables();
        double var_chaste_interface__membrane__Vm = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : rY[0]);
        // Units: millivolt; Initial value: -58.0
        
        
        const double var_x0 = var_chaste_interface__membrane__Vm / mParameters[6];
        const double var_x1 = exp(14.864019253910952 * var_x0);
        const double var_x2 = 0.12 * var_x1;
        const double var_x3 = exp(-17.767148014440433 * var_x0);
        const double var_x4 = 0.002 * var_x3;
        const double var_x5 = 0.089999999999999997 * var_x1;
        const double var_x6 = 0.0040000000000000001 * var_x3;
        const double var_x7 = 0.059999999999999998 * var_x1;
        const double var_x8 = 0.0060000000000000001 * var_x3;
        const double var_x9 = 0.029999999999999999 * var_x1;
        const double var_x10 = 0.0080000000000000002 * var_x3;
        
        
        rJacobian[0][0] = 1.0 - (mDt * (-var_x2));
        rJacobian[0][1] = -(mDt * (var_x4));
        rJacobian[0][2] = 0.0;
        rJacobian[0][3] = 0.0;
        rJacobian[0][4] = 0.0;
        rJacobian[0][5] = 0.0;
        rJacobian[1][0] = -(mDt * (var_x2));
        rJacobian[1][1] = 1.0 - (mDt * (-var_x4 - var_x5));
        rJacobian[1][2] = -(mDt * (var_x6));
        rJacobian[1][3] = 0.0;
        rJacobian[1][4] = 0.0;
        rJacobian[1][5] = 0.0;
        rJacobian[2][0] = 0.0;
        rJacobian[2][1] = -(mDt * (var_x5));
        rJacobian[2][2] = 1.0 - (mDt * (-var_x6 - var_x7));
        rJacobian[2][3] = -(mDt * (var_x8));
        rJacobian[2][4] = 0.0;
        rJacobian[2][5] = 0.0;
        rJacobian[3][0] = 0.0;
        rJacobian[3][1] = 0.0;
        rJacobian[3][2] = -(mDt * (var_x7));
        rJacobian[3][3] = 1.0 - (mDt * (-var_x8 - var_x9));
        rJacobian[3][4] = -(mDt * (var_x10));
        rJacobian[3][5] = 0.0;
        rJacobian[4][0] = 0.0;
        rJacobian[4][1] = 0.0;
        rJacobian[4][2] = 0.0;
        rJacobian[4][3] = -(mDt * (var_x9));
        rJacobian[4][4] = 1.0 - (mDt * (-0.076999999999999999 - var_x10));
        rJacobian[4][5] = -(mDt * (0.017999999999999999));
        rJacobian[5][0] = 0.0;
        rJacobian[5][1] = 0.0;
        rJacobian[5][2] = 0.0;
        rJacobian[5][3] = 0.0;
        rJacobian[5][4] = -(mDt * (0.076999999999999999));
        rJacobian[5][5] = 1.0 - (mDt * (-0.017999999999999999));
    }

    void Cellsachse_moreno_abildskov_2008_bFromCellMLBackwardEuler::UpdateTransmembranePotential(double var_chaste_interface__environment__time_converted)
    {
        // Time units: millisecond
        std::vector<double>& rY = rGetStateVariables();
        double var_chaste_interface__membrane__Vm = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : rY[0]);
        // Units: millivolt; Initial value: -58.0
        double var_chaste_interface__I_Shkr__OShkr = rY[6];
        // Units: dimensionless; Initial value: 0.0
        
        const double var_I_Kir__EK = 0.086113989637305696 * mParameters[6] * log(mParameters[1] / mParameters[0]); // millivolt
        const double d_dt_chaste_interface_var_membrane__Vm = 0.001 * (-mParameters[5] * var_chaste_interface__membrane__Vm - 1000.0 * GetIntracellularAreaStimulus(var_chaste_interface__environment__time_converted) * mParameters[2] / HeartConfig::Instance()->GetCapacitance() - 0.031622776601683791 * sqrt(mParameters[1]) * (-var_I_Kir__EK + var_chaste_interface__membrane__Vm) * mParameters[4] / (0.93999999999999995 + exp(14.631768953068592 * (-var_I_Kir__EK + var_chaste_interface__membrane__Vm) / mParameters[6])) - 1120607.7015643802 * (-mParameters[1] * exp(-11.612515042117931 * var_chaste_interface__membrane__Vm / mParameters[6]) + mParameters[0]) * var_chaste_interface__I_Shkr__OShkr * mParameters[3] * var_chaste_interface__membrane__Vm / ((1.0 - exp(-11.612515042117931 * var_chaste_interface__membrane__Vm / mParameters[6])) * mParameters[6])) / mParameters[2]; // millivolt / millisecond
        
        rY[0] += mDt*d_dt_chaste_interface_var_membrane__Vm;
    }
    
    void Cellsachse_moreno_abildskov_2008_bFromCellMLBackwardEuler::ComputeOneStepExceptVoltage(double var_chaste_interface__environment__time_converted)
    {
        // Time units: millisecond
        std::vector<double>& rY = rGetStateVariables();
        
        
        
        
        double _guess[6] = {rY[1],rY[2],rY[3],rY[4],rY[5],rY[6]};
        CardiacNewtonSolver<6,Cellsachse_moreno_abildskov_2008_bFromCellMLBackwardEuler>* _p_solver = CardiacNewtonSolver<6,Cellsachse_moreno_abildskov_2008_bFromCellMLBackwardEuler>::Instance();
        _p_solver->Solve(*this, var_chaste_interface__environment__time_converted, _guess);
        rY[1] = _guess[0];
        rY[2] = _guess[1];
        rY[3] = _guess[2];
        rY[4] = _guess[3];
        rY[5] = _guess[4];
        rY[6] = _guess[5];
    }

    std::vector<double> Cellsachse_moreno_abildskov_2008_bFromCellMLBackwardEuler::ComputeDerivedQuantities(double var_chaste_interface__environment__time_converted, const std::vector<double> & rY)
    {
        // Inputs:
        // Time units: millisecond
        double var_chaste_interface__membrane__Vm = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : rY[0]);
        // Units: millivolt; Initial value: -58.0
        double var_chaste_interface__I_Shkr__OShkr = rY[6];
        // Units: dimensionless; Initial value: 0.0
        
        // Mathematics
        const double var_I_Kir__aKir = 0.93999999999999995; // dimensionless
        const double var_I_Kir__bKir = 1.26; // dimensionless
        const double var_I_b__Eb = 0; // millivolt
        const double var_I_stim__I_stim_converted = -GetIntracellularAreaStimulus(var_chaste_interface__environment__time_converted); // uA_per_cm2
        const double var_I_b__I_b = (-var_I_b__Eb + var_chaste_interface__membrane__Vm) * mParameters[5]; // nanoampere
        const double var_I_b__I_b_converted = 0.001 * HeartConfig::Instance()->GetCapacitance() * var_I_b__I_b / mParameters[2]; // uA_per_cm2
        const double var_model_parameters__F = 96500.0; // coulomb_per_mole
        const double var_model_parameters__R = 8310.0; // millijoule_per_kelvin_mole
        const double var_I_Kir__EK = var_model_parameters__R * mParameters[6] * log(mParameters[1] / mParameters[0]) / var_model_parameters__F; // millivolt
        const double var_I_Kir__OKir = 1 / (var_I_Kir__aKir + exp((-var_I_Kir__EK + var_chaste_interface__membrane__Vm) * var_I_Kir__bKir * var_model_parameters__F / (var_model_parameters__R * mParameters[6]))); // dimensionless
        const double var_I_Kir__I_Kir = 0.031622776601683791 * sqrt(mParameters[1]) * (-var_I_Kir__EK + var_chaste_interface__membrane__Vm) * mParameters[4] * var_I_Kir__OKir; // nanoampere
        const double var_I_Kir__I_Kir_converted = 0.001 * HeartConfig::Instance()->GetCapacitance() * var_I_Kir__I_Kir / mParameters[2]; // uA_per_cm2
        const double var_I_Shkr__I_Shkr = pow(var_model_parameters__F, 2) * (-mParameters[1] * exp(-var_chaste_interface__membrane__Vm * var_model_parameters__F / (var_model_parameters__R * mParameters[6])) + mParameters[0]) * var_chaste_interface__I_Shkr__OShkr * mParameters[3] * var_chaste_interface__membrane__Vm / ((1.0 - exp(-var_chaste_interface__membrane__Vm * var_model_parameters__F / (var_model_parameters__R * mParameters[6]))) * var_model_parameters__R * mParameters[6]); // nanoampere
        const double var_I_Shkr__I_Shkr_converted = 0.001 * HeartConfig::Instance()->GetCapacitance() * var_I_Shkr__I_Shkr / mParameters[2]; // uA_per_cm2

        std::vector<double> dqs(5);
        dqs[0] = var_I_Shkr__I_Shkr_converted;
        dqs[1] = var_I_Kir__I_Kir_converted;
        dqs[2] = var_I_b__I_b_converted;
        dqs[3] = var_I_stim__I_stim_converted;
        dqs[4] = var_chaste_interface__environment__time_converted;
        return dqs;
    }

template<>
void OdeSystemInformation<Cellsachse_moreno_abildskov_2008_bFromCellMLBackwardEuler>::Initialise(void)
{
    this->mSystemName = "sachse_model_2007";
    this->mFreeVariableName = "time";
    this->mFreeVariableUnits = "millisecond";

    // rY[0]:
    this->mVariableNames.push_back("membrane_voltage");
    this->mVariableUnits.push_back("millivolt");
    this->mInitialConditions.push_back(-58.0);

    // rY[1]:
    this->mVariableNames.push_back("I_Shkr__C0Shkr");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.911);

    // rY[2]:
    this->mVariableNames.push_back("I_Shkr__C1Shkr");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.0857);

    // rY[3]:
    this->mVariableNames.push_back("I_Shkr__C2Shkr");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.00302);

    // rY[4]:
    this->mVariableNames.push_back("I_Shkr__C3Shkr");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(4.74e-05);

    // rY[5]:
    this->mVariableNames.push_back("I_Shkr__C4Shkr");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(2.79e-07);

    // rY[6]:
    this->mVariableNames.push_back("I_Shkr__OShkr");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.0);

    // mParameters[0]:
    this->mParameterNames.push_back("cytosolic_potassium_concentration");
    this->mParameterUnits.push_back("millimolar");

    // mParameters[1]:
    this->mParameterNames.push_back("extracellular_potassium_concentration");
    this->mParameterUnits.push_back("millimolar");

    // mParameters[2]:
    this->mParameterNames.push_back("membrane_capacitance");
    this->mParameterUnits.push_back("microfarad");

    // mParameters[3]:
    this->mParameterNames.push_back("membrane_delayed_rectifier_potassium_current_conductance");
    this->mParameterUnits.push_back("microlitre_per_second");

    // mParameters[4]:
    this->mParameterNames.push_back("membrane_inward_rectifier_potassium_current_conductance");
    this->mParameterUnits.push_back("microsiemens");

    // mParameters[5]:
    this->mParameterNames.push_back("membrane_leakage_current_conductance");
    this->mParameterUnits.push_back("microsiemens");

    // mParameters[6]:
    this->mParameterNames.push_back("temperature");
    this->mParameterUnits.push_back("kelvin");

    // Derived Quantity index [0]:
    this->mDerivedQuantityNames.push_back("membrane_delayed_rectifier_potassium_current");
    this->mDerivedQuantityUnits.push_back("uA_per_cm2");

    // Derived Quantity index [1]:
    this->mDerivedQuantityNames.push_back("membrane_inward_rectifier_potassium_current");
    this->mDerivedQuantityUnits.push_back("uA_per_cm2");

    // Derived Quantity index [2]:
    this->mDerivedQuantityNames.push_back("membrane_leakage_current");
    this->mDerivedQuantityUnits.push_back("uA_per_cm2");

    // Derived Quantity index [3]:
    this->mDerivedQuantityNames.push_back("membrane_stimulus_current");
    this->mDerivedQuantityUnits.push_back("uA_per_cm2");

    // Derived Quantity index [4]:
    this->mDerivedQuantityNames.push_back("time");
    this->mDerivedQuantityUnits.push_back("millisecond");

    this->mInitialised = true;
}

// Serialization for Boost >= 1.36
#include "SerializationExportWrapperForCpp.hpp"
CHASTE_CLASS_EXPORT(Cellsachse_moreno_abildskov_2008_bFromCellMLBackwardEuler)

