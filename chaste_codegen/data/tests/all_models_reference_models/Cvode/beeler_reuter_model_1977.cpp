#ifdef CHASTE_CVODE
//! @file
//!
//! This source file was generated from CellML by chaste_codegen version (version omitted as unimportant)
//!
//! Model: beeler_reuter_model_1977
//!
//! Processed by chaste_codegen: https://github.com/ModellingWebLab/chaste-codegen
//!     (translator: chaste_codegen, model type: NumericCvode)
//! on (date omitted as unimportant)
//!
//! <autogenerated>

#include "beeler_reuter_model_1977.hpp"
#include <cmath>
#include <cassert>
#include <memory>
#include "Exception.hpp"
#include "OdeSystemInformation.hpp"
#include "RegularStimulus.hpp"
#include "HeartConfig.hpp"
#include "IsNan.hpp"
#include "MathsCustomFunctions.hpp"


    boost::shared_ptr<RegularStimulus> Cellbeeler_reuter_model_1977FromCellMLCvode::UseCellMLDefaultStimulus()
    {
        // Use the default stimulus specified by CellML metadata
        const double var_chaste_interface__stimulus_protocol__IstimAmplitude_converted = 50.000000000000007; // uA_per_cm2
        const double var_chaste_interface__stimulus_protocol__IstimPeriod = 1000.0; // ms
        const double var_chaste_interface__stimulus_protocol__IstimPulseDuration = 1.0; // ms
        const double var_chaste_interface__stimulus_protocol__IstimStart = 10.0; // ms
        boost::shared_ptr<RegularStimulus> p_cellml_stim(new RegularStimulus(
                -fabs(var_chaste_interface__stimulus_protocol__IstimAmplitude_converted),
                var_chaste_interface__stimulus_protocol__IstimPulseDuration,
                var_chaste_interface__stimulus_protocol__IstimPeriod,
                var_chaste_interface__stimulus_protocol__IstimStart
                ));
        mpIntracellularStimulus = p_cellml_stim;
        return p_cellml_stim;
    }

    double Cellbeeler_reuter_model_1977FromCellMLCvode::GetIntracellularCalciumConcentration()
    {
        return NV_Ith_S(mStateVariables, 1);
    }
    
    Cellbeeler_reuter_model_1977FromCellMLCvode::Cellbeeler_reuter_model_1977FromCellMLCvode(boost::shared_ptr<AbstractIvpOdeSolver> pOdeSolver /* unused; should be empty */, boost::shared_ptr<AbstractStimulusFunction> pIntracellularStimulus)
        : AbstractCvodeCell(
                pOdeSolver,
                8,
                0,
                pIntracellularStimulus)
    {
        // Time units: millisecond
        //
        this->mpSystemInfo = OdeSystemInformation<Cellbeeler_reuter_model_1977FromCellMLCvode>::Instance();
        Init();

        // We have a default stimulus specified in the CellML file metadata
        this->mHasDefaultStimulusFromCellML = true;
        
    }

    Cellbeeler_reuter_model_1977FromCellMLCvode::~Cellbeeler_reuter_model_1977FromCellMLCvode()
    {
    }

    
    double Cellbeeler_reuter_model_1977FromCellMLCvode::GetIIonic(const std::vector<double>* pStateVariables)
    {
        // For state variable interpolation (SVI) we read in interpolated state variables,
        // otherwise for ionic current interpolation (ICI) we use the state variables of this model (node).
        N_Vector rY;
        bool made_new_cvode_vector = false;
        if (!pStateVariables)
        {
            rY = rGetStateVariables();
        }
        else
        {
            made_new_cvode_vector = true;
            rY = MakeNVector(*pStateVariables);
        }
        double var_chaste_interface__membrane__V = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : NV_Ith_S(rY, 0));
        // Units: mV; Initial value: -84.624
        double var_chaste_interface__slow_inward_current__Cai = NV_Ith_S(rY, 1);
        // Units: concentration_units; Initial value: 0.0001
        double var_chaste_interface__sodium_current_m_gate__m = NV_Ith_S(rY, 2);
        // Units: dimensionless; Initial value: 0.011
        double var_chaste_interface__sodium_current_h_gate__h = NV_Ith_S(rY, 3);
        // Units: dimensionless; Initial value: 0.988
        double var_chaste_interface__sodium_current_j_gate__j = NV_Ith_S(rY, 4);
        // Units: dimensionless; Initial value: 0.975
        double var_chaste_interface__slow_inward_current_d_gate__d = NV_Ith_S(rY, 5);
        // Units: dimensionless; Initial value: 0.003
        double var_chaste_interface__slow_inward_current_f_gate__f = NV_Ith_S(rY, 6);
        // Units: dimensionless; Initial value: 0.994
        double var_chaste_interface__time_dependent_outward_current_x1_gate__x1 = NV_Ith_S(rY, 7);
        // Units: dimensionless; Initial value: 0.0001
        
        const double var_slow_inward_current__E_s = 7.6990712032745758 - 13.028700000000001 * log(var_chaste_interface__slow_inward_current__Cai); // mV
        const double var_slow_inward_current__g_s = 0.00089999999999999998; // mS_per_mm2
        const double var_slow_inward_current__i_s = (-var_slow_inward_current__E_s + var_chaste_interface__membrane__V) * var_slow_inward_current__g_s * var_chaste_interface__slow_inward_current_d_gate__d * var_chaste_interface__slow_inward_current_f_gate__f; // uA_per_mm2
        const double var_sodium_current__E_Na = 50.0; // mV
        const double var_sodium_current__g_Na = 0.040000000000000001; // mS_per_mm2
        const double var_sodium_current__g_Nac = 3.0000000000000001e-5; // mS_per_mm2
        const double var_sodium_current__i_Na = (-var_sodium_current__E_Na + var_chaste_interface__membrane__V) * (pow(var_chaste_interface__sodium_current_m_gate__m, 3) * var_sodium_current__g_Na * var_chaste_interface__sodium_current_h_gate__h * var_chaste_interface__sodium_current_j_gate__j + var_sodium_current__g_Nac); // uA_per_mm2
        const double var_time_dependent_outward_current__i_x1 = 0.0080000000000000002 * (-1.0 + exp(3.0800000000000001 + 0.040000000000000001 * var_chaste_interface__membrane__V)) * var_chaste_interface__time_dependent_outward_current_x1_gate__x1 / exp(1.4000000000000001 + 0.040000000000000001 * var_chaste_interface__membrane__V); // uA_per_mm2
        const double var_time_independent_outward_current__i_K1 = 0.014 * (-1.0 + exp(3.3999999999999999 + 0.040000000000000001 * var_chaste_interface__membrane__V)) / (exp(2.1200000000000001 + 0.040000000000000001 * var_chaste_interface__membrane__V) + exp(4.2400000000000002 + 0.080000000000000002 * var_chaste_interface__membrane__V)) + 0.0007000000000000001 * (23.0 + var_chaste_interface__membrane__V) / (1.0 - exp(-0.92000000000000004 - 0.040000000000000001 * var_chaste_interface__membrane__V)); // uA_per_mm2
        const double var_chaste_interface__i_ionic = 100.00000000000001 * var_slow_inward_current__i_s + 100.00000000000001 * var_sodium_current__i_Na + 100.00000000000001 * var_time_dependent_outward_current__i_x1 + 100.00000000000001 * var_time_independent_outward_current__i_K1; // uA_per_cm2

        const double i_ionic = var_chaste_interface__i_ionic;
        if (made_new_cvode_vector)
        {
            DeleteVector(rY);
        }
        EXCEPT_IF_NOT(!std::isnan(i_ionic));
        return i_ionic;
    }

    void Cellbeeler_reuter_model_1977FromCellMLCvode::EvaluateYDerivatives(double var_chaste_interface__environment__time, const N_Vector rY, N_Vector rDY)
    {
        // Inputs:
        // Time units: millisecond
        double var_chaste_interface__membrane__V = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : NV_Ith_S(rY, 0));
        // Units: mV; Initial value: -84.624
        double var_chaste_interface__slow_inward_current__Cai = NV_Ith_S(rY, 1);
        // Units: concentration_units; Initial value: 0.0001
        double var_chaste_interface__sodium_current_m_gate__m = NV_Ith_S(rY, 2);
        // Units: dimensionless; Initial value: 0.011
        double var_chaste_interface__sodium_current_h_gate__h = NV_Ith_S(rY, 3);
        // Units: dimensionless; Initial value: 0.988
        double var_chaste_interface__sodium_current_j_gate__j = NV_Ith_S(rY, 4);
        // Units: dimensionless; Initial value: 0.975
        double var_chaste_interface__slow_inward_current_d_gate__d = NV_Ith_S(rY, 5);
        // Units: dimensionless; Initial value: 0.003
        double var_chaste_interface__slow_inward_current_f_gate__f = NV_Ith_S(rY, 6);
        // Units: dimensionless; Initial value: 0.994
        double var_chaste_interface__time_dependent_outward_current_x1_gate__x1 = NV_Ith_S(rY, 7);
        // Units: dimensionless; Initial value: 0.0001

        // Mathematics
        double d_dt_chaste_interface_var_membrane__V;
        const double var_slow_inward_current__E_s = 7.6990712032745758 - 13.028700000000001 * log(var_chaste_interface__slow_inward_current__Cai); // mV
        const double var_slow_inward_current__g_s = 0.00089999999999999998; // mS_per_mm2
        const double var_slow_inward_current_d_gate__alpha_d = 0.095000000000000001 * exp(0.050000000000000003 - 0.01 * var_chaste_interface__membrane__V) / (1.0 + exp(0.35997120230381568 - 0.071994240460763137 * var_chaste_interface__membrane__V)); // per_ms
        const double var_slow_inward_current_d_gate__beta_d = 0.070000000000000007 * exp(-0.74576271186440679 - 0.016949152542372881 * var_chaste_interface__membrane__V) / (1.0 + exp(2.2000000000000002 + 0.050000000000000003 * var_chaste_interface__membrane__V)); // per_ms
        const double d_dt_chaste_interface_var_slow_inward_current_d_gate__d = (1.0 - var_chaste_interface__slow_inward_current_d_gate__d) * var_slow_inward_current_d_gate__alpha_d - var_slow_inward_current_d_gate__beta_d * var_chaste_interface__slow_inward_current_d_gate__d; // 1 / ms
        const double var_slow_inward_current_f_gate__alpha_f = 0.012 * exp(-0.224 - 0.0080000000000000002 * var_chaste_interface__membrane__V) / (1.0 + exp(4.197901049475262 + 0.14992503748125938 * var_chaste_interface__membrane__V)); // per_ms
        const double var_slow_inward_current_f_gate__beta_f = 0.0064999999999999997 * exp(-0.59999999999999998 - 0.02 * var_chaste_interface__membrane__V) / (1.0 + exp(-6.0 - 0.20000000000000001 * var_chaste_interface__membrane__V)); // per_ms
        const double d_dt_chaste_interface_var_slow_inward_current_f_gate__f = (1.0 - var_chaste_interface__slow_inward_current_f_gate__f) * var_slow_inward_current_f_gate__alpha_f - var_slow_inward_current_f_gate__beta_f * var_chaste_interface__slow_inward_current_f_gate__f; // 1 / ms
        const double var_slow_inward_current__i_s = (-var_slow_inward_current__E_s + var_chaste_interface__membrane__V) * var_slow_inward_current__g_s * var_chaste_interface__slow_inward_current_d_gate__d * var_chaste_interface__slow_inward_current_f_gate__f; // uA_per_mm2
        const double d_dt_chaste_interface_var_slow_inward_current__Cai = 7.0000000000000007e-6 - 0.070000000000000007 * var_chaste_interface__slow_inward_current__Cai - 0.01 * var_slow_inward_current__i_s; // concentration_units / ms
        const double var_sodium_current_h_gate__alpha_h = 0.126 * exp(-19.25 - 0.25 * var_chaste_interface__membrane__V); // per_ms
        const double var_sodium_current_h_gate__beta_h = 1.7 / (1.0 + exp(-1.845 - 0.082000000000000003 * var_chaste_interface__membrane__V)); // per_ms
        const double d_dt_chaste_interface_var_sodium_current_h_gate__h = (1.0 - var_chaste_interface__sodium_current_h_gate__h) * var_sodium_current_h_gate__alpha_h - var_sodium_current_h_gate__beta_h * var_chaste_interface__sodium_current_h_gate__h; // 1 / ms
        const double var_sodium_current_j_gate__alpha_j = 0.055 * exp(-19.5 - 0.25 * var_chaste_interface__membrane__V) / (1.0 + exp(-15.600000000000001 - 0.20000000000000001 * var_chaste_interface__membrane__V)); // per_ms
        const double var_sodium_current_j_gate__beta_j = 0.29999999999999999 / (1.0 + exp(-3.2000000000000002 - 0.10000000000000001 * var_chaste_interface__membrane__V)); // per_ms
        const double d_dt_chaste_interface_var_sodium_current_j_gate__j = (1.0 - var_chaste_interface__sodium_current_j_gate__j) * var_sodium_current_j_gate__alpha_j - var_sodium_current_j_gate__beta_j * var_chaste_interface__sodium_current_j_gate__j; // 1 / ms
        const double var_sodium_current_m_gate__alpha_m = -(47.0 + var_chaste_interface__membrane__V) / (-1.0 + exp(-4.7000000000000002 - 0.10000000000000001 * var_chaste_interface__membrane__V)); // per_ms
        const double var_sodium_current_m_gate__beta_m = 40.0 * exp(-4.032 - 0.056000000000000001 * var_chaste_interface__membrane__V); // per_ms
        const double d_dt_chaste_interface_var_sodium_current_m_gate__m = (1.0 - var_chaste_interface__sodium_current_m_gate__m) * var_sodium_current_m_gate__alpha_m - var_sodium_current_m_gate__beta_m * var_chaste_interface__sodium_current_m_gate__m; // 1 / ms
        const double var_time_dependent_outward_current_x1_gate__alpha_x1 = 0.00050000000000000001 * exp(4.1322314049586781 + 0.082644628099173556 * var_chaste_interface__membrane__V) / (1.0 + exp(2.8571428571428572 + 0.057142857142857141 * var_chaste_interface__membrane__V)); // per_ms
        const double var_time_dependent_outward_current_x1_gate__beta_x1 = 0.0012999999999999999 * exp(-1.1997600479904018 - 0.059988002399520089 * var_chaste_interface__membrane__V) / (1.0 + exp(-0.80000000000000004 - 0.040000000000000001 * var_chaste_interface__membrane__V)); // per_ms
        const double d_dt_chaste_interface_var_time_dependent_outward_current_x1_gate__x1 = (1.0 - var_chaste_interface__time_dependent_outward_current_x1_gate__x1) * var_time_dependent_outward_current_x1_gate__alpha_x1 - var_time_dependent_outward_current_x1_gate__beta_x1 * var_chaste_interface__time_dependent_outward_current_x1_gate__x1; // 1 / ms

        if (mSetVoltageDerivativeToZero)
        {
            d_dt_chaste_interface_var_membrane__V = 0.0;
        }
        else
        {
            const double var_membrane__C = 0.01; // uF_per_mm2
            const double var_sodium_current__E_Na = 50.0; // mV
            const double var_sodium_current__g_Na = 0.040000000000000001; // mS_per_mm2
            const double var_sodium_current__g_Nac = 3.0000000000000001e-5; // mS_per_mm2
            const double var_sodium_current__i_Na = (-var_sodium_current__E_Na + var_chaste_interface__membrane__V) * (pow(var_chaste_interface__sodium_current_m_gate__m, 3) * var_sodium_current__g_Na * var_chaste_interface__sodium_current_h_gate__h * var_chaste_interface__sodium_current_j_gate__j + var_sodium_current__g_Nac); // uA_per_mm2
            const double var_stimulus_protocol__Istim_converted = -GetIntracellularAreaStimulus(var_chaste_interface__environment__time); // uA_per_cm2
            const double var_stimulus_protocol__Istim = 0.0099999999999999985 * var_stimulus_protocol__Istim_converted; // uA_per_mm2
            const double var_time_dependent_outward_current__i_x1 = 0.0080000000000000002 * (-1.0 + exp(3.0800000000000001 + 0.040000000000000001 * var_chaste_interface__membrane__V)) * var_chaste_interface__time_dependent_outward_current_x1_gate__x1 / exp(1.4000000000000001 + 0.040000000000000001 * var_chaste_interface__membrane__V); // uA_per_mm2
            const double var_time_independent_outward_current__i_K1 = 0.014 * (-1.0 + exp(3.3999999999999999 + 0.040000000000000001 * var_chaste_interface__membrane__V)) / (exp(2.1200000000000001 + 0.040000000000000001 * var_chaste_interface__membrane__V) + exp(4.2400000000000002 + 0.080000000000000002 * var_chaste_interface__membrane__V)) + 0.0007000000000000001 * (23.0 + var_chaste_interface__membrane__V) / (1.0 - exp(-0.92000000000000004 - 0.040000000000000001 * var_chaste_interface__membrane__V)); // uA_per_mm2
            d_dt_chaste_interface_var_membrane__V = (-var_slow_inward_current__i_s - var_sodium_current__i_Na - var_time_dependent_outward_current__i_x1 - var_time_independent_outward_current__i_K1 + var_stimulus_protocol__Istim) / var_membrane__C; // mV / ms
        }
        
        NV_Ith_S(rDY,0) = d_dt_chaste_interface_var_membrane__V;
        NV_Ith_S(rDY,1) = d_dt_chaste_interface_var_slow_inward_current__Cai;
        NV_Ith_S(rDY,2) = d_dt_chaste_interface_var_sodium_current_m_gate__m;
        NV_Ith_S(rDY,3) = d_dt_chaste_interface_var_sodium_current_h_gate__h;
        NV_Ith_S(rDY,4) = d_dt_chaste_interface_var_sodium_current_j_gate__j;
        NV_Ith_S(rDY,5) = d_dt_chaste_interface_var_slow_inward_current_d_gate__d;
        NV_Ith_S(rDY,6) = d_dt_chaste_interface_var_slow_inward_current_f_gate__f;
        NV_Ith_S(rDY,7) = d_dt_chaste_interface_var_time_dependent_outward_current_x1_gate__x1;
    }

    N_Vector Cellbeeler_reuter_model_1977FromCellMLCvode::ComputeDerivedQuantities(double var_chaste_interface__environment__time, const N_Vector & rY)
    {
        // Inputs:
        // Time units: millisecond
        
        // Mathematics
        const double var_stimulus_protocol__Istim_converted = -GetIntracellularAreaStimulus(var_chaste_interface__environment__time); // uA_per_cm2

        N_Vector dqs = N_VNew_Serial(2);
        NV_Ith_S(dqs, 0) = var_chaste_interface__environment__time;
        NV_Ith_S(dqs, 1) = var_stimulus_protocol__Istim_converted;
        return dqs;
    }

template<>
void OdeSystemInformation<Cellbeeler_reuter_model_1977FromCellMLCvode>::Initialise(void)
{
    this->mSystemName = "beeler_reuter_model_1977";
    this->mFreeVariableName = "environment__time";
    this->mFreeVariableUnits = "ms";

    // NV_Ith_S(rY, 0):
    this->mVariableNames.push_back("membrane_voltage");
    this->mVariableUnits.push_back("mV");
    this->mInitialConditions.push_back(-84.624);

    // NV_Ith_S(rY, 1):
    this->mVariableNames.push_back("cytosolic_calcium_concentration");
    this->mVariableUnits.push_back("concentration_units");
    this->mInitialConditions.push_back(0.0001);

    // NV_Ith_S(rY, 2):
    this->mVariableNames.push_back("sodium_current_m_gate__m");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.011);

    // NV_Ith_S(rY, 3):
    this->mVariableNames.push_back("sodium_current_h_gate__h");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.988);

    // NV_Ith_S(rY, 4):
    this->mVariableNames.push_back("sodium_current_j_gate__j");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.975);

    // NV_Ith_S(rY, 5):
    this->mVariableNames.push_back("slow_inward_current_d_gate__d");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.003);

    // NV_Ith_S(rY, 6):
    this->mVariableNames.push_back("slow_inward_current_f_gate__f");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.994);

    // NV_Ith_S(rY, 7):
    this->mVariableNames.push_back("time_dependent_outward_current_x1_gate__x1");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.0001);

    // Derived Quantity index [0]:
    this->mDerivedQuantityNames.push_back("environment__time");
    this->mDerivedQuantityUnits.push_back("ms");

    // Derived Quantity index [1]:
    this->mDerivedQuantityNames.push_back("membrane_stimulus_current");
    this->mDerivedQuantityUnits.push_back("uA_per_cm2");

    this->mInitialised = true;
}

// Serialization for Boost >= 1.36
#include "SerializationExportWrapperForCpp.hpp"
CHASTE_CLASS_EXPORT(Cellbeeler_reuter_model_1977FromCellMLCvode)

#endif // CHASTE_CVODE
