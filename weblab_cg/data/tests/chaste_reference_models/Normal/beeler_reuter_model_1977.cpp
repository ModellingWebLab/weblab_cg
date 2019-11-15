//! @file
//! 
//! This source file was generated from CellML.
//! 
//! Model: beeler_reuter_model_1977
//! 
//! Processed by webalab_cg - CellML Tools in Python: https://github.com/ModellingWebLab/weblab-cg
//!     (translators: , webalab_cg: , options: normal)
//! on 2019-11-15 15:20:29
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

    boost::shared_ptr<RegularStimulus> Dynamicbeeler_reuter_model_1977FromCellML::UseCellMLDefaultStimulus()
    {
        // Use the default stimulus specified by CellML metadata
        const double var_chaste_interface__stimulus_protocol__IstimAmplitude = 50.0; // uA_per_cm2
        const double var_chaste_interface__stimulus_protocol__IstimPeriod = 1000.0; // millisecond
        const double var_chaste_interface__stimulus_protocol__IstimPulseDuration = 1.0; // millisecond
        const double var_chaste_interface__stimulus_protocol__IstimStart = 10.0; // millisecond
        boost::shared_ptr<RegularStimulus> p_cellml_stim(new RegularStimulus(
                -fabs(var_chaste_interface__stimulus_protocol__IstimAmplitude),
                var_chaste_interface__stimulus_protocol__IstimPulseDuration,
                var_chaste_interface__stimulus_protocol__IstimPeriod,
                var_chaste_interface__stimulus_protocol__IstimStart
                ));
        mpIntracellularStimulus = p_cellml_stim;
        return p_cellml_stim;
    }
    
    double Dynamicbeeler_reuter_model_1977FromCellML::GetIntracellularCalciumConcentration()
    {
        return mStateVariables[1];
    }
    
    Dynamicbeeler_reuter_model_1977FromCellML::Dynamicbeeler_reuter_model_1977FromCellML(boost::shared_ptr<AbstractIvpOdeSolver> pSolver, boost::shared_ptr<AbstractStimulusFunction> pIntracellularStimulus)
        : AbstractCardiacCell(
                pSolver,
                8,
                0,
                pIntracellularStimulus)
    {
        // Time units: millisecond
        // 
        this->mpSystemInfo = OdeSystemInformation<Dynamicbeeler_reuter_model_1977FromCellML>::Instance();
        Init();
        
        // We have a default stimulus specified in the CellML file metadata
        this->mHasDefaultStimulusFromCellML = true;
    }
    
    Dynamicbeeler_reuter_model_1977FromCellML::~Dynamicbeeler_reuter_model_1977FromCellML()
    {
    }
    
    double Dynamicbeeler_reuter_model_1977FromCellML::GetIIonic(const std::vector<double>* pStateVariables)
    {
        // For state variable interpolation (SVI) we read in interpolated state variables,
        // otherwise for ionic current interpolation (ICI) we use the state variables of this model (node).
        if (!pStateVariables) pStateVariables = &rGetStateVariables();
        const std::vector<double>& rY = *pStateVariables;
        double var_chaste_interface__membrane__V = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : rY[0]);
        // Units: mV; Initial value: -84.624
        double var_chaste_interface__slow_inward_current__Cai = rY[1];
        // Units: concentration_units; Initial value: 0.0001
        double var_chaste_interface__sodium_current_m_gate__m = rY[2];
        // Units: dimensionless; Initial value: 0.011
        double var_chaste_interface__sodium_current_h_gate__h = rY[3];
        // Units: dimensionless; Initial value: 0.988
        double var_chaste_interface__sodium_current_j_gate__j = rY[4];
        // Units: dimensionless; Initial value: 0.975
        double var_chaste_interface__slow_inward_current_d_gate__d = rY[5];
        // Units: dimensionless; Initial value: 0.003
        double var_chaste_interface__slow_inward_current_f_gate__f = rY[6];
        // Units: dimensionless; Initial value: 0.994
        double var_chaste_interface__time_dependent_outward_current_x1_gate__x1 = rY[7];
        // Units: dimensionless; Initial value: 0.0001
        
        const double var_slow_inward_current__E_s = -82.3 - 13.0287 * log(0.001 * var_chaste_interface__slow_inward_current__Cai); // mV
        const double var_slow_inward_current__g_s = 0.0009; // mS_per_mm2
        const double var_slow_inward_current__i_s = (-var_slow_inward_current__E_s + var_chaste_interface__membrane__V) * var_slow_inward_current__g_s * var_chaste_interface__slow_inward_current_d_gate__d * var_chaste_interface__slow_inward_current_f_gate__f; // uA_per_mm2
        const double var_sodium_current__E_Na = 50.0; // mV
        const double var_sodium_current__g_Na = 0.04; // mS_per_mm2
        const double var_sodium_current__g_Nac = 3e-05; // mS_per_mm2
        const double var_sodium_current__i_Na = (-var_sodium_current__E_Na + var_chaste_interface__membrane__V) * (pow(var_chaste_interface__sodium_current_m_gate__m, 3.0) * var_sodium_current__g_Na * var_chaste_interface__sodium_current_h_gate__h * var_chaste_interface__sodium_current_j_gate__j + var_sodium_current__g_Nac); // uA_per_mm2
        const double var_time_dependent_outward_current__i_x1 = 0.0019727757115328517 * (-1.0 + 21.75840239619708 * exp(0.04 * var_chaste_interface__membrane__V)) * var_chaste_interface__time_dependent_outward_current_x1_gate__x1 * exp(-0.04 * var_chaste_interface__membrane__V); // uA_per_mm2
        const double var_time_independent_outward_current__i_K1 = 0.0007000000000000001 * (23.0 + var_chaste_interface__membrane__V) / (1.0 - 0.39851904108451414 * exp(-0.04 * var_chaste_interface__membrane__V)) + 0.014 * (-1.0 + 29.96410004739701 * exp(0.04 * var_chaste_interface__membrane__V)) / (8.331137487687693 * exp(0.04 * var_chaste_interface__membrane__V) + 69.4078518387552 * exp(0.08 * var_chaste_interface__membrane__V)); // uA_per_mm2
        const double var_chaste_interface__i_ionic = 100.0 * var_time_independent_outward_current__i_K1 + 100.0 * var_time_dependent_outward_current__i_x1 + 100.0 * var_sodium_current__i_Na + 100.0 * var_slow_inward_current__i_s; // uA_per_cm2
        
        const double i_ionic = var_chaste_interface__i_ionic;
        EXCEPT_IF_NOT(!std::isnan(i_ionic));
        return i_ionic;
    }
    
    void Dynamicbeeler_reuter_model_1977FromCellML::EvaluateYDerivatives(double var_chaste_interface__environment__time, const std::vector<double>& rY, std::vector<double>& rDY)
    {
        // Inputs:
        // Time units: millisecond
        double var_chaste_interface__membrane__V = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : rY[0]);
        // Units: mV; Initial value: -84.624
        double var_chaste_interface__slow_inward_current__Cai = rY[1];
        // Units: concentration_units; Initial value: 0.0001
        double var_chaste_interface__sodium_current_m_gate__m = rY[2];
        // Units: dimensionless; Initial value: 0.011
        double var_chaste_interface__sodium_current_h_gate__h = rY[3];
        // Units: dimensionless; Initial value: 0.988
        double var_chaste_interface__sodium_current_j_gate__j = rY[4];
        // Units: dimensionless; Initial value: 0.975
        double var_chaste_interface__slow_inward_current_d_gate__d = rY[5];
        // Units: dimensionless; Initial value: 0.003
        double var_chaste_interface__slow_inward_current_f_gate__f = rY[6];
        // Units: dimensionless; Initial value: 0.994
        double var_chaste_interface__time_dependent_outward_current_x1_gate__x1 = rY[7];
        // Units: dimensionless; Initial value: 0.0001
        
        // Mathematics
        double d_dt_chaste_interface__membrane__V;
        const double var_slow_inward_current__E_s = -82.3 - 13.0287 * log(0.001 * var_chaste_interface__slow_inward_current__Cai); // mV
        const double var_slow_inward_current__g_s = 0.0009; // mS_per_mm2
        const double var_slow_inward_current_d_gate__alpha_d = 0.09987075415572229 * exp(-0.01 * var_chaste_interface__membrane__V) / (1.0 + 1.4332881385696572 * exp(-0.07199424046076314 * var_chaste_interface__membrane__V)); // per_ms
        const double var_slow_inward_current_d_gate__beta_d = 0.03320606467536786 * exp(-0.01694915254237288 * var_chaste_interface__membrane__V) / (1.0 + 9.025013499434122 * exp(0.05 * var_chaste_interface__membrane__V)); // per_ms
        const double var_slow_inward_current_f_gate__alpha_f = 0.009591781612432381 * exp(-0.008 * var_chaste_interface__membrane__V) / (1.0 + 66.5465065250986 * exp(0.14992503748125938 * var_chaste_interface__membrane__V)); // per_ms
        const double var_slow_inward_current_f_gate__beta_f = 0.0035672756346111713 * exp(-0.02 * var_chaste_interface__membrane__V) / (1.0 + 0.0024787521766663585 * exp(-0.2 * var_chaste_interface__membrane__V)); // per_ms
        const double var_slow_inward_current__i_s = (-var_slow_inward_current__E_s + var_chaste_interface__membrane__V) * var_slow_inward_current__g_s * var_chaste_interface__slow_inward_current_d_gate__d * var_chaste_interface__slow_inward_current_f_gate__f; // uA_per_mm2
        const double var_sodium_current_h_gate__alpha_h = 5.497962438709065e-10 * exp(-0.25 * var_chaste_interface__membrane__V); // per_ms
        const double var_sodium_current_h_gate__beta_h = 1.7 / (1.0 + 0.1580253208896478 * exp(-0.082 * var_chaste_interface__membrane__V)); // per_ms
        const double var_sodium_current_j_gate__alpha_j = 1.8690473007222892e-10 * exp(-0.25 * var_chaste_interface__membrane__V) / (1.0 + 1.6788275299956603e-07 * exp(-0.2 * var_chaste_interface__membrane__V)); // per_ms
        const double var_sodium_current_j_gate__beta_j = 0.3 / (1.0 + 0.040762203978366204 * exp(-0.1 * var_chaste_interface__membrane__V)); // per_ms
        const double var_sodium_current_m_gate__alpha_m = -1.0 * (47.0 + var_chaste_interface__membrane__V) / (-1.0 + 0.009095277101695816 * exp(-0.1 * var_chaste_interface__membrane__V)); // per_ms
        const double var_sodium_current_m_gate__beta_m = 0.7095526727489909 * exp(-0.056 * var_chaste_interface__membrane__V); // per_ms
        const double var_time_dependent_outward_current_x1_gate__alpha_x1 = 0.031158410986342627 * exp(0.08264462809917356 * var_chaste_interface__membrane__V) / (1.0 + 17.41170806332765 * exp(0.05714285714285714 * var_chaste_interface__membrane__V)); // per_ms
        const double var_time_dependent_outward_current_x1_gate__beta_x1 = 0.0003916464405623223 * exp(-0.05998800239952009 * var_chaste_interface__membrane__V) / (1.0 + 0.44932896411722156 * exp(-0.04 * var_chaste_interface__membrane__V)); // per_ms
        const double d_dt_chaste_interface__slow_inward_current_d_gate__d = (1.0 - var_chaste_interface__slow_inward_current_d_gate__d) * var_slow_inward_current_d_gate__alpha_d - var_slow_inward_current_d_gate__beta_d * var_chaste_interface__slow_inward_current_d_gate__d; // 1 / millisecond
        const double d_dt_chaste_interface__slow_inward_current_f_gate__f = (1.0 - var_chaste_interface__slow_inward_current_f_gate__f) * var_slow_inward_current_f_gate__alpha_f - var_slow_inward_current_f_gate__beta_f * var_chaste_interface__slow_inward_current_f_gate__f; // 1 / millisecond
        const double d_dt_chaste_interface__slow_inward_current__Cai = 6.999999999999999e-06 - 0.009999999999999998 * var_slow_inward_current__i_s - 0.06999999999999999 * var_chaste_interface__slow_inward_current__Cai; // millimolar / millisecond
        const double d_dt_chaste_interface__sodium_current_h_gate__h = (1.0 - var_chaste_interface__sodium_current_h_gate__h) * var_sodium_current_h_gate__alpha_h - var_sodium_current_h_gate__beta_h * var_chaste_interface__sodium_current_h_gate__h; // 1 / millisecond
        const double d_dt_chaste_interface__sodium_current_j_gate__j = (1.0 - var_chaste_interface__sodium_current_j_gate__j) * var_sodium_current_j_gate__alpha_j - var_sodium_current_j_gate__beta_j * var_chaste_interface__sodium_current_j_gate__j; // 1 / millisecond
        const double d_dt_chaste_interface__sodium_current_m_gate__m = (1.0 - var_chaste_interface__sodium_current_m_gate__m) * var_sodium_current_m_gate__alpha_m - var_sodium_current_m_gate__beta_m * var_chaste_interface__sodium_current_m_gate__m; // 1 / millisecond
        const double d_dt_chaste_interface__time_dependent_outward_current_x1_gate__x1 = (1.0 - var_chaste_interface__time_dependent_outward_current_x1_gate__x1) * var_time_dependent_outward_current_x1_gate__alpha_x1 - var_time_dependent_outward_current_x1_gate__beta_x1 * var_chaste_interface__time_dependent_outward_current_x1_gate__x1; // 1 / millisecond
        
        if (mSetVoltageDerivativeToZero)
        {
            d_dt_chaste_interface__membrane__V = 0.0;
        }
        else
        {
            const double var_membrane__C = 0.01; // uF_per_mm2
            const double var_sodium_current__E_Na = 50.0; // mV
            const double var_sodium_current__g_Na = 0.04; // mS_per_mm2
            const double var_sodium_current__g_Nac = 3e-05; // mS_per_mm2
            const double var_sodium_current__i_Na = (-var_sodium_current__E_Na + var_chaste_interface__membrane__V) * (pow(var_chaste_interface__sodium_current_m_gate__m, 3.0) * var_sodium_current__g_Na * var_chaste_interface__sodium_current_h_gate__h * var_chaste_interface__sodium_current_j_gate__j + var_sodium_current__g_Nac); // uA_per_mm2
            const double var_stimulus_protocol__Istim = -0.01 * GetIntracellularAreaStimulus(var_chaste_interface__environment__time); // uA_per_mm2
            const double var_time_dependent_outward_current__i_x1 = 0.0019727757115328517 * (-1.0 + 21.75840239619708 * exp(0.04 * var_chaste_interface__membrane__V)) * var_chaste_interface__time_dependent_outward_current_x1_gate__x1 * exp(-0.04 * var_chaste_interface__membrane__V); // uA_per_mm2
            const double var_time_independent_outward_current__i_K1 = 0.0007000000000000001 * (23.0 + var_chaste_interface__membrane__V) / (1.0 - 0.39851904108451414 * exp(-0.04 * var_chaste_interface__membrane__V)) + 0.014 * (-1.0 + 29.96410004739701 * exp(0.04 * var_chaste_interface__membrane__V)) / (8.331137487687693 * exp(0.04 * var_chaste_interface__membrane__V) + 69.4078518387552 * exp(0.08 * var_chaste_interface__membrane__V)); // uA_per_mm2
            d_dt_chaste_interface__membrane__V = (-var_slow_inward_current__i_s - var_sodium_current__i_Na - var_time_dependent_outward_current__i_x1 - var_time_independent_outward_current__i_K1 + var_stimulus_protocol__Istim) / var_membrane__C; // millivolt / millisecond
        }
        
        rDY[0] = d_dt_chaste_interface__membrane__V;
        rDY[1] = d_dt_chaste_interface__slow_inward_current__Cai;
        rDY[2] = d_dt_chaste_interface__sodium_current_m_gate__m;
        rDY[3] = d_dt_chaste_interface__sodium_current_h_gate__h;
        rDY[4] = d_dt_chaste_interface__sodium_current_j_gate__j;
        rDY[5] = d_dt_chaste_interface__slow_inward_current_d_gate__d;
        rDY[6] = d_dt_chaste_interface__slow_inward_current_f_gate__f;
        rDY[7] = d_dt_chaste_interface__time_dependent_outward_current_x1_gate__x1;
    }
    
template<>
void OdeSystemInformation<Dynamicbeeler_reuter_model_1977FromCellML>::Initialise(void)
{
    this->mSystemName = "beeler_reuter_model_1977";
    this->mFreeVariableName = "environment__time";
    this->mFreeVariableUnits = "millisecond";
    
    // rY[0]:
    this->mVariableNames.push_back("membrane_voltage");
    this->mVariableUnits.push_back("millivolt");
    this->mInitialConditions.push_back(-84.624);
    
    // rY[1]:
    this->mVariableNames.push_back("cytosolic_calcium_concentration");
    this->mVariableUnits.push_back("millimolar");
    this->mInitialConditions.push_back(0.0001);
    
    // rY[2]:
    this->mVariableNames.push_back("sodium_current_m_gate__m");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.011);
    
    // rY[3]:
    this->mVariableNames.push_back("sodium_current_h_gate__h");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.988);
    
    // rY[4]:
    this->mVariableNames.push_back("sodium_current_j_gate__j");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.975);
    
    // rY[5]:
    this->mVariableNames.push_back("slow_inward_current_d_gate__d");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.003);
    
    // rY[6]:
    this->mVariableNames.push_back("slow_inward_current_f_gate__f");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.994);
    
    // rY[7]:
    this->mVariableNames.push_back("time_dependent_outward_current_x1_gate__x1");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.0001);
    
    
    this->mInitialised = true;
}


// Serialization for Boost >= 1.36
#include "SerializationExportWrapperForCpp.hpp"
CHASTE_CLASS_EXPORT(Dynamicbeeler_reuter_model_1977FromCellML)
extern "C"
{
    AbstractCardiacCellInterface* MakeCardiacCell(
            boost::shared_ptr<AbstractIvpOdeSolver> pSolver,
            boost::shared_ptr<AbstractStimulusFunction> pStimulus)
    {
        return new Dynamicbeeler_reuter_model_1977FromCellML(pSolver, pStimulus);
    }
    
}
