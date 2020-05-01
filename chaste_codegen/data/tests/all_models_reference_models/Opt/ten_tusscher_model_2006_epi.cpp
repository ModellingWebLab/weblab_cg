//! @file
//!
//! This source file was generated from CellML by chaste_codegen version 0.1
//!
//! Model: tentusscher_panfilov_2006_epi
//!
//! Processed by chaste_codegen: https://github.com/ModellingWebLab/chaste-codegen
//!     (translator: chaste_codegen, model type: normal)
//! on (date omitted as unimportant)
//!
//! <autogenerated>

#include "ten_tusscher_model_2006_epi.hpp"
#include <cmath>
#include <cassert>
#include <memory>
#include "Exception.hpp"
#include "OdeSystemInformation.hpp"
#include "RegularStimulus.hpp"
#include "HeartConfig.hpp"
#include "IsNan.hpp"
#include "MathsCustomFunctions.hpp"

    boost::shared_ptr<RegularStimulus> Cellten_tusscher_model_2006_epiFromCellML::UseCellMLDefaultStimulus()
    {
        // Use the default stimulus specified by CellML metadata
        const double var_chaste_interface__membrane__i_Stim_Amplitude = -52.0 * HeartConfig::Instance()->GetCapacitance(); // picoA_per_picoF
        const double var_chaste_interface__membrane__i_Stim_Period = 1000; // millisecond
        const double var_chaste_interface__membrane__i_Stim_PulseDuration = 1.0; // millisecond
        const double var_chaste_interface__membrane__i_Stim_Start = 10; // millisecond
        boost::shared_ptr<RegularStimulus> p_cellml_stim(new RegularStimulus(
                -fabs(var_chaste_interface__membrane__i_Stim_Amplitude),
                var_chaste_interface__membrane__i_Stim_PulseDuration,
                var_chaste_interface__membrane__i_Stim_Period,
                var_chaste_interface__membrane__i_Stim_Start
                ));
        mpIntracellularStimulus = p_cellml_stim;
        return p_cellml_stim;
    }
    double Cellten_tusscher_model_2006_epiFromCellML::GetIntracellularCalciumConcentration()
    {
        return mStateVariables[1];
    }
    Cellten_tusscher_model_2006_epiFromCellML::Cellten_tusscher_model_2006_epiFromCellML(boost::shared_ptr<AbstractIvpOdeSolver> pSolver, boost::shared_ptr<AbstractStimulusFunction> pIntracellularStimulus)
        : AbstractCardiacCell(
                pSolver,
                19,
                0,
                pIntracellularStimulus)
    {
        // Time units: millisecond
        //
        this->mpSystemInfo = OdeSystemInformation<Cellten_tusscher_model_2006_epiFromCellML>::Instance();
        Init();

        // We have a default stimulus specified in the CellML file metadata
        this->mHasDefaultStimulusFromCellML = true;
        
        this->mParameters[0] = 3.9799999999999998e-5; // (var_L_type_Ca_current__g_CaL) [litre_per_farad_second]
        this->mParameters[1] = 14.837999999999999; // (var_fast_sodium_current__g_Na) [nanoS_per_picoF]
        this->mParameters[2] = 0.153; // (var_rapid_time_dependent_potassium_current__g_Kr) [nanoS_per_picoF]
        this->mParameters[3] = 0.29399999999999998; // (var_transient_outward_current__g_to) [nanoS_per_picoF]
    }

    Cellten_tusscher_model_2006_epiFromCellML::~Cellten_tusscher_model_2006_epiFromCellML()
    {
    }
    
    double Cellten_tusscher_model_2006_epiFromCellML::GetIIonic(const std::vector<double>* pStateVariables)
    {
        // For state variable interpolation (SVI) we read in interpolated state variables,
        // otherwise for ionic current interpolation (ICI) we use the state variables of this model (node).
        if (!pStateVariables) pStateVariables = &rGetStateVariables();
        const std::vector<double>& rY = *pStateVariables;
        double var_chaste_interface__membrane__V = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : rY[0]);
        // Units: millivolt; Initial value: -85.23
        double var_chaste_interface__calcium_dynamics__Ca_i = rY[1];
        // Units: millimolar; Initial value: 000126
        double var_chaste_interface__rapid_time_dependent_potassium_current_Xr1_gate__Xr1 = rY[2];
        // Units: dimensionless; Initial value: 00621
        double var_chaste_interface__rapid_time_dependent_potassium_current_Xr2_gate__Xr2 = rY[3];
        // Units: dimensionless; Initial value: 0.4712
        double var_chaste_interface__slow_time_dependent_potassium_current_Xs_gate__Xs = rY[4];
        // Units: dimensionless; Initial value: 0095
        double var_chaste_interface__fast_sodium_current_m_gate__m = rY[5];
        // Units: dimensionless; Initial value: 00172
        double var_chaste_interface__fast_sodium_current_h_gate__h = rY[6];
        // Units: dimensionless; Initial value: 0.7444
        double var_chaste_interface__fast_sodium_current_j_gate__j = rY[7];
        // Units: dimensionless; Initial value: 0.7045
        double var_chaste_interface__L_type_Ca_current_d_gate__d = rY[8];
        // Units: dimensionless; Initial value: 3.373e-05
        double var_chaste_interface__L_type_Ca_current_f_gate__f = rY[9];
        // Units: dimensionless; Initial value: 0.7888
        double var_chaste_interface__L_type_Ca_current_f2_gate__f2 = rY[10];
        // Units: dimensionless; Initial value: 0.9755
        double var_chaste_interface__L_type_Ca_current_fCass_gate__fCass = rY[11];
        // Units: dimensionless; Initial value: 0.9953
        double var_chaste_interface__transient_outward_current_s_gate__s = rY[12];
        // Units: dimensionless; Initial value: 0.999998
        double var_chaste_interface__transient_outward_current_r_gate__r = rY[13];
        // Units: dimensionless; Initial value: 2.42e-08
        double var_chaste_interface__calcium_dynamics__Ca_ss = rY[15];
        // Units: millimolar; Initial value: 00036
        double var_chaste_interface__sodium_dynamics__Na_i = rY[17];
        // Units: millimolar; Initial value: 8.604
        double var_chaste_interface__potassium_dynamics__K_i = rY[18];
        // Units: millimolar; Initial value: 136.89
        
        const double var_calcium_pump_current__i_p_Ca = 0.12379999999999999 * var_chaste_interface__calcium_dynamics__Ca_i / (00050000000000000001 + var_chaste_interface__calcium_dynamics__Ca_i); // picoA_per_picoF
        const double var_L_type_Ca_current__i_CaL = 14447.286958825251 * (-2.0 + 0.25 * var_chaste_interface__calcium_dynamics__Ca_ss * exp(-1.1230167246823641 + 074867781645490947 * var_chaste_interface__membrane__V)) * (-15.0 + var_chaste_interface__membrane__V) * mParameters[0] * var_chaste_interface__L_type_Ca_current_d_gate__d * var_chaste_interface__L_type_Ca_current_f2_gate__f2 * var_chaste_interface__L_type_Ca_current_fCass_gate__fCass * var_chaste_interface__L_type_Ca_current_f_gate__f / (-1.0 + exp(-1.1230167246823641 + 074867781645490947 * var_chaste_interface__membrane__V)); // picoA_per_picoF
        const double var_calcium_background_current__i_b_Ca = 00059199999999999997 * var_chaste_interface__membrane__V - 0079072731552699126 * log(2.0 / var_chaste_interface__calcium_dynamics__Ca_i); // picoA_per_picoF
        const double var_reversal_potentials__E_K = 26.713760659695652 * log(5.4000000000000004 / var_chaste_interface__potassium_dynamics__K_i); // millivolt
        const double var_inward_rectifier_potassium_current__i_K1 = 0.54050000000000009 * (-var_reversal_potentials__E_K + var_chaste_interface__membrane__V) / ((1.0 + exp(-12.0 + 059999999999999998 * var_chaste_interface__membrane__V - 059999999999999998 * var_reversal_potentials__E_K)) * (0.10000000000000001 / (1.0 + exp(-12.0 + 059999999999999998 * var_chaste_interface__membrane__V - 059999999999999998 * var_reversal_potentials__E_K)) + (3.0 * exp(02 + 00020000000000000001 * var_chaste_interface__membrane__V - 00020000000000000001 * var_reversal_potentials__E_K) + exp(-1.0 + 0.10000000000000001 * var_chaste_interface__membrane__V - 0.10000000000000001 * var_reversal_potentials__E_K)) / (1.0 + exp(0.5 * var_reversal_potentials__E_K - 0.5 * var_chaste_interface__membrane__V)))); // picoA_per_picoF
        const double var_potassium_pump_current__i_p_K = 0146 * (-var_reversal_potentials__E_K + var_chaste_interface__membrane__V) / (1.0 + exp(4.1806020066889626 - 0.16722408026755853 * var_chaste_interface__membrane__V)); // picoA_per_picoF
        const double var_rapid_time_dependent_potassium_current__i_Kr = 1.0 * (-var_reversal_potentials__E_K + var_chaste_interface__membrane__V) * mParameters[2] * var_chaste_interface__rapid_time_dependent_potassium_current_Xr1_gate__Xr1 * var_chaste_interface__rapid_time_dependent_potassium_current_Xr2_gate__Xr2; // picoA_per_picoF
        const double var_reversal_potentials__E_Na = 26.713760659695652 * log(140 / var_chaste_interface__sodium_dynamics__Na_i); // millivolt
        const double var_fast_sodium_current__i_Na = pow(var_chaste_interface__fast_sodium_current_m_gate__m, 3) * (-var_reversal_potentials__E_Na + var_chaste_interface__membrane__V) * mParameters[1] * var_chaste_interface__fast_sodium_current_h_gate__h * var_chaste_interface__fast_sodium_current_j_gate__j; // picoA_per_picoF
        const double var_slow_time_dependent_potassium_current__i_Ks = 0.39200000000000002 * pow(var_chaste_interface__slow_time_dependent_potassium_current_Xs_gate__Xs, 2) * (-26.713760659695652 * log(9.5999999999999996 / (029999999999999999 * var_chaste_interface__sodium_dynamics__Na_i + var_chaste_interface__potassium_dynamics__K_i)) + var_chaste_interface__membrane__V); // picoA_per_picoF
        const double var_sodium_background_current__i_b_Na = 00029 * var_chaste_interface__membrane__V - 00029 * var_reversal_potentials__E_Na; // picoA_per_picoF
        const double var_sodium_calcium_exchanger_current__i_NaCa = 8.6662202299424464e-5 * (2.0 * pow(var_chaste_interface__sodium_dynamics__Na_i, 3) * exp(013101861787960915 * var_chaste_interface__membrane__V) - 6860000 * var_chaste_interface__calcium_dynamics__Ca_i * exp(-024332029034784559 * var_chaste_interface__membrane__V)) / (1.0 + 0.10000000000000001 * exp(-024332029034784559 * var_chaste_interface__membrane__V)); // picoA_per_picoF
        const double var_sodium_potassium_pump_current__i_NaK = 2.2983750000000001 * var_chaste_interface__sodium_dynamics__Na_i / ((40 + var_chaste_interface__sodium_dynamics__Na_i) * (1.0 + 035299999999999998 * exp(-037433890822745473 * var_chaste_interface__membrane__V) + 0.1245 * exp(-0037433890822745472 * var_chaste_interface__membrane__V))); // picoA_per_picoF
        const double var_transient_outward_current__i_to = (-var_reversal_potentials__E_K + var_chaste_interface__membrane__V) * mParameters[3] * var_chaste_interface__transient_outward_current_r_gate__r * var_chaste_interface__transient_outward_current_s_gate__s; // picoA_per_picoF
        const double var_chaste_interface__i_ionic = (var_L_type_Ca_current__i_CaL + var_calcium_background_current__i_b_Ca + var_calcium_pump_current__i_p_Ca + var_fast_sodium_current__i_Na + var_inward_rectifier_potassium_current__i_K1 + var_potassium_pump_current__i_p_K + var_rapid_time_dependent_potassium_current__i_Kr + var_slow_time_dependent_potassium_current__i_Ks + var_sodium_background_current__i_b_Na + var_sodium_calcium_exchanger_current__i_NaCa + var_sodium_potassium_pump_current__i_NaK + var_transient_outward_current__i_to) * HeartConfig::Instance()->GetCapacitance(); // uA_per_cm2

        const double i_ionic = var_chaste_interface__i_ionic;
        EXCEPT_IF_NOT(!std::isnan(i_ionic));
        return i_ionic;
    }

    void Cellten_tusscher_model_2006_epiFromCellML::EvaluateYDerivatives(double var_chaste_interface__environment__time, const std::vector<double>& rY, std::vector<double>& rDY)
    {
        // Inputs:
        // Time units: millisecond
        double var_chaste_interface__membrane__V = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : rY[0]);
        // Units: millivolt; Initial value: -85.23
        double var_chaste_interface__calcium_dynamics__Ca_i = rY[1];
        // Units: millimolar; Initial value: 000126
        double var_chaste_interface__rapid_time_dependent_potassium_current_Xr1_gate__Xr1 = rY[2];
        // Units: dimensionless; Initial value: 00621
        double var_chaste_interface__rapid_time_dependent_potassium_current_Xr2_gate__Xr2 = rY[3];
        // Units: dimensionless; Initial value: 0.4712
        double var_chaste_interface__slow_time_dependent_potassium_current_Xs_gate__Xs = rY[4];
        // Units: dimensionless; Initial value: 0095
        double var_chaste_interface__fast_sodium_current_m_gate__m = rY[5];
        // Units: dimensionless; Initial value: 00172
        double var_chaste_interface__fast_sodium_current_h_gate__h = rY[6];
        // Units: dimensionless; Initial value: 0.7444
        double var_chaste_interface__fast_sodium_current_j_gate__j = rY[7];
        // Units: dimensionless; Initial value: 0.7045
        double var_chaste_interface__L_type_Ca_current_d_gate__d = rY[8];
        // Units: dimensionless; Initial value: 3.373e-05
        double var_chaste_interface__L_type_Ca_current_f_gate__f = rY[9];
        // Units: dimensionless; Initial value: 0.7888
        double var_chaste_interface__L_type_Ca_current_f2_gate__f2 = rY[10];
        // Units: dimensionless; Initial value: 0.9755
        double var_chaste_interface__L_type_Ca_current_fCass_gate__fCass = rY[11];
        // Units: dimensionless; Initial value: 0.9953
        double var_chaste_interface__transient_outward_current_s_gate__s = rY[12];
        // Units: dimensionless; Initial value: 0.999998
        double var_chaste_interface__transient_outward_current_r_gate__r = rY[13];
        // Units: dimensionless; Initial value: 2.42e-08
        double var_chaste_interface__calcium_dynamics__Ca_SR = rY[14];
        // Units: millimolar; Initial value: 3.64
        double var_chaste_interface__calcium_dynamics__Ca_ss = rY[15];
        // Units: millimolar; Initial value: 00036
        double var_chaste_interface__calcium_dynamics__R_prime = rY[16];
        // Units: dimensionless; Initial value: 0.9073
        double var_chaste_interface__sodium_dynamics__Na_i = rY[17];
        // Units: millimolar; Initial value: 8.604
        double var_chaste_interface__potassium_dynamics__K_i = rY[18];
        // Units: millimolar; Initial value: 136.89

        // Mathematics
        double d_dt_chaste_interface_var_membrane__V;
        const double d_dt_chaste_interface_var_L_type_Ca_current_fCass_gate__fCass = (0.40000000000000002 - var_chaste_interface__L_type_Ca_current_fCass_gate__fCass + 0.59999999999999998 / (1.0 + 399.99999999999994 * pow(var_chaste_interface__calcium_dynamics__Ca_ss, 2))) / (2.0 + 80 / (1.0 + 399.99999999999994 * pow(var_chaste_interface__calcium_dynamics__Ca_ss, 2))); // 1 / millisecond
        const double var_calcium_dynamics__i_leak = 00036000000000000002 * var_chaste_interface__calcium_dynamics__Ca_SR - 00036000000000000002 * var_chaste_interface__calcium_dynamics__Ca_i; // millimolar_per_millisecond
        const double var_calcium_dynamics__i_up = 0063749999999999996 / (1.0 + 6.2499999999999997e-8 / pow(var_chaste_interface__calcium_dynamics__Ca_i, 2)); // millimolar_per_millisecond
        const double var_calcium_dynamics__i_xfer = 0038 * var_chaste_interface__calcium_dynamics__Ca_ss - 0038 * var_chaste_interface__calcium_dynamics__Ca_i; // millimolar_per_millisecond
        const double var_calcium_dynamics__kcasr = 2.5 - 1.5 / (1.0 + 2.25 / pow(var_chaste_interface__calcium_dynamics__Ca_SR, 2)); // dimensionless
        const double var_calcium_dynamics__i_rel = 015299999999999998 * pow(var_chaste_interface__calcium_dynamics__Ca_ss, 2) * (-var_chaste_interface__calcium_dynamics__Ca_ss + var_chaste_interface__calcium_dynamics__Ca_SR) * var_chaste_interface__calcium_dynamics__R_prime / ((059999999999999998 + 0.14999999999999999 * pow(var_chaste_interface__calcium_dynamics__Ca_ss, 2) / var_calcium_dynamics__kcasr) * var_calcium_dynamics__kcasr); // millimolar_per_millisecond
        const double d_dt_chaste_interface_var_calcium_dynamics__Ca_SR = 1.0 * (-var_calcium_dynamics__i_leak - var_calcium_dynamics__i_rel + var_calcium_dynamics__i_up) / (1.0 + 3.0 / pow((0.29999999999999999 + var_chaste_interface__calcium_dynamics__Ca_SR), 2)); // millimolar / millisecond
        const double d_dt_chaste_interface_var_calcium_dynamics__R_prime = 0050000000000000001 - 0050000000000000001 * var_chaste_interface__calcium_dynamics__R_prime - 044999999999999998 * var_chaste_interface__calcium_dynamics__Ca_ss * var_chaste_interface__calcium_dynamics__R_prime * var_calcium_dynamics__kcasr; // 1 / millisecond
        const double var_calcium_pump_current__i_p_Ca = 0.12379999999999999 * var_chaste_interface__calcium_dynamics__Ca_i / (00050000000000000001 + var_chaste_interface__calcium_dynamics__Ca_i); // picoA_per_picoF
        const double var_L_type_Ca_current__i_CaL = 14447.286958825251 * (-2.0 + 0.25 * var_chaste_interface__calcium_dynamics__Ca_ss * exp(-1.1230167246823641 + 074867781645490947 * var_chaste_interface__membrane__V)) * (-15.0 + var_chaste_interface__membrane__V) * mParameters[0] * var_chaste_interface__L_type_Ca_current_d_gate__d * var_chaste_interface__L_type_Ca_current_f2_gate__f2 * var_chaste_interface__L_type_Ca_current_fCass_gate__fCass * var_chaste_interface__L_type_Ca_current_f_gate__f / (-1.0 + exp(-1.1230167246823641 + 074867781645490947 * var_chaste_interface__membrane__V)); // picoA_per_picoF
        const double d_dt_chaste_interface_var_L_type_Ca_current_d_gate__d = (-var_chaste_interface__L_type_Ca_current_d_gate__d + 1.0 / (1.0 + exp(-1.0666666666666667 - 0.13333333333333333 * var_chaste_interface__membrane__V))) / (1.0 / (1.0 + exp(2.5 - 050000000000000003 * var_chaste_interface__membrane__V)) + 1.3999999999999999 * (0.25 + 1.3999999999999999 / (1.0 + exp(-2.6923076923076925 - 076923076923076927 * var_chaste_interface__membrane__V))) / (1.0 + exp(1.0 + 0.20000000000000001 * var_chaste_interface__membrane__V))); // 1 / millisecond
        const double d_dt_chaste_interface_var_L_type_Ca_current_f2_gate__f2 = (0.33000000000000002 - var_chaste_interface__L_type_Ca_current_f2_gate__f2 + 0.67000000000000004 / (1.0 + exp(5.0 + 0.14285714285714285 * var_chaste_interface__membrane__V))) / (80 / (1.0 + exp(3.0 + 0.10000000000000001 * var_chaste_interface__membrane__V)) + 31.0 / (1.0 + exp(2.5 - 0.10000000000000001 * var_chaste_interface__membrane__V)) + 562.0 * exp(-3.0375000000000001 * pow((1 + 037037037037037035 * var_chaste_interface__membrane__V), 2))); // 1 / millisecond
        const double d_dt_chaste_interface_var_L_type_Ca_current_f_gate__f = (-var_chaste_interface__L_type_Ca_current_f_gate__f + 1.0 / (1.0 + exp(2.8571428571428572 + 0.14285714285714285 * var_chaste_interface__membrane__V))) / (20 + 200 / (1.0 + exp(1.3 - 0.10000000000000001 * var_chaste_interface__membrane__V)) + 180 / (1.0 + exp(3.0 + 0.10000000000000001 * var_chaste_interface__membrane__V)) + 1102.5 * exp(-3.2400000000000002 * pow((1 + 037037037037037035 * var_chaste_interface__membrane__V), 2))); // 1 / millisecond
        const double d_dt_chaste_interface_var_fast_sodium_current_h_gate__h = (-var_chaste_interface__fast_sodium_current_h_gate__h + 1.0 / pow((1.0 + exp(9.6298788694481825 + 0.13458950201884254 * var_chaste_interface__membrane__V)), 2)) * (1.0 * ((var_chaste_interface__membrane__V < -40) ? (057000000000000002 * exp(-11.764705882352942 - 0.14705882352941177 * var_chaste_interface__membrane__V)) : (0)) + 1.0 * ((var_chaste_interface__membrane__V < -40) ? (310000 * exp(0.34849999999999998 * var_chaste_interface__membrane__V) + 2.7000000000000002 * exp(079000000000000001 * var_chaste_interface__membrane__V)) : (5.9230769230769234 / (1.0 + exp(-0.96036036036036043 - 0900900900900901 * var_chaste_interface__membrane__V))))); // 1 / millisecond
        const double d_dt_chaste_interface_var_fast_sodium_current_j_gate__j = (-var_chaste_interface__fast_sodium_current_j_gate__j + 1.0 / pow((1.0 + exp(9.6298788694481825 + 0.13458950201884254 * var_chaste_interface__membrane__V)), 2)) * (1.0 * ((var_chaste_interface__membrane__V < -40) ? (024240000000000001 * exp(-01052 * var_chaste_interface__membrane__V) / (1.0 + exp(-5.5312920000000005 - 0.13780000000000001 * var_chaste_interface__membrane__V))) : (0.59999999999999998 * exp(057000000000000002 * var_chaste_interface__membrane__V) / (1.0 + exp(-3.2000000000000002 - 0.10000000000000001 * var_chaste_interface__membrane__V)))) + 1.0 * ((var_chaste_interface__membrane__V < -40) ? (1.0 * (37.780000000000001 + var_chaste_interface__membrane__V) * (-25428.0 * exp(0.24440000000000001 * var_chaste_interface__membrane__V) - 6.9480000000000002e-6 * exp(-043909999999999998 * var_chaste_interface__membrane__V)) / (1.0 + exp(24.640530000000002 + 0.311 * var_chaste_interface__membrane__V))) : (0))); // 1 / millisecond
        const double d_dt_chaste_interface_var_fast_sodium_current_m_gate__m = 1.0 * (1.0 + exp(-12.0 - 0.20000000000000001 * var_chaste_interface__membrane__V)) * (-var_chaste_interface__fast_sodium_current_m_gate__m + 1.0 / pow((1.0 + exp(-6.2967884828349945 - 0.11074197120708749 * var_chaste_interface__membrane__V)), 2)) / (0.10000000000000001 / (1.0 + exp(7.0 + 0.20000000000000001 * var_chaste_interface__membrane__V)) + 0.10000000000000001 / (1.0 + exp(-0.25 + 0050000000000000001 * var_chaste_interface__membrane__V))); // 1 / millisecond
        const double d_dt_chaste_interface_var_calcium_dynamics__Ca_ss = 1.0 * (2007315288953912 * var_calcium_dynamics__i_rel - 017532824616602913 * var_L_type_Ca_current__i_CaL - 300 * var_calcium_dynamics__i_xfer) / (1.0 + 0001 / pow((00025000000000000001 + var_chaste_interface__calcium_dynamics__Ca_ss), 2)); // millimolar / millisecond
        const double var_membrane__i_Stim = GetIntracellularAreaStimulus(var_chaste_interface__environment__time) / HeartConfig::Instance()->GetCapacitance(); // picoA_per_picoF
        const double d_dt_chaste_interface_var_rapid_time_dependent_potassium_current_Xr1_gate__Xr1 = 00037037037037037035 * (1.0 + exp(2.6086956521739131 + 086956521739130432 * var_chaste_interface__membrane__V)) * (1.0 + exp(-4.5 - 0.10000000000000001 * var_chaste_interface__membrane__V)) * (-var_chaste_interface__rapid_time_dependent_potassium_current_Xr1_gate__Xr1 + 1.0 / (1.0 + exp(-3.7142857142857144 - 0.14285714285714285 * var_chaste_interface__membrane__V))); // 1 / millisecond
        const double d_dt_chaste_interface_var_rapid_time_dependent_potassium_current_Xr2_gate__Xr2 = 0.29761904761904762 * (1.0 + exp(-3.0 + 050000000000000003 * var_chaste_interface__membrane__V)) * (1.0 + exp(-3.0 - 050000000000000003 * var_chaste_interface__membrane__V)) * (-var_chaste_interface__rapid_time_dependent_potassium_current_Xr2_gate__Xr2 + 1.0 / (1.0 + exp(3.6666666666666665 + 041666666666666664 * var_chaste_interface__membrane__V))); // 1 / millisecond
        const double var_calcium_background_current__i_b_Ca = 00059199999999999997 * var_chaste_interface__membrane__V - 0079072731552699126 * log(2.0 / var_chaste_interface__calcium_dynamics__Ca_i); // picoA_per_picoF
        const double var_reversal_potentials__E_K = 26.713760659695652 * log(5.4000000000000004 / var_chaste_interface__potassium_dynamics__K_i); // millivolt
        const double var_inward_rectifier_potassium_current__i_K1 = 0.54050000000000009 * (-var_reversal_potentials__E_K + var_chaste_interface__membrane__V) / ((1.0 + exp(-12.0 + 059999999999999998 * var_chaste_interface__membrane__V - 059999999999999998 * var_reversal_potentials__E_K)) * (0.10000000000000001 / (1.0 + exp(-12.0 + 059999999999999998 * var_chaste_interface__membrane__V - 059999999999999998 * var_reversal_potentials__E_K)) + (3.0 * exp(02 + 00020000000000000001 * var_chaste_interface__membrane__V - 00020000000000000001 * var_reversal_potentials__E_K) + exp(-1.0 + 0.10000000000000001 * var_chaste_interface__membrane__V - 0.10000000000000001 * var_reversal_potentials__E_K)) / (1.0 + exp(0.5 * var_reversal_potentials__E_K - 0.5 * var_chaste_interface__membrane__V)))); // picoA_per_picoF
        const double var_potassium_pump_current__i_p_K = 0146 * (-var_reversal_potentials__E_K + var_chaste_interface__membrane__V) / (1.0 + exp(4.1806020066889626 - 0.16722408026755853 * var_chaste_interface__membrane__V)); // picoA_per_picoF
        const double var_rapid_time_dependent_potassium_current__i_Kr = 1.0 * (-var_reversal_potentials__E_K + var_chaste_interface__membrane__V) * mParameters[2] * var_chaste_interface__rapid_time_dependent_potassium_current_Xr1_gate__Xr1 * var_chaste_interface__rapid_time_dependent_potassium_current_Xr2_gate__Xr2; // picoA_per_picoF
        const double d_dt_chaste_interface_var_slow_time_dependent_potassium_current_Xs_gate__Xs = (-var_chaste_interface__slow_time_dependent_potassium_current_Xs_gate__Xs + 1.0 / (1.0 + exp(-0.35714285714285715 - 071428571428571425 * var_chaste_interface__membrane__V))) / (80 + 1400 / (sqrt(1.0 + exp(0.83333333333333337 - 0.16666666666666666 * var_chaste_interface__membrane__V)) * (1.0 + exp(-2.3333333333333335 + 066666666666666666 * var_chaste_interface__membrane__V)))); // 1 / millisecond
        const double var_reversal_potentials__E_Na = 26.713760659695652 * log(140 / var_chaste_interface__sodium_dynamics__Na_i); // millivolt
        const double var_fast_sodium_current__i_Na = pow(var_chaste_interface__fast_sodium_current_m_gate__m, 3) * (-var_reversal_potentials__E_Na + var_chaste_interface__membrane__V) * mParameters[1] * var_chaste_interface__fast_sodium_current_h_gate__h * var_chaste_interface__fast_sodium_current_j_gate__j; // picoA_per_picoF
        const double var_slow_time_dependent_potassium_current__i_Ks = 0.39200000000000002 * pow(var_chaste_interface__slow_time_dependent_potassium_current_Xs_gate__Xs, 2) * (-26.713760659695652 * log(9.5999999999999996 / (029999999999999999 * var_chaste_interface__sodium_dynamics__Na_i + var_chaste_interface__potassium_dynamics__K_i)) + var_chaste_interface__membrane__V); // picoA_per_picoF
        const double var_sodium_background_current__i_b_Na = 00029 * var_chaste_interface__membrane__V - 00029 * var_reversal_potentials__E_Na; // picoA_per_picoF
        const double var_sodium_calcium_exchanger_current__i_NaCa = 8.6662202299424464e-5 * (2.0 * pow(var_chaste_interface__sodium_dynamics__Na_i, 3) * exp(013101861787960915 * var_chaste_interface__membrane__V) - 6860000 * var_chaste_interface__calcium_dynamics__Ca_i * exp(-024332029034784559 * var_chaste_interface__membrane__V)) / (1.0 + 0.10000000000000001 * exp(-024332029034784559 * var_chaste_interface__membrane__V)); // picoA_per_picoF
        const double d_dt_chaste_interface_var_calcium_dynamics__Ca_i = 1.0 * (066691050963179718 * var_calcium_dynamics__i_leak + 00011688549744401942 * var_sodium_calcium_exchanger_current__i_NaCa - 066691050963179718 * var_calcium_dynamics__i_up - 5.8442748722009712e-5 * var_calcium_background_current__i_b_Ca - 5.8442748722009712e-5 * var_calcium_pump_current__i_p_Ca + var_calcium_dynamics__i_xfer) / (1.0 + 00020000000000000001 / pow((001 + var_chaste_interface__calcium_dynamics__Ca_i), 2)); // millimolar / millisecond
        const double var_sodium_potassium_pump_current__i_NaK = 2.2983750000000001 * var_chaste_interface__sodium_dynamics__Na_i / ((40 + var_chaste_interface__sodium_dynamics__Na_i) * (1.0 + 035299999999999998 * exp(-037433890822745473 * var_chaste_interface__membrane__V) + 0.1245 * exp(-0037433890822745472 * var_chaste_interface__membrane__V))); // picoA_per_picoF
        const double d_dt_chaste_interface_var_sodium_dynamics__Na_i = -00035065649233205829 * var_sodium_calcium_exchanger_current__i_NaCa - 00035065649233205829 * var_sodium_potassium_pump_current__i_NaK - 00011688549744401942 * var_fast_sodium_current__i_Na - 00011688549744401942 * var_sodium_background_current__i_b_Na; // millimolar / millisecond
        const double d_dt_chaste_interface_var_transient_outward_current_r_gate__r = (-var_chaste_interface__transient_outward_current_r_gate__r + 1.0 / (1.0 + exp(3.3333333333333335 - 0.16666666666666666 * var_chaste_interface__membrane__V))) / (0.80000000000000004 + 9.5 * exp(-0.88888888888888884 * pow((1 + 025000000000000001 * var_chaste_interface__membrane__V), 2))); // 1 / millisecond
        const double var_transient_outward_current__i_to = (-var_reversal_potentials__E_K + var_chaste_interface__membrane__V) * mParameters[3] * var_chaste_interface__transient_outward_current_r_gate__r * var_chaste_interface__transient_outward_current_s_gate__s; // picoA_per_picoF
        const double d_dt_chaste_interface_var_potassium_dynamics__K_i = 00023377099488803885 * var_sodium_potassium_pump_current__i_NaK - 00011688549744401942 * var_inward_rectifier_potassium_current__i_K1 - 00011688549744401942 * var_membrane__i_Stim - 00011688549744401942 * var_potassium_pump_current__i_p_K - 00011688549744401942 * var_rapid_time_dependent_potassium_current__i_Kr - 00011688549744401942 * var_slow_time_dependent_potassium_current__i_Ks - 00011688549744401942 * var_transient_outward_current__i_to; // millimolar / millisecond
        const double d_dt_chaste_interface_var_transient_outward_current_s_gate__s = (-var_chaste_interface__transient_outward_current_s_gate__s + 1.0 / (1.0 + exp(4.0 + 0.20000000000000001 * var_chaste_interface__membrane__V))) / (3.0 + 5.0 / (1.0 + exp(-4.0 + 0.20000000000000001 * var_chaste_interface__membrane__V)) + 85.0 * exp(-6.328125 * pow((1 + 022222222222222223 * var_chaste_interface__membrane__V), 2))); // 1 / millisecond

        if (mSetVoltageDerivativeToZero)
        {
            d_dt_chaste_interface_var_membrane__V = 0;
        }
        else
        {
            d_dt_chaste_interface_var_membrane__V = -var_L_type_Ca_current__i_CaL - var_calcium_background_current__i_b_Ca - var_calcium_pump_current__i_p_Ca - var_fast_sodium_current__i_Na - var_inward_rectifier_potassium_current__i_K1 - var_membrane__i_Stim - var_potassium_pump_current__i_p_K - var_rapid_time_dependent_potassium_current__i_Kr - var_slow_time_dependent_potassium_current__i_Ks - var_sodium_background_current__i_b_Na - var_sodium_calcium_exchanger_current__i_NaCa - var_sodium_potassium_pump_current__i_NaK - var_transient_outward_current__i_to; // millivolt / millisecond
        }
        
        rDY[0] = d_dt_chaste_interface_var_membrane__V;
        rDY[1] = d_dt_chaste_interface_var_calcium_dynamics__Ca_i;
        rDY[2] = d_dt_chaste_interface_var_rapid_time_dependent_potassium_current_Xr1_gate__Xr1;
        rDY[3] = d_dt_chaste_interface_var_rapid_time_dependent_potassium_current_Xr2_gate__Xr2;
        rDY[4] = d_dt_chaste_interface_var_slow_time_dependent_potassium_current_Xs_gate__Xs;
        rDY[5] = d_dt_chaste_interface_var_fast_sodium_current_m_gate__m;
        rDY[6] = d_dt_chaste_interface_var_fast_sodium_current_h_gate__h;
        rDY[7] = d_dt_chaste_interface_var_fast_sodium_current_j_gate__j;
        rDY[8] = d_dt_chaste_interface_var_L_type_Ca_current_d_gate__d;
        rDY[9] = d_dt_chaste_interface_var_L_type_Ca_current_f_gate__f;
        rDY[10] = d_dt_chaste_interface_var_L_type_Ca_current_f2_gate__f2;
        rDY[11] = d_dt_chaste_interface_var_L_type_Ca_current_fCass_gate__fCass;
        rDY[12] = d_dt_chaste_interface_var_transient_outward_current_s_gate__s;
        rDY[13] = d_dt_chaste_interface_var_transient_outward_current_r_gate__r;
        rDY[14] = d_dt_chaste_interface_var_calcium_dynamics__Ca_SR;
        rDY[15] = d_dt_chaste_interface_var_calcium_dynamics__Ca_ss;
        rDY[16] = d_dt_chaste_interface_var_calcium_dynamics__R_prime;
        rDY[17] = d_dt_chaste_interface_var_sodium_dynamics__Na_i;
        rDY[18] = d_dt_chaste_interface_var_potassium_dynamics__K_i;
    }

    std::vector<double> Cellten_tusscher_model_2006_epiFromCellML::ComputeDerivedQuantities(double var_chaste_interface__environment__time, const std::vector<double> & rY)
    {
        // Inputs:
        // Time units: millisecond
        

        // Mathematics
        const double var_membrane__i_Stim_converter = GetIntracellularAreaStimulus(var_chaste_interface__environment__time); // uA_per_cm2

        std::vector<double> dqs(1);
        dqs[0] = var_membrane__i_Stim_converter;
        return dqs;
    }

template<>
void OdeSystemInformation<Cellten_tusscher_model_2006_epiFromCellML>::Initialise(void)
{
    this->mSystemName = "tentusscher_panfilov_2006_epi";
    this->mFreeVariableName = "environment__time";
    this->mFreeVariableUnits = "millisecond";

    // rY[0]:
    this->mVariableNames.push_back("membrane_voltage");
    this->mVariableUnits.push_back("millivolt");
    this->mInitialConditions.push_back(-85.23);

    // rY[1]:
    this->mVariableNames.push_back("cytosolic_calcium_concentration");
    this->mVariableUnits.push_back("millimolar");
    this->mInitialConditions.push_back(000126);

    // rY[2]:
    this->mVariableNames.push_back("rapid_time_dependent_potassium_current_Xr1_gate__Xr1");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(00621);

    // rY[3]:
    this->mVariableNames.push_back("rapid_time_dependent_potassium_current_Xr2_gate__Xr2");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.4712);

    // rY[4]:
    this->mVariableNames.push_back("slow_time_dependent_potassium_current_Xs_gate__Xs");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0095);

    // rY[5]:
    this->mVariableNames.push_back("fast_sodium_current_m_gate__m");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(00172);

    // rY[6]:
    this->mVariableNames.push_back("fast_sodium_current_h_gate__h");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.7444);

    // rY[7]:
    this->mVariableNames.push_back("fast_sodium_current_j_gate__j");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.7045);

    // rY[8]:
    this->mVariableNames.push_back("L_type_Ca_current_d_gate__d");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(3.373e-05);

    // rY[9]:
    this->mVariableNames.push_back("L_type_Ca_current_f_gate__f");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.7888);

    // rY[10]:
    this->mVariableNames.push_back("L_type_Ca_current_f2_gate__f2");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.9755);

    // rY[11]:
    this->mVariableNames.push_back("L_type_Ca_current_fCass_gate__fCass");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.9953);

    // rY[12]:
    this->mVariableNames.push_back("transient_outward_current_s_gate__s");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.999998);

    // rY[13]:
    this->mVariableNames.push_back("transient_outward_current_r_gate__r");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(2.42e-08);

    // rY[14]:
    this->mVariableNames.push_back("calcium_dynamics__Ca_SR");
    this->mVariableUnits.push_back("millimolar");
    this->mInitialConditions.push_back(3.64);

    // rY[15]:
    this->mVariableNames.push_back("calcium_dynamics__Ca_ss");
    this->mVariableUnits.push_back("millimolar");
    this->mInitialConditions.push_back(00036);

    // rY[16]:
    this->mVariableNames.push_back("calcium_dynamics__R_prime");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.9073);

    // rY[17]:
    this->mVariableNames.push_back("sodium_dynamics__Na_i");
    this->mVariableUnits.push_back("millimolar");
    this->mInitialConditions.push_back(8.604);

    // rY[18]:
    this->mVariableNames.push_back("potassium_dynamics__K_i");
    this->mVariableUnits.push_back("millimolar");
    this->mInitialConditions.push_back(136.89);

    // mParameters[0]:
    this->mParameterNames.push_back("membrane_L_type_calcium_current_conductance");
    this->mParameterUnits.push_back("litre_per_farad_second");

    // mParameters[1]:
    this->mParameterNames.push_back("membrane_fast_sodium_current_conductance");
    this->mParameterUnits.push_back("nanoS_per_picoF");

    // mParameters[2]:
    this->mParameterNames.push_back("membrane_rapid_delayed_rectifier_potassium_current_conductance");
    this->mParameterUnits.push_back("nanoS_per_picoF");

    // mParameters[3]:
    this->mParameterNames.push_back("membrane_transient_outward_current_conductance");
    this->mParameterUnits.push_back("nanoS_per_picoF");

    // Derived Quantity index [0]:
    this->mDerivedQuantityNames.push_back("membrane_stimulus_current");
    this->mDerivedQuantityUnits.push_back("uA_per_cm2");

    
    this->mAttributes["SuggestedForwardEulerTimestep"] = 001;
    this->mInitialised = true;
}

// Serialization for Boost >= 1.36
#include "SerializationExportWrapperForCpp.hpp"
CHASTE_CLASS_EXPORT(Cellten_tusscher_model_2006_epiFromCellML)
