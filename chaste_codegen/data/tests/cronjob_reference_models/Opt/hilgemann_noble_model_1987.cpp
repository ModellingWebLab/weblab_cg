//! @file
//!
//! This source file was generated from CellML by chaste_codegen version 0.0.1
//!
//! Model: hilgemann_noble_model_1987
//!
//! Processed by chaste_codegen: https://github.com/ModellingWebLab/chaste-codegen
//!     (translator: chaste_codegen, model type: normal)
//! on 2020-02-25 16:12:38
//!
//! <autogenerated>

#include "hilgemann_noble_model_1987.hpp"
#include <cmath>
#include <cassert>
#include <memory>
#include "Exception.hpp"
#include "OdeSystemInformation.hpp"
#include "RegularStimulus.hpp"
#include "HeartConfig.hpp"
#include "IsNan.hpp"
#include "MathsCustomFunctions.hpp"

    boost::shared_ptr<RegularStimulus> Cellhilgemann_noble_model_1987FromCellML::UseCellMLDefaultStimulus()
    {
        // Use the default stimulus specified by CellML metadata
        const double var_chaste_interface__membrane__stim_amplitude = -33.333333333333336 * HeartConfig::Instance()->GetCapacitance(); // uA_per_cm2
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

    double Cellhilgemann_noble_model_1987FromCellML::GetIntracellularCalciumConcentration()
    {
        return mStateVariables[1];
    }

    Cellhilgemann_noble_model_1987FromCellML::Cellhilgemann_noble_model_1987FromCellML(boost::shared_ptr<AbstractIvpOdeSolver> pSolver, boost::shared_ptr<AbstractStimulusFunction> pIntracellularStimulus)
        : AbstractCardiacCell(
                pSolver,
                15,
                0,
                pIntracellularStimulus)
    {
        // Time units: millisecond
        //
        this->mpSystemInfo = OdeSystemInformation<Cellhilgemann_noble_model_1987FromCellML>::Instance();
        Init();

        // We have a default stimulus specified in the CellML file metadata
        this->mHasDefaultStimulusFromCellML = true;
        
    }

    Cellhilgemann_noble_model_1987FromCellML::~Cellhilgemann_noble_model_1987FromCellML()
    {
    }

    double Cellhilgemann_noble_model_1987FromCellML::GetIIonic(const std::vector<double>* pStateVariables)
    {
        // For state variable interpolation (SVI) we read in interpolated state variables,
        // otherwise for ionic current interpolation (ICI) we use the state variables of this model (node).
        if (!pStateVariables) pStateVariables = &rGetStateVariables();
        const std::vector<double>& rY = *pStateVariables;
        double var_chaste_interface__membrane__V = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : rY[0]);
        // Units: millivolt; Initial value: -88.0
        double var_chaste_interface__intracellular_calcium_concentration__Ca_i = rY[1];
        // Units: millimolar; Initial value: 1e-05
        double var_chaste_interface__fast_sodium_current_m_gate__m = rY[2];
        // Units: dimensionless; Initial value: 0.076
        double var_chaste_interface__fast_sodium_current_h_gate__h = rY[3];
        // Units: dimensionless; Initial value: 0.015
        double var_chaste_interface__second_inward_calcium_current_d_gate__d = rY[4];
        // Units: dimensionless; Initial value: 0.0011
        double var_chaste_interface__second_inward_calcium_current_f_Ca_gate__f_Ca = rY[5];
        // Units: dimensionless; Initial value: 0.785
        double var_chaste_interface__intracellular_sodium_concentration__Na_i = rY[8];
        // Units: millimolar; Initial value: 6.5
        double var_chaste_interface__extracellular_calcium_concentration__Ca_o = rY[9];
        // Units: millimolar; Initial value: 2.0
        double var_chaste_interface__intracellular_potassium_concentration__K_i = rY[10];
        // Units: millimolar; Initial value: 140.0
        
        const double var_Na_Ca_exchanger__i_NaCa = 0.01 * (-2744000.0 * var_chaste_interface__intracellular_calcium_concentration__Ca_i * exp(-0.018716945411372733 * var_chaste_interface__membrane__V) + pow(var_chaste_interface__intracellular_sodium_concentration__Na_i, 3.0) * var_chaste_interface__extracellular_calcium_concentration__Ca_o * exp(0.018716945411372733 * var_chaste_interface__membrane__V)) / ((1.0 + 144.92753623188406 * var_chaste_interface__intracellular_calcium_concentration__Ca_i) * (1.0 + 274.40000000000003 * var_chaste_interface__intracellular_calcium_concentration__Ca_i + 0.0001 * pow(var_chaste_interface__intracellular_sodium_concentration__Na_i, 3.0) * var_chaste_interface__extracellular_calcium_concentration__Ca_o)); // nanoA
        const double var_calcium_background_current__i_b_Ca = 0.0050000000000000001 * var_chaste_interface__membrane__V - 0.066784401649239128 * log(var_chaste_interface__extracellular_calcium_concentration__Ca_o / var_chaste_interface__intracellular_calcium_concentration__Ca_i); // nanoA
        const double var_fast_sodium_current__i_Na = 50.0 * pow(var_chaste_interface__fast_sodium_current_m_gate__m, 3.0) * (-26.713760659695652 * log(140.47999999999999 / (0.12 * var_chaste_interface__intracellular_potassium_concentration__K_i + var_chaste_interface__intracellular_sodium_concentration__Na_i)) + var_chaste_interface__membrane__V) * var_chaste_interface__fast_sodium_current_h_gate__h; // nanoA
        const double var_second_inward_calcium_current_f_Ca_gate__CaChon = (1.0 - var_chaste_interface__second_inward_calcium_current_f_Ca_gate__f_Ca) * (1.0 - var_chaste_interface__intracellular_calcium_concentration__Ca_i / (0.001 + var_chaste_interface__intracellular_calcium_concentration__Ca_i)); // dimensionless
        const double var_second_inward_calcium_current__i_si = 0.74867781645490927 * (-50.0 + var_chaste_interface__membrane__V) * (var_chaste_interface__intracellular_calcium_concentration__Ca_i * exp(3.7433890822745468) - var_chaste_interface__extracellular_calcium_concentration__Ca_o * exp(3.7433890822745468 - 0.074867781645490933 * var_chaste_interface__membrane__V)) * var_chaste_interface__second_inward_calcium_current_d_gate__d * var_second_inward_calcium_current_f_Ca_gate__CaChon / (1.0 - exp(3.7433890822745468 - 0.074867781645490933 * var_chaste_interface__membrane__V)) + 0.00037433890822745466 * (-50.0 + var_chaste_interface__membrane__V) * (-4.0 * exp(1.8716945411372734 - 0.037433890822745466 * var_chaste_interface__membrane__V) + var_chaste_interface__intracellular_potassium_concentration__K_i * exp(1.8716945411372734)) * var_chaste_interface__second_inward_calcium_current_d_gate__d * var_second_inward_calcium_current_f_Ca_gate__CaChon / (1.0 - exp(1.8716945411372734 - 0.037433890822745466 * var_chaste_interface__membrane__V)) + 0.0018716945411372734 * (-50.0 + var_chaste_interface__membrane__V) * (-140.0 * exp(1.8716945411372734 - 0.037433890822745466 * var_chaste_interface__membrane__V) + var_chaste_interface__intracellular_sodium_concentration__Na_i * exp(1.8716945411372734)) * var_chaste_interface__second_inward_calcium_current_d_gate__d * var_second_inward_calcium_current_f_Ca_gate__CaChon / (1.0 - exp(1.8716945411372734 - 0.037433890822745466 * var_chaste_interface__membrane__V)); // nanoA
        const double var_sodium_background_current__i_b_Na = 0.012 * var_chaste_interface__membrane__V - 0.32056512791634784 * log(140.0 / var_chaste_interface__intracellular_sodium_concentration__Na_i); // nanoA
        const double var_sodium_potassium_pump__i_NaK = 11.200000000000001 * var_chaste_interface__intracellular_sodium_concentration__Na_i / (40.0 + var_chaste_interface__intracellular_sodium_concentration__Na_i); // nanoA
        const double var_time_independent_potassium_current__E_K = 26.713760659695652 * log(4.0 / var_chaste_interface__intracellular_potassium_concentration__K_i); // millivolt
        const double var_potassium_background_current__i_b_K = 0.17000000000000001 * var_chaste_interface__membrane__V - 0.17000000000000001 * var_time_independent_potassium_current__E_K; // nanoA
        const double var_time_independent_potassium_current__i_K1 = 0.48571428571428565 * (-var_time_independent_potassium_current__E_K + var_chaste_interface__membrane__V) / (1.0 + exp(-0.74867781645490927 + 0.074867781645490933 * var_chaste_interface__membrane__V - 0.074867781645490933 * var_time_independent_potassium_current__E_K)); // nanoA
        const double var_chaste_interface__i_ionic = 166.66666666666666 * (0.001 * var_Na_Ca_exchanger__i_NaCa + 0.001 * var_calcium_background_current__i_b_Ca + 0.001 * var_fast_sodium_current__i_Na + 0.001 * var_potassium_background_current__i_b_K + 0.001 * var_second_inward_calcium_current__i_si + 0.001 * var_sodium_background_current__i_b_Na + 0.001 * var_sodium_potassium_pump__i_NaK + 0.001 * var_time_independent_potassium_current__i_K1) * HeartConfig::Instance()->GetCapacitance(); // uA_per_cm2

        const double i_ionic = var_chaste_interface__i_ionic;
        EXCEPT_IF_NOT(!std::isnan(i_ionic));
        return i_ionic;
    }

    void Cellhilgemann_noble_model_1987FromCellML::EvaluateYDerivatives(double var_chaste_interface__environment__time_converted, const std::vector<double>& rY, std::vector<double>& rDY)
    {
        // Inputs:
        // Time units: millisecond
        double var_chaste_interface__membrane__V = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : rY[0]);
        // Units: millivolt; Initial value: -88.0
        double var_chaste_interface__intracellular_calcium_concentration__Ca_i = rY[1];
        // Units: millimolar; Initial value: 1e-05
        double var_chaste_interface__fast_sodium_current_m_gate__m = rY[2];
        // Units: dimensionless; Initial value: 0.076
        double var_chaste_interface__fast_sodium_current_h_gate__h = rY[3];
        // Units: dimensionless; Initial value: 0.015
        double var_chaste_interface__second_inward_calcium_current_d_gate__d = rY[4];
        // Units: dimensionless; Initial value: 0.0011
        double var_chaste_interface__second_inward_calcium_current_f_Ca_gate__f_Ca = rY[5];
        // Units: dimensionless; Initial value: 0.785
        double var_chaste_interface__calcium_release__ActFrac = rY[6];
        // Units: dimensionless; Initial value: 0.0
        double var_chaste_interface__calcium_release__ProdFrac = rY[7];
        // Units: dimensionless; Initial value: 0.0
        double var_chaste_interface__intracellular_sodium_concentration__Na_i = rY[8];
        // Units: millimolar; Initial value: 6.5
        double var_chaste_interface__extracellular_calcium_concentration__Ca_o = rY[9];
        // Units: millimolar; Initial value: 2.0
        double var_chaste_interface__intracellular_potassium_concentration__K_i = rY[10];
        // Units: millimolar; Initial value: 140.0
        double var_chaste_interface__intracellular_calcium_concentration__Ca_up = rY[11];
        // Units: millimolar; Initial value: 0.3
        double var_chaste_interface__intracellular_calcium_concentration__Ca_rel = rY[12];
        // Units: millimolar; Initial value: 0.3
        double var_chaste_interface__intracellular_calcium_concentration__Ca_Calmod = rY[13];
        // Units: millimolar; Initial value: 0.0005
        double var_chaste_interface__intracellular_calcium_concentration__Ca_Trop = rY[14];
        // Units: millimolar; Initial value: 0.0015

        // Mathematics
        double d_dt_chaste_interface_var_membrane__V;
        const double var_calcium_release__RegBindSite = pow((var_chaste_interface__intracellular_calcium_concentration__Ca_i / (0.00050000000000000001 + var_chaste_interface__intracellular_calcium_concentration__Ca_i)), 2.0); // dimensionless
        const double var_calcium_release__InactRate = 60.0 + 500.0 * var_calcium_release__RegBindSite; // per_second
        const double d_dt_chaste_interface_var_calcium_release__ProdFrac = -0.00059999999999999995 * var_chaste_interface__calcium_release__ProdFrac + 0.001 * var_chaste_interface__calcium_release__ActFrac * var_calcium_release__InactRate; // 1 / millisecond
        const double var_calcium_release__i_rel = 250.0 * pow((var_chaste_interface__calcium_release__ActFrac / (0.25 + var_chaste_interface__calcium_release__ActFrac)), 2.0) * var_chaste_interface__intracellular_calcium_concentration__Ca_rel; // millimolar_per_second
        const double var_calcium_translocation__i_trans = 50.0 * var_chaste_interface__intracellular_calcium_concentration__Ca_up - 50.0 * var_chaste_interface__intracellular_calcium_concentration__Ca_rel; // millimolar_per_second
        const double d_dt_chaste_interface_var_intracellular_calcium_concentration__Ca_rel = 0.0001 * var_calcium_translocation__i_trans - 0.001 * var_calcium_release__i_rel; // millimolar / millisecond
        const double var_intracellular_calcium_concentration__Ca_Calmod_orig_deriv = -50.0 * var_chaste_interface__intracellular_calcium_concentration__Ca_Calmod + 100000.0 * (0.02 - var_chaste_interface__intracellular_calcium_concentration__Ca_Calmod) * var_chaste_interface__intracellular_calcium_concentration__Ca_i; // millimolar / second
        const double d_dt_chaste_interface_var_intracellular_calcium_concentration__Ca_Calmod = 0.001 * var_intracellular_calcium_concentration__Ca_Calmod_orig_deriv; // millimolar / millisecond
        const double var_intracellular_calcium_concentration__Ca_Trop_orig_deriv = -200.0 * var_chaste_interface__intracellular_calcium_concentration__Ca_Trop + 100000.0 * (0.14999999999999999 - var_chaste_interface__intracellular_calcium_concentration__Ca_Trop) * var_chaste_interface__intracellular_calcium_concentration__Ca_i; // millimolar / second
        const double d_dt_chaste_interface_var_intracellular_calcium_concentration__Ca_Trop = 0.001 * var_intracellular_calcium_concentration__Ca_Trop_orig_deriv; // millimolar / millisecond
        const double var_Na_Ca_exchanger__i_NaCa = 0.01 * (-2744000.0 * var_chaste_interface__intracellular_calcium_concentration__Ca_i * exp(-0.018716945411372733 * var_chaste_interface__membrane__V) + pow(var_chaste_interface__intracellular_sodium_concentration__Na_i, 3.0) * var_chaste_interface__extracellular_calcium_concentration__Ca_o * exp(0.018716945411372733 * var_chaste_interface__membrane__V)) / ((1.0 + 144.92753623188406 * var_chaste_interface__intracellular_calcium_concentration__Ca_i) * (1.0 + 274.40000000000003 * var_chaste_interface__intracellular_calcium_concentration__Ca_i + 0.0001 * pow(var_chaste_interface__intracellular_sodium_concentration__Na_i, 3.0) * var_chaste_interface__extracellular_calcium_concentration__Ca_o)); // nanoA
        const double var_calcium_background_current__i_b_Ca = 0.0050000000000000001 * var_chaste_interface__membrane__V - 0.066784401649239128 * log(var_chaste_interface__extracellular_calcium_concentration__Ca_o / var_chaste_interface__intracellular_calcium_concentration__Ca_i); // nanoA
        const double d_dt_chaste_interface_var_calcium_release__ActFrac = 0.001 * (600.0 * exp(-3.2000000000000002 + 0.080000000000000002 * var_chaste_interface__membrane__V) + 500.0 * var_calcium_release__RegBindSite) * (1.0 - var_chaste_interface__calcium_release__ActFrac - var_chaste_interface__calcium_release__ProdFrac) - 0.001 * var_chaste_interface__calcium_release__ActFrac * var_calcium_release__InactRate; // 1 / millisecond
        const double var_fast_sodium_current__i_Na = 50.0 * pow(var_chaste_interface__fast_sodium_current_m_gate__m, 3.0) * (-26.713760659695652 * log(140.47999999999999 / (0.12 * var_chaste_interface__intracellular_potassium_concentration__K_i + var_chaste_interface__intracellular_sodium_concentration__Na_i)) + var_chaste_interface__membrane__V) * var_chaste_interface__fast_sodium_current_h_gate__h; // nanoA
        const double d_dt_chaste_interface_var_fast_sodium_current_h_gate__h = 0.02 * (1.0 - var_chaste_interface__fast_sodium_current_h_gate__h) * exp(-9.375 - 0.125 * var_chaste_interface__membrane__V) - 2.0 * var_chaste_interface__fast_sodium_current_h_gate__h / (1.0 + 320.0 * exp(-7.5 - 0.10000000000000001 * var_chaste_interface__membrane__V)); // 1 / millisecond
        const double d_dt_chaste_interface_var_fast_sodium_current_m_gate__m = 0.001 * (1.0 - var_chaste_interface__fast_sodium_current_m_gate__m) * ((fabs(41.0 + var_chaste_interface__membrane__V) < 1.0000000000000001e-5) ? (2000.0) : (200.0 * (41.0 + var_chaste_interface__membrane__V) / (1.0 - exp(-4.1000000000000005 - 0.10000000000000001 * var_chaste_interface__membrane__V)))) - 8.0 * var_chaste_interface__fast_sodium_current_m_gate__m * exp(-3.6960000000000002 - 0.056000000000000001 * var_chaste_interface__membrane__V); // 1 / millisecond
        const double var_sarcoplasmic_reticulum_calcium_pump__i_up = 3.0 * var_chaste_interface__intracellular_calcium_concentration__Ca_i / (0.00041999999999999996 + 0.00023999999999999998 * var_chaste_interface__intracellular_calcium_concentration__Ca_up + var_chaste_interface__intracellular_calcium_concentration__Ca_i) - 5.52e-5 * var_chaste_interface__intracellular_calcium_concentration__Ca_up / (0.00041999999999999996 + 0.00023999999999999998 * var_chaste_interface__intracellular_calcium_concentration__Ca_up + var_chaste_interface__intracellular_calcium_concentration__Ca_i); // millimolar_per_second
        const double d_dt_chaste_interface_var_intracellular_calcium_concentration__Ca_up = 0.048999999999999995 * var_sarcoplasmic_reticulum_calcium_pump__i_up - 0.001 * var_calcium_translocation__i_trans; // millimolar / millisecond
        const double var_second_inward_calcium_current_d_gate__E0_d = 19.0 + var_chaste_interface__membrane__V; // millivolt
        const double d_dt_chaste_interface_var_second_inward_calcium_current_d_gate__d = 0.001 * (1.0 - var_chaste_interface__second_inward_calcium_current_d_gate__d) * ((fabs(var_second_inward_calcium_current_d_gate__E0_d) < 0.0001) ? (120.0) : (30.0 * var_second_inward_calcium_current_d_gate__E0_d / (1.0 - exp(-0.25 * var_second_inward_calcium_current_d_gate__E0_d)))) - 0.001 * ((fabs(var_second_inward_calcium_current_d_gate__E0_d) < 0.0001) ? (120.0) : (12.0 * var_second_inward_calcium_current_d_gate__E0_d / (-1.0 + exp(0.10000000000000001 * var_second_inward_calcium_current_d_gate__E0_d)))) * var_chaste_interface__second_inward_calcium_current_d_gate__d; // 1 / millisecond
        const double var_second_inward_calcium_current_f_Ca_gate__CaChoff = var_chaste_interface__intracellular_calcium_concentration__Ca_i / (0.001 + var_chaste_interface__intracellular_calcium_concentration__Ca_i); // dimensionless
        const double var_second_inward_calcium_current_f_Ca_gate__E0_f = 34.0 + var_chaste_interface__membrane__V; // millivolt
        const double var_second_inward_calcium_current_f_Ca_gate__CaChon = (1.0 - var_second_inward_calcium_current_f_Ca_gate__CaChoff) * (1.0 - var_chaste_interface__second_inward_calcium_current_f_Ca_gate__f_Ca); // dimensionless
        const double var_second_inward_calcium_current__i_siCa = 0.74867781645490927 * (-50.0 + var_chaste_interface__membrane__V) * (var_chaste_interface__intracellular_calcium_concentration__Ca_i * exp(3.7433890822745468) - var_chaste_interface__extracellular_calcium_concentration__Ca_o * exp(3.7433890822745468 - 0.074867781645490933 * var_chaste_interface__membrane__V)) * var_chaste_interface__second_inward_calcium_current_d_gate__d * var_second_inward_calcium_current_f_Ca_gate__CaChon / (1.0 - exp(3.7433890822745468 - 0.074867781645490933 * var_chaste_interface__membrane__V)); // nanoA
        const double d_dt_chaste_interface_var_extracellular_calcium_concentration__Ca_o = 9.9999999999999995e-7 - 4.9999999999999998e-7 * var_chaste_interface__extracellular_calcium_concentration__Ca_o - 8.0543192715385057e-6 * var_Na_Ca_exchanger__i_NaCa - 8.0543192715385057e-6 * var_calcium_background_current__i_b_Ca - 8.0543192715385057e-6 * var_second_inward_calcium_current__i_siCa; // millimolar / millisecond
        const double d_dt_chaste_interface_var_intracellular_calcium_concentration__Ca_i = 1.3149909014756744e-5 * var_Na_Ca_exchanger__i_NaCa + 0.00020408163265306126 * var_calcium_release__i_rel - 0.001 * var_intracellular_calcium_concentration__Ca_Calmod_orig_deriv - 0.001 * var_intracellular_calcium_concentration__Ca_Trop_orig_deriv - 0.001 * var_sarcoplasmic_reticulum_calcium_pump__i_up - 6.5749545073783721e-6 * var_calcium_background_current__i_b_Ca - 6.5749545073783721e-6 * var_second_inward_calcium_current__i_siCa; // millimolar / millisecond
        const double var_second_inward_calcium_current__i_siK = 0.00037433890822745466 * (-50.0 + var_chaste_interface__membrane__V) * (-4.0 * exp(1.8716945411372734 - 0.037433890822745466 * var_chaste_interface__membrane__V) + var_chaste_interface__intracellular_potassium_concentration__K_i * exp(1.8716945411372734)) * var_chaste_interface__second_inward_calcium_current_d_gate__d * var_second_inward_calcium_current_f_Ca_gate__CaChon / (1.0 - exp(1.8716945411372734 - 0.037433890822745466 * var_chaste_interface__membrane__V)); // nanoA
        const double var_second_inward_calcium_current__i_siNa = 0.0018716945411372734 * (-50.0 + var_chaste_interface__membrane__V) * (-140.0 * exp(1.8716945411372734 - 0.037433890822745466 * var_chaste_interface__membrane__V) + var_chaste_interface__intracellular_sodium_concentration__Na_i * exp(1.8716945411372734)) * var_chaste_interface__second_inward_calcium_current_d_gate__d * var_second_inward_calcium_current_f_Ca_gate__CaChon / (1.0 - exp(1.8716945411372734 - 0.037433890822745466 * var_chaste_interface__membrane__V)); // nanoA
        const double d_dt_chaste_interface_var_second_inward_calcium_current_f_Ca_gate__f_Ca = 0.012 * ((1.0 - var_second_inward_calcium_current_f_Ca_gate__CaChoff) * (1.0 - var_chaste_interface__second_inward_calcium_current_f_Ca_gate__f_Ca) + 120.0 * (1.0 - var_chaste_interface__second_inward_calcium_current_f_Ca_gate__f_Ca) * var_second_inward_calcium_current_f_Ca_gate__CaChoff) / (1.0 + exp(-0.25 * var_second_inward_calcium_current_f_Ca_gate__E0_f)) - 0.001 * ((fabs(var_second_inward_calcium_current_f_Ca_gate__E0_f) < 0.0001) ? (25.0) : (6.25 * var_second_inward_calcium_current_f_Ca_gate__E0_f / (-1.0 + exp(0.25 * var_second_inward_calcium_current_f_Ca_gate__E0_f)))) * var_chaste_interface__second_inward_calcium_current_f_Ca_gate__f_Ca; // 1 / millisecond
        const double var_sodium_background_current__i_b_Na = 0.012 * var_chaste_interface__membrane__V - 0.32056512791634784 * log(140.0 / var_chaste_interface__intracellular_sodium_concentration__Na_i); // nanoA
        const double var_sodium_potassium_pump__i_NaK = 11.200000000000001 * var_chaste_interface__intracellular_sodium_concentration__Na_i / (40.0 + var_chaste_interface__intracellular_sodium_concentration__Na_i); // nanoA
        const double d_dt_chaste_interface_var_intracellular_sodium_concentration__Na_i = -1.3149909014756744e-5 * var_fast_sodium_current__i_Na - 1.3149909014756744e-5 * var_second_inward_calcium_current__i_siNa - 1.3149909014756744e-5 * var_sodium_background_current__i_b_Na - 3.9449727044270235e-5 * var_Na_Ca_exchanger__i_NaCa - 3.9449727044270235e-5 * var_sodium_potassium_pump__i_NaK; // millimolar / millisecond
        const double var_time_independent_potassium_current__E_K = 26.713760659695652 * log(4.0 / var_chaste_interface__intracellular_potassium_concentration__K_i); // millivolt
        const double var_potassium_background_current__i_b_K = 0.17000000000000001 * var_chaste_interface__membrane__V - 0.17000000000000001 * var_time_independent_potassium_current__E_K; // nanoA
        const double var_time_independent_potassium_current__i_K1 = 0.48571428571428565 * (-var_time_independent_potassium_current__E_K + var_chaste_interface__membrane__V) / (1.0 + exp(-0.74867781645490927 + 0.074867781645490933 * var_chaste_interface__membrane__V - 0.074867781645490933 * var_time_independent_potassium_current__E_K)); // nanoA
        const double d_dt_chaste_interface_var_intracellular_potassium_concentration__K_i = 2.6299818029513489e-5 * var_sodium_potassium_pump__i_NaK - 1.3149909014756744e-5 * var_potassium_background_current__i_b_K - 1.3149909014756744e-5 * var_second_inward_calcium_current__i_siK - 1.3149909014756744e-5 * var_time_independent_potassium_current__i_K1; // millimolar / millisecond

        if (mSetVoltageDerivativeToZero)
        {
            d_dt_chaste_interface_var_membrane__V = 0.0;
        }
        else
        {
            d_dt_chaste_interface_var_membrane__V = -0.16666666666666666 * var_Na_Ca_exchanger__i_NaCa - 0.16666666666666666 * var_calcium_background_current__i_b_Ca - 0.16666666666666666 * var_fast_sodium_current__i_Na - 0.16666666666666666 * var_potassium_background_current__i_b_K - 0.16666666666666666 * var_second_inward_calcium_current__i_siCa - 0.16666666666666666 * var_second_inward_calcium_current__i_siK - 0.16666666666666666 * var_second_inward_calcium_current__i_siNa - 0.16666666666666666 * var_sodium_background_current__i_b_Na - 0.16666666666666666 * var_sodium_potassium_pump__i_NaK - 0.16666666666666666 * var_time_independent_potassium_current__i_K1 - 1.0 * GetIntracellularAreaStimulus(var_chaste_interface__environment__time_converted) / HeartConfig::Instance()->GetCapacitance(); // millivolt / millisecond
        }
        
        rDY[0] = d_dt_chaste_interface_var_membrane__V;
        rDY[1] = d_dt_chaste_interface_var_intracellular_calcium_concentration__Ca_i;
        rDY[2] = d_dt_chaste_interface_var_fast_sodium_current_m_gate__m;
        rDY[3] = d_dt_chaste_interface_var_fast_sodium_current_h_gate__h;
        rDY[4] = d_dt_chaste_interface_var_second_inward_calcium_current_d_gate__d;
        rDY[5] = d_dt_chaste_interface_var_second_inward_calcium_current_f_Ca_gate__f_Ca;
        rDY[6] = d_dt_chaste_interface_var_calcium_release__ActFrac;
        rDY[7] = d_dt_chaste_interface_var_calcium_release__ProdFrac;
        rDY[8] = d_dt_chaste_interface_var_intracellular_sodium_concentration__Na_i;
        rDY[9] = d_dt_chaste_interface_var_extracellular_calcium_concentration__Ca_o;
        rDY[10] = d_dt_chaste_interface_var_intracellular_potassium_concentration__K_i;
        rDY[11] = d_dt_chaste_interface_var_intracellular_calcium_concentration__Ca_up;
        rDY[12] = d_dt_chaste_interface_var_intracellular_calcium_concentration__Ca_rel;
        rDY[13] = d_dt_chaste_interface_var_intracellular_calcium_concentration__Ca_Calmod;
        rDY[14] = d_dt_chaste_interface_var_intracellular_calcium_concentration__Ca_Trop;
    }

template<>
void OdeSystemInformation<Cellhilgemann_noble_model_1987FromCellML>::Initialise(void)
{
    this->mSystemName = "hilgemann_noble_model_1987";
    this->mFreeVariableName = "environment__time_converted";
    this->mFreeVariableUnits = "millisecond";

    // rY[0]:
    this->mVariableNames.push_back("membrane_voltage");
    this->mVariableUnits.push_back("millivolt");
    this->mInitialConditions.push_back(-88.0);

    // rY[1]:
    this->mVariableNames.push_back("cytosolic_calcium_concentration");
    this->mVariableUnits.push_back("millimolar");
    this->mInitialConditions.push_back(1e-05);

    // rY[2]:
    this->mVariableNames.push_back("fast_sodium_current_m_gate__m");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.076);

    // rY[3]:
    this->mVariableNames.push_back("fast_sodium_current_h_gate__h");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.015);

    // rY[4]:
    this->mVariableNames.push_back("second_inward_calcium_current_d_gate__d");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.0011);

    // rY[5]:
    this->mVariableNames.push_back("second_inward_calcium_current_f_Ca_gate__f_Ca");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.785);

    // rY[6]:
    this->mVariableNames.push_back("calcium_release__ActFrac");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.0);

    // rY[7]:
    this->mVariableNames.push_back("calcium_release__ProdFrac");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.0);

    // rY[8]:
    this->mVariableNames.push_back("intracellular_sodium_concentration__Na_i");
    this->mVariableUnits.push_back("millimolar");
    this->mInitialConditions.push_back(6.5);

    // rY[9]:
    this->mVariableNames.push_back("extracellular_calcium_concentration__Ca_o");
    this->mVariableUnits.push_back("millimolar");
    this->mInitialConditions.push_back(2.0);

    // rY[10]:
    this->mVariableNames.push_back("intracellular_potassium_concentration__K_i");
    this->mVariableUnits.push_back("millimolar");
    this->mInitialConditions.push_back(140.0);

    // rY[11]:
    this->mVariableNames.push_back("intracellular_calcium_concentration__Ca_up");
    this->mVariableUnits.push_back("millimolar");
    this->mInitialConditions.push_back(0.3);

    // rY[12]:
    this->mVariableNames.push_back("intracellular_calcium_concentration__Ca_rel");
    this->mVariableUnits.push_back("millimolar");
    this->mInitialConditions.push_back(0.3);

    // rY[13]:
    this->mVariableNames.push_back("intracellular_calcium_concentration__Ca_Calmod");
    this->mVariableUnits.push_back("millimolar");
    this->mInitialConditions.push_back(0.0005);

    // rY[14]:
    this->mVariableNames.push_back("intracellular_calcium_concentration__Ca_Trop");
    this->mVariableUnits.push_back("millimolar");
    this->mInitialConditions.push_back(0.0015);

    this->mInitialised = true;
}


// Serialization for Boost >= 1.36
#include "SerializationExportWrapperForCpp.hpp"
CHASTE_CLASS_EXPORT(Cellhilgemann_noble_model_1987FromCellML)

