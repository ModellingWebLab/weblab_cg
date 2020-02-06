//! @file
//!
//! This source file was generated from CellML by chaste_codegen version 0.0.1
//!
//! Model: noble_model_1991
//!
//! Processed by chaste_codegen: https://github.com/ModellingWebLab/chaste-codegen
//!     (translator: chaste_codegen, model type: normal)
//! on 2020-02-06 15:30:28
//!
//! <autogenerated>

#include "noble_model_1991.hpp"
#include <cmath>
#include <cassert>
#include <memory>
#include "Exception.hpp"
#include "OdeSystemInformation.hpp"
#include "RegularStimulus.hpp"
#include "HeartConfig.hpp"
#include "IsNan.hpp"
#include "MathsCustomFunctions.hpp"

    boost::shared_ptr<RegularStimulus> Cellnoble_model_1991FromCellML::UseCellMLDefaultStimulus()
    {
        // Use the default stimulus specified by CellML metadata
        const double var_chaste_interface__membrane__stim_amplitude = -63.157894736842103 * HeartConfig::Instance()->GetCapacitance(); // uA_per_cm2
        const double var_chaste_interface__membrane__stim_duration = 2.0; // millisecond
        const double var_chaste_interface__membrane__stim_period = 1000.0; // millisecond
        const double var_chaste_interface__membrane__stim_start = 100.0; // millisecond
        boost::shared_ptr<RegularStimulus> p_cellml_stim(new RegularStimulus(
                -fabs(var_chaste_interface__membrane__stim_amplitude),
                var_chaste_interface__membrane__stim_duration,
                var_chaste_interface__membrane__stim_period,
                var_chaste_interface__membrane__stim_start
                ));
        mpIntracellularStimulus = p_cellml_stim;
        return p_cellml_stim;
    }

    Cellnoble_model_1991FromCellML::Cellnoble_model_1991FromCellML(boost::shared_ptr<AbstractIvpOdeSolver> pSolver, boost::shared_ptr<AbstractStimulusFunction> pIntracellularStimulus)
        : AbstractCardiacCell(
                pSolver,
                17,
                0,
                pIntracellularStimulus)
    {
        // Time units: millisecond
        //
        this->mpSystemInfo = OdeSystemInformation<Cellnoble_model_1991FromCellML>::Instance();
        Init();

        // We have a default stimulus specified in the CellML file metadata
        this->mHasDefaultStimulusFromCellML = true;
        
    }

    Cellnoble_model_1991FromCellML::~Cellnoble_model_1991FromCellML()
    {
    }

    double Cellnoble_model_1991FromCellML::GetIIonic(const std::vector<double>* pStateVariables)
    {
        // For state variable interpolation (SVI) we read in interpolated state variables,
        // otherwise for ionic current interpolation (ICI) we use the state variables of this model (node).
        if (!pStateVariables) pStateVariables = &rGetStateVariables();
        const std::vector<double>& rY = *pStateVariables;
        double var_chaste_interface__membrane__V = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : rY[0]);
        // Units: millivolt; Initial value: -93.0
        double var_chaste_interface__time_dependent_potassium_current_x_gate__x = rY[1];
        // Units: dimensionless; Initial value: 0.001
        double var_chaste_interface__fast_sodium_current_m_gate__m = rY[2];
        // Units: dimensionless; Initial value: 0.000105
        double var_chaste_interface__fast_sodium_current_h_gate__h = rY[3];
        // Units: dimensionless; Initial value: 0.99816539
        double var_chaste_interface__L_type_Ca_channel_d_gate__d = rY[4];
        // Units: dimensionless; Initial value: 0.0
        double var_chaste_interface__L_type_Ca_channel_f_gate__f = rY[5];
        // Units: dimensionless; Initial value: 1.0
        double var_chaste_interface__transient_outward_current_s_gate__s = rY[6];
        // Units: dimensionless; Initial value: 1.0
        double var_chaste_interface__transient_outward_current_r_gate__r = rY[7];
        // Units: dimensionless; Initial value: 0.0
        double var_chaste_interface__intracellular_sodium_concentration__Na_i = rY[10];
        // Units: millimolar; Initial value: 5.0
        double var_chaste_interface__intracellular_potassium_concentration__K_i = rY[11];
        // Units: millimolar; Initial value: 140.0
        double var_chaste_interface__intracellular_calcium_concentration__Ca_i = rY[12];
        // Units: millimolar; Initial value: 7.63e-06
        
        const double var_L_type_Ca_channel__i_Ca_L_Ca = 0.037433890822745473 * (-50.0 + var_chaste_interface__membrane__V) * (-2.0 * exp(3.7433890822745473 - 0.074867781645490947 * var_chaste_interface__membrane__V) + var_chaste_interface__intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473)) * var_chaste_interface__L_type_Ca_channel_d_gate__d * var_chaste_interface__L_type_Ca_channel_f_gate__f / (1.0 - exp(3.7433890822745473 - 0.074867781645490947 * var_chaste_interface__membrane__V)); // nanoA
        const double var_L_type_Ca_channel__i_Ca_L_K = 1.8716945411372739e-5 * (-50.0 + var_chaste_interface__membrane__V) * (-4.0 * exp(1.8716945411372736 - 0.037433890822745473 * var_chaste_interface__membrane__V) + var_chaste_interface__intracellular_potassium_concentration__K_i * exp(1.8716945411372736)) * var_chaste_interface__L_type_Ca_channel_d_gate__d * var_chaste_interface__L_type_Ca_channel_f_gate__f / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * var_chaste_interface__membrane__V)); // nanoA
        const double var_L_type_Ca_channel__i_Ca_L_Na = 9.3584727056863679e-5 * (-50.0 + var_chaste_interface__membrane__V) * (-140.0 * exp(1.8716945411372736 - 0.037433890822745473 * var_chaste_interface__membrane__V) + var_chaste_interface__intracellular_sodium_concentration__Na_i * exp(1.8716945411372736)) * var_chaste_interface__L_type_Ca_channel_d_gate__d * var_chaste_interface__L_type_Ca_channel_f_gate__f / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * var_chaste_interface__membrane__V)); // nanoA
        const double var_calcium_background_current__i_b_Ca = 0.00025000000000000001 * var_chaste_interface__membrane__V - 0.0033392200824619565 * log(2.0 / var_chaste_interface__intracellular_calcium_concentration__Ca_i); // nanoA
        const double var_reversal_potentials__E_K = 26.713760659695652 * log(4.0 / var_chaste_interface__intracellular_potassium_concentration__K_i); // millivolt
        const double var_potassium_background_current__i_b_K = 0.00059999999999999995 * var_chaste_interface__membrane__V - 0.00059999999999999995 * var_reversal_potentials__E_K; // nanoA
        const double var_fast_sodium_current__i_Na = 2.5 * pow(var_chaste_interface__fast_sodium_current_m_gate__m, 3.0) * (-26.713760659695652 * log(140.47999999999999 / (0.12 * var_chaste_interface__intracellular_potassium_concentration__K_i + var_chaste_interface__intracellular_sodium_concentration__Na_i)) + var_chaste_interface__membrane__V) * var_chaste_interface__fast_sodium_current_h_gate__h; // nanoA
        const double var_sodium_background_current__i_b_Na = 0.00059999999999999995 * var_chaste_interface__membrane__V - 0.01602825639581739 * log(140.0 / var_chaste_interface__intracellular_sodium_concentration__Na_i); // nanoA
        const double var_sodium_calcium_exchanger__i_NaCa = 0.00050000000000000001 * (2.0 * pow(var_chaste_interface__intracellular_sodium_concentration__Na_i, 3.0) * exp(0.018716945411372737 * var_chaste_interface__membrane__V) - 2744000.0 * var_chaste_interface__intracellular_calcium_concentration__Ca_i * exp(-0.018716945411372737 * var_chaste_interface__membrane__V)) / (1.0 + 144.92753623188406 * var_chaste_interface__intracellular_calcium_concentration__Ca_i); // nanoA
        const double var_sodium_potassium_pump__i_NaK = 0.55999999999999994 * var_chaste_interface__intracellular_sodium_concentration__Na_i / (40.0 + var_chaste_interface__intracellular_sodium_concentration__Na_i); // nanoA
        const double var_time_dependent_potassium_current__i_K = (0.0071428571428571426 * var_chaste_interface__intracellular_potassium_concentration__K_i - 0.028571428571428571 * exp(-0.037433890822745473 * var_chaste_interface__membrane__V)) * var_chaste_interface__time_dependent_potassium_current_x_gate__x; // nanoA
        const double var_time_independent_potassium_current__i_K1 = 0.2857142857142857 * (-var_reversal_potentials__E_K + var_chaste_interface__membrane__V) / (1.0 + exp(-0.74867781645490949 + 0.074867781645490947 * var_chaste_interface__membrane__V - 0.074867781645490947 * var_reversal_potentials__E_K)); // nanoA
        const double var_transient_outward_current__i_to = 0.0050000000000000001 * (-var_reversal_potentials__E_K + var_chaste_interface__membrane__V) * var_chaste_interface__transient_outward_current_r_gate__r * var_chaste_interface__transient_outward_current_s_gate__s; // nanoA
        const double var_chaste_interface__i_ionic = 10526.315789473683 * (0.001 * var_L_type_Ca_channel__i_Ca_L_Ca + 0.001 * var_L_type_Ca_channel__i_Ca_L_K + 0.001 * var_L_type_Ca_channel__i_Ca_L_Na + 0.001 * var_calcium_background_current__i_b_Ca + 0.001 * var_fast_sodium_current__i_Na + 0.001 * var_potassium_background_current__i_b_K + 0.001 * var_sodium_background_current__i_b_Na + 0.001 * var_sodium_calcium_exchanger__i_NaCa + 0.001 * var_sodium_potassium_pump__i_NaK + 0.001 * var_time_dependent_potassium_current__i_K + 0.001 * var_time_independent_potassium_current__i_K1 + 0.001 * var_transient_outward_current__i_to) * HeartConfig::Instance()->GetCapacitance(); // uA_per_cm2

        const double i_ionic = var_chaste_interface__i_ionic;
        EXCEPT_IF_NOT(!std::isnan(i_ionic));
        return i_ionic;
    }

    void Cellnoble_model_1991FromCellML::EvaluateYDerivatives(double var_chaste_interface__environment__time_converted, const std::vector<double>& rY, std::vector<double>& rDY)
    {
        // Inputs:
        // Time units: millisecond
        double var_chaste_interface__membrane__V = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : rY[0]);
        // Units: millivolt; Initial value: -93.0
        double var_chaste_interface__time_dependent_potassium_current_x_gate__x = rY[1];
        // Units: dimensionless; Initial value: 0.001
        double var_chaste_interface__fast_sodium_current_m_gate__m = rY[2];
        // Units: dimensionless; Initial value: 0.000105
        double var_chaste_interface__fast_sodium_current_h_gate__h = rY[3];
        // Units: dimensionless; Initial value: 0.99816539
        double var_chaste_interface__L_type_Ca_channel_d_gate__d = rY[4];
        // Units: dimensionless; Initial value: 0.0
        double var_chaste_interface__L_type_Ca_channel_f_gate__f = rY[5];
        // Units: dimensionless; Initial value: 1.0
        double var_chaste_interface__transient_outward_current_s_gate__s = rY[6];
        // Units: dimensionless; Initial value: 1.0
        double var_chaste_interface__transient_outward_current_r_gate__r = rY[7];
        // Units: dimensionless; Initial value: 0.0
        double var_chaste_interface__calcium_release__ActFrac = rY[8];
        // Units: dimensionless; Initial value: 0.0
        double var_chaste_interface__calcium_release__ProdFrac = rY[9];
        // Units: dimensionless; Initial value: 0.0
        double var_chaste_interface__intracellular_sodium_concentration__Na_i = rY[10];
        // Units: millimolar; Initial value: 5.0
        double var_chaste_interface__intracellular_potassium_concentration__K_i = rY[11];
        // Units: millimolar; Initial value: 140.0
        double var_chaste_interface__intracellular_calcium_concentration__Ca_i = rY[12];
        // Units: millimolar; Initial value: 7.63e-06
        double var_chaste_interface__intracellular_calcium_concentration__Ca_up = rY[13];
        // Units: millimolar; Initial value: 0.3013
        double var_chaste_interface__intracellular_calcium_concentration__Ca_rel = rY[14];
        // Units: millimolar; Initial value: 0.2989
        double var_chaste_interface__intracellular_calcium_concentration__Ca_Calmod = rY[15];
        // Units: millimolar; Initial value: 0.0003
        double var_chaste_interface__intracellular_calcium_concentration__Ca_Trop = rY[16];
        // Units: millimolar; Initial value: 0.0002

        // Mathematics
        double d_dt_chaste_interface_var_membrane__V;
        const double var_calcium_release__RegBindSite = pow((var_chaste_interface__intracellular_calcium_concentration__Ca_i / (0.00050000000000000001 + var_chaste_interface__intracellular_calcium_concentration__Ca_i)), 2.0); // dimensionless
        const double var_calcium_release__InactRate = 60.0 + 500.0 * var_calcium_release__RegBindSite; // per_second
        const double d_dt_chaste_interface_var_calcium_release__ActFrac = 0.5 * (1.0 - var_chaste_interface__calcium_release__ActFrac - var_chaste_interface__calcium_release__ProdFrac) * var_calcium_release__RegBindSite - 0.001 * var_chaste_interface__calcium_release__ActFrac * var_calcium_release__InactRate; // 1 / millisecond
        const double d_dt_chaste_interface_var_calcium_release__ProdFrac = -0.001 * var_chaste_interface__calcium_release__ProdFrac + 0.001 * var_chaste_interface__calcium_release__ActFrac * var_calcium_release__InactRate; // 1 / millisecond
        const double var_calcium_release__i_rel = 250.0 * pow((var_chaste_interface__calcium_release__ActFrac / (0.25 + var_chaste_interface__calcium_release__ActFrac)), 2.0) * var_chaste_interface__intracellular_calcium_concentration__Ca_rel; // millimolar_per_second
        const double var_calcium_translocation__i_trans = 50.0 * var_chaste_interface__intracellular_calcium_concentration__Ca_up - 50.0 * var_chaste_interface__intracellular_calcium_concentration__Ca_rel; // millimolar_per_second
        const double d_dt_chaste_interface_var_intracellular_calcium_concentration__Ca_rel = 0.0001 * var_calcium_translocation__i_trans - 0.001 * var_calcium_release__i_rel; // millimolar / millisecond
        const double var_intracellular_calcium_concentration__Ca_Calmod_orig_deriv = -50.0 * var_chaste_interface__intracellular_calcium_concentration__Ca_Calmod + 100000.0 * (0.02 - var_chaste_interface__intracellular_calcium_concentration__Ca_Calmod) * var_chaste_interface__intracellular_calcium_concentration__Ca_i; // millimolar / second
        const double d_dt_chaste_interface_var_intracellular_calcium_concentration__Ca_Calmod = 0.001 * var_intracellular_calcium_concentration__Ca_Calmod_orig_deriv; // millimolar / millisecond
        const double var_intracellular_calcium_concentration__Ca_Trop_orig_deriv = -200.0 * var_chaste_interface__intracellular_calcium_concentration__Ca_Trop + 100000.0 * (0.050000000000000003 - var_chaste_interface__intracellular_calcium_concentration__Ca_Trop) * var_chaste_interface__intracellular_calcium_concentration__Ca_i; // millimolar / second
        const double d_dt_chaste_interface_var_intracellular_calcium_concentration__Ca_Trop = 0.001 * var_intracellular_calcium_concentration__Ca_Trop_orig_deriv; // millimolar / millisecond
        const double var_L_type_Ca_channel__i_Ca_L_Ca = 0.037433890822745473 * (-50.0 + var_chaste_interface__membrane__V) * (-2.0 * exp(3.7433890822745473 - 0.074867781645490947 * var_chaste_interface__membrane__V) + var_chaste_interface__intracellular_calcium_concentration__Ca_i * exp(3.7433890822745473)) * var_chaste_interface__L_type_Ca_channel_d_gate__d * var_chaste_interface__L_type_Ca_channel_f_gate__f / (1.0 - exp(3.7433890822745473 - 0.074867781645490947 * var_chaste_interface__membrane__V)); // nanoA
        const double var_L_type_Ca_channel__i_Ca_L_K = 1.8716945411372739e-5 * (-50.0 + var_chaste_interface__membrane__V) * (-4.0 * exp(1.8716945411372736 - 0.037433890822745473 * var_chaste_interface__membrane__V) + var_chaste_interface__intracellular_potassium_concentration__K_i * exp(1.8716945411372736)) * var_chaste_interface__L_type_Ca_channel_d_gate__d * var_chaste_interface__L_type_Ca_channel_f_gate__f / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * var_chaste_interface__membrane__V)); // nanoA
        const double var_L_type_Ca_channel__i_Ca_L_Na = 9.3584727056863679e-5 * (-50.0 + var_chaste_interface__membrane__V) * (-140.0 * exp(1.8716945411372736 - 0.037433890822745473 * var_chaste_interface__membrane__V) + var_chaste_interface__intracellular_sodium_concentration__Na_i * exp(1.8716945411372736)) * var_chaste_interface__L_type_Ca_channel_d_gate__d * var_chaste_interface__L_type_Ca_channel_f_gate__f / (1.0 - exp(1.8716945411372736 - 0.037433890822745473 * var_chaste_interface__membrane__V)); // nanoA
        const double var_L_type_Ca_channel_d_gate__E0_d = 19.0 + var_chaste_interface__membrane__V; // millivolt
        const double d_dt_chaste_interface_var_L_type_Ca_channel_d_gate__d = 0.0030000000000000001 * (1.0 - var_chaste_interface__L_type_Ca_channel_d_gate__d) * ((fabs(var_L_type_Ca_channel_d_gate__E0_d) < 0.0001) ? (120.0) : (30.0 * var_L_type_Ca_channel_d_gate__E0_d / (1.0 - exp(-0.25 * var_L_type_Ca_channel_d_gate__E0_d)))) - 0.0030000000000000001 * ((fabs(var_L_type_Ca_channel_d_gate__E0_d) < 0.0001) ? (120.0) : (12.0 * var_L_type_Ca_channel_d_gate__E0_d / (-1.0 + exp(0.10000000000000001 * var_L_type_Ca_channel_d_gate__E0_d)))) * var_chaste_interface__L_type_Ca_channel_d_gate__d; // 1 / millisecond
        const double d_dt_chaste_interface_var_L_type_Ca_channel_f_gate__f = 0.00050000000000000001 * (1.0 - var_chaste_interface__L_type_Ca_channel_f_gate__f) * ((fabs(34.0 + var_chaste_interface__membrane__V) < 0.0001) ? (25.0) : (6.25 * (34.0 + var_chaste_interface__membrane__V) / (-1.0 + exp(8.5 + 0.25 * var_chaste_interface__membrane__V)))) - 0.025000000000000001 * var_chaste_interface__L_type_Ca_channel_f_gate__f / (1.0 + exp(-8.5 - 0.25 * var_chaste_interface__membrane__V)); // 1 / millisecond
        const double d_dt_chaste_interface_var_fast_sodium_current_h_gate__h = 0.02 * (1.0 - var_chaste_interface__fast_sodium_current_h_gate__h) * exp(-9.375 - 0.125 * var_chaste_interface__membrane__V) - 2.0 * var_chaste_interface__fast_sodium_current_h_gate__h / (1.0 + 320.0 * exp(-7.5 - 0.10000000000000001 * var_chaste_interface__membrane__V)); // 1 / millisecond
        const double d_dt_chaste_interface_var_fast_sodium_current_m_gate__m = 0.001 * (1.0 - var_chaste_interface__fast_sodium_current_m_gate__m) * ((fabs(41.0 + var_chaste_interface__membrane__V) < 1.0000000000000001e-5) ? (2000.0) : (200.0 * (41.0 + var_chaste_interface__membrane__V) / (1.0 - exp(-4.1000000000000005 - 0.10000000000000001 * var_chaste_interface__membrane__V)))) - 8.0 * var_chaste_interface__fast_sodium_current_m_gate__m * exp(-3.6960000000000002 - 0.056000000000000001 * var_chaste_interface__membrane__V); // 1 / millisecond
        const double var_calcium_background_current__i_b_Ca = 0.00025000000000000001 * var_chaste_interface__membrane__V - 0.0033392200824619565 * log(2.0 / var_chaste_interface__intracellular_calcium_concentration__Ca_i); // nanoA
        const double var_reversal_potentials__E_K = 26.713760659695652 * log(4.0 / var_chaste_interface__intracellular_potassium_concentration__K_i); // millivolt
        const double var_potassium_background_current__i_b_K = 0.00059999999999999995 * var_chaste_interface__membrane__V - 0.00059999999999999995 * var_reversal_potentials__E_K; // nanoA
        const double var_fast_sodium_current__i_Na = 2.5 * pow(var_chaste_interface__fast_sodium_current_m_gate__m, 3.0) * (-26.713760659695652 * log(140.47999999999999 / (0.12 * var_chaste_interface__intracellular_potassium_concentration__K_i + var_chaste_interface__intracellular_sodium_concentration__Na_i)) + var_chaste_interface__membrane__V) * var_chaste_interface__fast_sodium_current_h_gate__h; // nanoA
        const double var_sarcoplasmic_reticulum_calcium_pump__i_up = 0.40000000000000002 * var_chaste_interface__intracellular_calcium_concentration__Ca_i / (0.00041999999999999996 + 0.00023999999999999998 * var_chaste_interface__intracellular_calcium_concentration__Ca_up + var_chaste_interface__intracellular_calcium_concentration__Ca_i) - 7.1999999999999988e-6 * var_chaste_interface__intracellular_calcium_concentration__Ca_up / (0.00041999999999999996 + 0.00023999999999999998 * var_chaste_interface__intracellular_calcium_concentration__Ca_up + var_chaste_interface__intracellular_calcium_concentration__Ca_i); // millimolar_per_second
        const double d_dt_chaste_interface_var_intracellular_calcium_concentration__Ca_up = 0.048999999999999995 * var_sarcoplasmic_reticulum_calcium_pump__i_up - 0.001 * var_calcium_translocation__i_trans; // millimolar / millisecond
        const double var_sodium_background_current__i_b_Na = 0.00059999999999999995 * var_chaste_interface__membrane__V - 0.01602825639581739 * log(140.0 / var_chaste_interface__intracellular_sodium_concentration__Na_i); // nanoA
        const double var_sodium_calcium_exchanger__i_NaCa = 0.00050000000000000001 * (2.0 * pow(var_chaste_interface__intracellular_sodium_concentration__Na_i, 3.0) * exp(0.018716945411372737 * var_chaste_interface__membrane__V) - 2744000.0 * var_chaste_interface__intracellular_calcium_concentration__Ca_i * exp(-0.018716945411372737 * var_chaste_interface__membrane__V)) / (1.0 + 144.92753623188406 * var_chaste_interface__intracellular_calcium_concentration__Ca_i); // nanoA
        const double d_dt_chaste_interface_var_intracellular_calcium_concentration__Ca_i = 0.00020408163265306126 * var_calcium_release__i_rel + 0.00063182746016849224 * var_sodium_calcium_exchanger__i_NaCa - 0.001 * var_intracellular_calcium_concentration__Ca_Calmod_orig_deriv - 0.001 * var_intracellular_calcium_concentration__Ca_Trop_orig_deriv - 0.001 * var_sarcoplasmic_reticulum_calcium_pump__i_up - 0.00031591373008424612 * var_L_type_Ca_channel__i_Ca_L_Ca - 0.00031591373008424612 * var_calcium_background_current__i_b_Ca; // millimolar / millisecond
        const double var_sodium_potassium_pump__i_NaK = 0.55999999999999994 * var_chaste_interface__intracellular_sodium_concentration__Na_i / (40.0 + var_chaste_interface__intracellular_sodium_concentration__Na_i); // nanoA
        const double d_dt_chaste_interface_var_intracellular_sodium_concentration__Na_i = -0.0018954823805054767 * var_sodium_calcium_exchanger__i_NaCa - 0.0018954823805054767 * var_sodium_potassium_pump__i_NaK - 0.00063182746016849224 * var_L_type_Ca_channel__i_Ca_L_Na - 0.00063182746016849224 * var_fast_sodium_current__i_Na - 0.00063182746016849224 * var_sodium_background_current__i_b_Na; // millimolar / millisecond
        const double var_time_dependent_potassium_current__i_K = (0.0071428571428571426 * var_chaste_interface__intracellular_potassium_concentration__K_i - 0.028571428571428571 * exp(-0.037433890822745473 * var_chaste_interface__membrane__V)) * var_chaste_interface__time_dependent_potassium_current_x_gate__x; // nanoA
        const double d_dt_chaste_interface_var_time_dependent_potassium_current_x_gate__x = 0.00050000000000000001 * (1.0 - var_chaste_interface__time_dependent_potassium_current_x_gate__x) * exp(4.1300000000000008 + 0.082600000000000007 * var_chaste_interface__membrane__V) / (1.0 + exp(2.8500000000000001 + 0.057000000000000002 * var_chaste_interface__membrane__V)) - 0.0013000000000000002 * var_chaste_interface__time_dependent_potassium_current_x_gate__x * exp(-1.2 - 0.059999999999999998 * var_chaste_interface__membrane__V) / (1.0 + exp(-0.80000000000000004 - 0.040000000000000001 * var_chaste_interface__membrane__V)); // 1 / millisecond
        const double var_time_independent_potassium_current__i_K1 = 0.2857142857142857 * (-var_reversal_potentials__E_K + var_chaste_interface__membrane__V) / (1.0 + exp(-0.74867781645490949 + 0.074867781645490947 * var_chaste_interface__membrane__V - 0.074867781645490947 * var_reversal_potentials__E_K)); // nanoA
        const double d_dt_chaste_interface_var_transient_outward_current_r_gate__r = 0.33300000000000002 / (1.0 + exp(-0.80000000000000004 - 0.20000000000000001 * var_chaste_interface__membrane__V)) - 0.33300000000000002 * var_chaste_interface__transient_outward_current_r_gate__r; // 1 / millisecond
        const double var_transient_outward_current__i_to = 0.0050000000000000001 * (-var_reversal_potentials__E_K + var_chaste_interface__membrane__V) * var_chaste_interface__transient_outward_current_r_gate__r * var_chaste_interface__transient_outward_current_s_gate__s; // nanoA
        const double d_dt_chaste_interface_var_intracellular_potassium_concentration__K_i = 0.0012636549203369845 * var_sodium_potassium_pump__i_NaK - 0.00063182746016849224 * var_L_type_Ca_channel__i_Ca_L_K - 0.00063182746016849224 * var_potassium_background_current__i_b_K - 0.00063182746016849224 * var_time_dependent_potassium_current__i_K - 0.00063182746016849224 * var_time_independent_potassium_current__i_K1 - 0.00063182746016849224 * var_transient_outward_current__i_to; // millimolar / millisecond
        const double d_dt_chaste_interface_var_transient_outward_current_s_gate__s = 3.3000000000000003e-5 * (1.0 - var_chaste_interface__transient_outward_current_s_gate__s) * exp(-0.058823529411764705 * var_chaste_interface__membrane__V) - 0.033000000000000002 * var_chaste_interface__transient_outward_current_s_gate__s / (1.0 + exp(-1.25 - 0.125 * var_chaste_interface__membrane__V)); // 1 / millisecond

        if (mSetVoltageDerivativeToZero)
        {
            d_dt_chaste_interface_var_membrane__V = 0.0;
        }
        else
        {
            d_dt_chaste_interface_var_membrane__V = -10.526315789473683 * var_L_type_Ca_channel__i_Ca_L_Ca - 10.526315789473683 * var_L_type_Ca_channel__i_Ca_L_K - 10.526315789473683 * var_L_type_Ca_channel__i_Ca_L_Na - 10.526315789473683 * var_calcium_background_current__i_b_Ca - 10.526315789473683 * var_fast_sodium_current__i_Na - 10.526315789473683 * var_potassium_background_current__i_b_K - 10.526315789473683 * var_sodium_background_current__i_b_Na - 10.526315789473683 * var_sodium_calcium_exchanger__i_NaCa - 10.526315789473683 * var_sodium_potassium_pump__i_NaK - 10.526315789473683 * var_time_dependent_potassium_current__i_K - 10.526315789473683 * var_time_independent_potassium_current__i_K1 - 10.526315789473683 * var_transient_outward_current__i_to - 0.99999999999999989 * GetIntracellularAreaStimulus(var_chaste_interface__environment__time_converted) / HeartConfig::Instance()->GetCapacitance(); // millivolt / millisecond
        }
        
        rDY[0] = d_dt_chaste_interface_var_membrane__V;
        rDY[1] = d_dt_chaste_interface_var_time_dependent_potassium_current_x_gate__x;
        rDY[2] = d_dt_chaste_interface_var_fast_sodium_current_m_gate__m;
        rDY[3] = d_dt_chaste_interface_var_fast_sodium_current_h_gate__h;
        rDY[4] = d_dt_chaste_interface_var_L_type_Ca_channel_d_gate__d;
        rDY[5] = d_dt_chaste_interface_var_L_type_Ca_channel_f_gate__f;
        rDY[6] = d_dt_chaste_interface_var_transient_outward_current_s_gate__s;
        rDY[7] = d_dt_chaste_interface_var_transient_outward_current_r_gate__r;
        rDY[8] = d_dt_chaste_interface_var_calcium_release__ActFrac;
        rDY[9] = d_dt_chaste_interface_var_calcium_release__ProdFrac;
        rDY[10] = d_dt_chaste_interface_var_intracellular_sodium_concentration__Na_i;
        rDY[11] = d_dt_chaste_interface_var_intracellular_potassium_concentration__K_i;
        rDY[12] = d_dt_chaste_interface_var_intracellular_calcium_concentration__Ca_i;
        rDY[13] = d_dt_chaste_interface_var_intracellular_calcium_concentration__Ca_up;
        rDY[14] = d_dt_chaste_interface_var_intracellular_calcium_concentration__Ca_rel;
        rDY[15] = d_dt_chaste_interface_var_intracellular_calcium_concentration__Ca_Calmod;
        rDY[16] = d_dt_chaste_interface_var_intracellular_calcium_concentration__Ca_Trop;
    }

template<>
void OdeSystemInformation<Cellnoble_model_1991FromCellML>::Initialise(void)
{
    this->mSystemName = "noble_model_1991";
    this->mFreeVariableName = "environment__time_converted";
    this->mFreeVariableUnits = "millisecond";

    // rY[0]:
    this->mVariableNames.push_back("membrane_voltage");
    this->mVariableUnits.push_back("millivolt");
    this->mInitialConditions.push_back(-93.0);

    // rY[1]:
    this->mVariableNames.push_back("time_dependent_potassium_current_x_gate__x");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.001);

    // rY[2]:
    this->mVariableNames.push_back("fast_sodium_current_m_gate__m");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.000105);

    // rY[3]:
    this->mVariableNames.push_back("fast_sodium_current_h_gate__h");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.99816539);

    // rY[4]:
    this->mVariableNames.push_back("L_type_Ca_channel_d_gate__d");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.0);

    // rY[5]:
    this->mVariableNames.push_back("L_type_Ca_channel_f_gate__f");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(1.0);

    // rY[6]:
    this->mVariableNames.push_back("transient_outward_current_s_gate__s");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(1.0);

    // rY[7]:
    this->mVariableNames.push_back("transient_outward_current_r_gate__r");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.0);

    // rY[8]:
    this->mVariableNames.push_back("calcium_release__ActFrac");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.0);

    // rY[9]:
    this->mVariableNames.push_back("calcium_release__ProdFrac");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.0);

    // rY[10]:
    this->mVariableNames.push_back("intracellular_sodium_concentration__Na_i");
    this->mVariableUnits.push_back("millimolar");
    this->mInitialConditions.push_back(5.0);

    // rY[11]:
    this->mVariableNames.push_back("intracellular_potassium_concentration__K_i");
    this->mVariableUnits.push_back("millimolar");
    this->mInitialConditions.push_back(140.0);

    // rY[12]:
    this->mVariableNames.push_back("intracellular_calcium_concentration__Ca_i");
    this->mVariableUnits.push_back("millimolar");
    this->mInitialConditions.push_back(7.63e-06);

    // rY[13]:
    this->mVariableNames.push_back("intracellular_calcium_concentration__Ca_up");
    this->mVariableUnits.push_back("millimolar");
    this->mInitialConditions.push_back(0.3013);

    // rY[14]:
    this->mVariableNames.push_back("intracellular_calcium_concentration__Ca_rel");
    this->mVariableUnits.push_back("millimolar");
    this->mInitialConditions.push_back(0.2989);

    // rY[15]:
    this->mVariableNames.push_back("intracellular_calcium_concentration__Ca_Calmod");
    this->mVariableUnits.push_back("millimolar");
    this->mInitialConditions.push_back(0.0003);

    // rY[16]:
    this->mVariableNames.push_back("intracellular_calcium_concentration__Ca_Trop");
    this->mVariableUnits.push_back("millimolar");
    this->mInitialConditions.push_back(0.0002);

    this->mInitialised = true;
}


// Serialization for Boost >= 1.36
#include "SerializationExportWrapperForCpp.hpp"
CHASTE_CLASS_EXPORT(Cellnoble_model_1991FromCellML)

