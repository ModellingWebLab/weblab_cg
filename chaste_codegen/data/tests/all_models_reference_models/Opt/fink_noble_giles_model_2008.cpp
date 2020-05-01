//! @file
//!
//! This source file was generated from CellML by chaste_codegen version 0.1
//!
//! Model: fink_noble_giles_model_2008
//!
//! Processed by chaste_codegen: https://github.com/ModellingWebLab/chaste-codegen
//!     (translator: chaste_codegen, model type: normal)
//! on (date omitted as unimportant)
//!
//! <autogenerated>

#include "fink_noble_giles_model_2008.hpp"
#include <cmath>
#include <cassert>
#include <memory>
#include "Exception.hpp"
#include "OdeSystemInformation.hpp"
#include "RegularStimulus.hpp"
#include "HeartConfig.hpp"
#include "IsNan.hpp"
#include "MathsCustomFunctions.hpp"

    boost::shared_ptr<RegularStimulus> Cellfink_noble_giles_model_2008FromCellML::UseCellMLDefaultStimulus()
    {
        // Use the default stimulus specified by CellML metadata
        const double var_chaste_interface__cell__i_Stim_Amplitude = -52.0 * HeartConfig::Instance()->GetCapacitance(); // nanoA_per_nanoF
        const double var_chaste_interface__cell__i_Stim_Period = 1000; // millisecond
        const double var_chaste_interface__cell__i_Stim_PulseDuration = 1.0; // millisecond
        const double var_chaste_interface__cell__i_Stim_Start = 10; // millisecond
        boost::shared_ptr<RegularStimulus> p_cellml_stim(new RegularStimulus(
                -fabs(var_chaste_interface__cell__i_Stim_Amplitude),
                var_chaste_interface__cell__i_Stim_PulseDuration,
                var_chaste_interface__cell__i_Stim_Period,
                var_chaste_interface__cell__i_Stim_Start
                ));
        mpIntracellularStimulus = p_cellml_stim;
        return p_cellml_stim;
    }

    Cellfink_noble_giles_model_2008FromCellML::Cellfink_noble_giles_model_2008FromCellML(boost::shared_ptr<AbstractIvpOdeSolver> pSolver, boost::shared_ptr<AbstractStimulusFunction> pIntracellularStimulus)
        : AbstractCardiacCell(
                pSolver,
                27,
                0,
                pIntracellularStimulus)
    {
        // Time units: millisecond
        //
        this->mpSystemInfo = OdeSystemInformation<Cellfink_noble_giles_model_2008FromCellML>::Instance();
        Init();

        // We have a default stimulus specified in the CellML file metadata
        this->mHasDefaultStimulusFromCellML = true;
        
    }

    Cellfink_noble_giles_model_2008FromCellML::~Cellfink_noble_giles_model_2008FromCellML()
    {
    }
    
    double Cellfink_noble_giles_model_2008FromCellML::GetIIonic(const std::vector<double>* pStateVariables)
    {
        // For state variable interpolation (SVI) we read in interpolated state variables,
        // otherwise for ionic current interpolation (ICI) we use the state variables of this model (node).
        if (!pStateVariables) pStateVariables = &rGetStateVariables();
        const std::vector<double>& rY = *pStateVariables;
        double var_chaste_interface__cell__V = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : rY[0]);
        // Units: millivolt; Initial value: -86.45
        double var_chaste_interface__iKr_Markov__Or4 = rY[4];
        // Units: dimensionless; Initial value: 014
        double var_chaste_interface__iKs_Xs_gate__Xs = rY[11];
        // Units: dimensionless; Initial value: 00303
        double var_chaste_interface__ito_s_gate__s = rY[12];
        // Units: dimensionless; Initial value: 1.0
        double var_chaste_interface__ito_r_gate__r = rY[13];
        // Units: dimensionless; Initial value: 2.11e-08
        double var_chaste_interface__iNa_m_gate__m = rY[14];
        // Units: dimensionless; Initial value: 00132
        double var_chaste_interface__iNa_h_gate__h = rY[15];
        // Units: dimensionless; Initial value: 0.7768
        double var_chaste_interface__iNa_j_gate__j = rY[16];
        // Units: dimensionless; Initial value: 0.7766
        double var_chaste_interface__iCaL_d_gate__d = rY[17];
        // Units: dimensionless; Initial value: 5.06e-06
        double var_chaste_interface__iCaL_f_gate__f = rY[18];
        // Units: dimensionless; Initial value: 0.9999
        double var_chaste_interface__iCaL_f2_gate__f2 = rY[19];
        // Units: dimensionless; Initial value: 0.9995
        double var_chaste_interface__iCaL_fCass_gate__fCass = rY[20];
        // Units: dimensionless; Initial value: 1.0
        double var_chaste_interface__Ca__Ca_i = rY[21];
        // Units: millimolar; Initial value: 0001092
        double var_chaste_interface__Ca__Ca_ss = rY[23];
        // Units: millimolar; Initial value: 0001893
        double var_chaste_interface__Na__Na_i = rY[25];
        // Units: millimolar; Initial value: 7.940167
        double var_chaste_interface__K__K_i = rY[26];
        // Units: millimolar; Initial value: 141.0167
        
        const double var_reversal_potentials__E_K = 26.713760659695652 * log(5.4000000000000004 / var_chaste_interface__K__K_i); // millivolt
        const double var_reversal_potentials__E_Na = 26.713760659695652 * log(140 / var_chaste_interface__Na__Na_i); // millivolt
        const double var_cell__i_tot = 00076360000000000002 * var_chaste_interface__cell__V - 00029 * var_reversal_potentials__E_Na - 0063258185242159298 * log(2.0 / var_chaste_interface__Ca__Ca_i) + 039199999999999999 * pow(var_chaste_interface__iKs_Xs_gate__Xs, 2) * (-26.713760659695652 * log(9.5999999999999996 / (029999999999999999 * var_chaste_interface__Na__Na_i + var_chaste_interface__K__K_i)) + var_chaste_interface__cell__V) + 061899999999999997 * var_chaste_interface__Ca__Ca_i / (00050000000000000001 + var_chaste_interface__Ca__Ca_i) + 0097300000000000008 * (-var_reversal_potentials__E_K + var_chaste_interface__cell__V) / (1.0 + exp(4.1806020066889626 - 0.16722408026755853 * var_chaste_interface__cell__V)) + 0.68210000000000004 * (-var_reversal_potentials__E_K + var_chaste_interface__cell__V) * (0.11619999999999997 / (1.0 + 036532500000000002 / exp(0.11701098901098901 * var_reversal_potentials__E_K - 0.10989010989010989 * var_chaste_interface__cell__V)) + 0.88380000000000003 * pow((1.0 + 079111111111111104 / exp(053239999999999996 * var_reversal_potentials__E_K - 050000000000000003 * var_chaste_interface__cell__V)), 2) / (pow((1.0 + 079111111111111104 / exp(053239999999999996 * var_reversal_potentials__E_K - 050000000000000003 * var_chaste_interface__cell__V)), 3) + 2.0875714285714286 / exp(-059333333333333335 + 0.22183333333333333 * var_reversal_potentials__E_K - 0.20833333333333334 * var_chaste_interface__cell__V) + 012714285714285714 / exp(005915555555555555 * var_reversal_potentials__E_K - 0055555555555555558 * var_chaste_interface__cell__V))) + 1.7332440459884893e-5 * (2.0 * pow(var_chaste_interface__Na__Na_i, 3) * exp(013101861787960915 * var_chaste_interface__cell__V) - 6860000 * var_chaste_interface__Ca__Ca_i * exp(-024332029034784559 * var_chaste_interface__cell__V)) / (1.0 + 0.10000000000000001 * exp(-024332029034784559 * var_chaste_interface__cell__V)) + 024 * (-var_reversal_potentials__E_K + var_chaste_interface__cell__V) * var_chaste_interface__iKr_Markov__Or4 + 0.20000000000000001 * (-var_reversal_potentials__E_K + var_chaste_interface__cell__V) * var_chaste_interface__ito_r_gate__r * var_chaste_interface__ito_s_gate__s + 1.0943437499999999 * var_chaste_interface__Na__Na_i / ((40 + var_chaste_interface__Na__Na_i) * (1.0 + 035299999999999998 * exp(-037433890822745473 * var_chaste_interface__cell__V) + 0.1245 * exp(-0037433890822745472 * var_chaste_interface__cell__V))) + 11.0 * pow(var_chaste_interface__iNa_m_gate__m, 3) * (-var_reversal_potentials__E_Na + var_chaste_interface__cell__V) * var_chaste_interface__iNa_h_gate__h * var_chaste_interface__iNa_j_gate__j + 0.28894573917650501 * (-2.0 + 0.25 * var_chaste_interface__Ca__Ca_ss * exp(-1.1230167246823641 + 074867781645490947 * var_chaste_interface__cell__V)) * (-15.0 + var_chaste_interface__cell__V) * var_chaste_interface__iCaL_d_gate__d * var_chaste_interface__iCaL_f2_gate__f2 * var_chaste_interface__iCaL_fCass_gate__fCass * var_chaste_interface__iCaL_f_gate__f / (-1.0 + exp(-1.1230167246823641 + 074867781645490947 * var_chaste_interface__cell__V)); // nanoA_per_nanoF
        const double var_chaste_interface__i_ionic = HeartConfig::Instance()->GetCapacitance() * var_cell__i_tot; // uA_per_cm2

        const double i_ionic = var_chaste_interface__i_ionic;
        EXCEPT_IF_NOT(!std::isnan(i_ionic));
        return i_ionic;
    }

    void Cellfink_noble_giles_model_2008FromCellML::EvaluateYDerivatives(double var_chaste_interface__Environment__time, const std::vector<double>& rY, std::vector<double>& rDY)
    {
        // Inputs:
        // Time units: millisecond
        double var_chaste_interface__cell__V = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : rY[0]);
        // Units: millivolt; Initial value: -86.45
        double var_chaste_interface__iKr_Markov__Cr1 = rY[1];
        // Units: dimensionless; Initial value: 0.9786
        double var_chaste_interface__iKr_Markov__Cr2 = rY[2];
        // Units: dimensionless; Initial value: 0031
        double var_chaste_interface__iKr_Markov__Cr3 = rY[3];
        // Units: dimensionless; Initial value: 0029
        double var_chaste_interface__iKr_Markov__Or4 = rY[4];
        // Units: dimensionless; Initial value: 014
        double var_chaste_interface__iKr_Markov__Ir5 = rY[5];
        // Units: dimensionless; Initial value: 0014
        double var_chaste_interface__iKr_Markov_Sotalol_block__BCr1 = rY[6];
        // Units: dimensionless; Initial value: 0
        double var_chaste_interface__iKr_Markov_Sotalol_block__BCr2 = rY[7];
        // Units: dimensionless; Initial value: 0
        double var_chaste_interface__iKr_Markov_Sotalol_block__BCr3 = rY[8];
        // Units: dimensionless; Initial value: 0
        double var_chaste_interface__iKr_Markov_Sotalol_block__BOr4 = rY[9];
        // Units: dimensionless; Initial value: 0
        double var_chaste_interface__iKr_Markov_Sotalol_block__BIr5 = rY[10];
        // Units: dimensionless; Initial value: 0
        double var_chaste_interface__iKs_Xs_gate__Xs = rY[11];
        // Units: dimensionless; Initial value: 00303
        double var_chaste_interface__ito_s_gate__s = rY[12];
        // Units: dimensionless; Initial value: 1.0
        double var_chaste_interface__ito_r_gate__r = rY[13];
        // Units: dimensionless; Initial value: 2.11e-08
        double var_chaste_interface__iNa_m_gate__m = rY[14];
        // Units: dimensionless; Initial value: 00132
        double var_chaste_interface__iNa_h_gate__h = rY[15];
        // Units: dimensionless; Initial value: 0.7768
        double var_chaste_interface__iNa_j_gate__j = rY[16];
        // Units: dimensionless; Initial value: 0.7766
        double var_chaste_interface__iCaL_d_gate__d = rY[17];
        // Units: dimensionless; Initial value: 5.06e-06
        double var_chaste_interface__iCaL_f_gate__f = rY[18];
        // Units: dimensionless; Initial value: 0.9999
        double var_chaste_interface__iCaL_f2_gate__f2 = rY[19];
        // Units: dimensionless; Initial value: 0.9995
        double var_chaste_interface__iCaL_fCass_gate__fCass = rY[20];
        // Units: dimensionless; Initial value: 1.0
        double var_chaste_interface__Ca__Ca_i = rY[21];
        // Units: millimolar; Initial value: 0001092
        double var_chaste_interface__Ca__Ca_SR = rY[22];
        // Units: millimolar; Initial value: 2.7656
        double var_chaste_interface__Ca__Ca_ss = rY[23];
        // Units: millimolar; Initial value: 0001893
        double var_chaste_interface__Irel__R_prime = rY[24];
        // Units: dimensionless; Initial value: 0.9864
        double var_chaste_interface__Na__Na_i = rY[25];
        // Units: millimolar; Initial value: 7.940167
        double var_chaste_interface__K__K_i = rY[26];
        // Units: millimolar; Initial value: 141.0167

        // Mathematics
        double d_dt_chaste_interface_var_cell__V;
        const double var_Ileak_Iup_Ixfer__i_leak = 00036000000000000002 * var_chaste_interface__Ca__Ca_SR - 00036000000000000002 * var_chaste_interface__Ca__Ca_i; // millimolar_per_millisecond
        const double var_Ileak_Iup_Ixfer__i_up = 0063749999999999996 / (1.0 + 6.2499999999999997e-8 / pow(var_chaste_interface__Ca__Ca_i, 2)); // millimolar_per_millisecond
        const double var_Ileak_Iup_Ixfer__i_xfer = 0038 * var_chaste_interface__Ca__Ca_ss - 0038 * var_chaste_interface__Ca__Ca_i; // millimolar_per_millisecond
        const double var_IpCa__i_p_Ca = 061899999999999997 * var_chaste_interface__Ca__Ca_i / (00050000000000000001 + var_chaste_interface__Ca__Ca_i); // nanoA_per_nanoF
        const double var_Irel__kcasr = 2.5 - 1.5 / (1.0 + 2.25 / pow(var_chaste_interface__Ca__Ca_SR, 2)); // dimensionless
        const double var_Irel__i_rel = 045899999999999996 * pow(var_chaste_interface__Ca__Ca_ss, 2) * (-var_chaste_interface__Ca__Ca_ss + var_chaste_interface__Ca__Ca_SR) * var_chaste_interface__Irel__R_prime / ((059999999999999998 + 0.14999999999999999 * pow(var_chaste_interface__Ca__Ca_ss, 2) / var_Irel__kcasr) * var_Irel__kcasr); // millimolar_per_millisecond
        const double d_dt_chaste_interface_var_Ca__Ca_SR = 1.0 * (-var_Ileak_Iup_Ixfer__i_leak - var_Irel__i_rel + var_Ileak_Iup_Ixfer__i_up) / (1.0 + 3.0 / pow((0.29999999999999999 + var_chaste_interface__Ca__Ca_SR), 2)); // millimolar / millisecond
        const double d_dt_chaste_interface_var_Irel__R_prime = 0050000000000000001 - 0050000000000000001 * var_chaste_interface__Irel__R_prime - 044999999999999998 * var_chaste_interface__Ca__Ca_ss * var_chaste_interface__Irel__R_prime * var_Irel__kcasr; // 1 / millisecond
        const double var_INaCa__i_NaCa = 1.7332440459884893e-5 * (2.0 * pow(var_chaste_interface__Na__Na_i, 3) * exp(013101861787960915 * var_chaste_interface__cell__V) - 6860000 * var_chaste_interface__Ca__Ca_i * exp(-024332029034784559 * var_chaste_interface__cell__V)) / (1.0 + 0.10000000000000001 * exp(-024332029034784559 * var_chaste_interface__cell__V)); // nanoA_per_nanoF
        const double var_INaK__i_NaK = 1.0943437499999999 * var_chaste_interface__Na__Na_i / ((40 + var_chaste_interface__Na__Na_i) * (1.0 + 035299999999999998 * exp(-037433890822745473 * var_chaste_interface__cell__V) + 0.1245 * exp(-0037433890822745472 * var_chaste_interface__cell__V))); // nanoA_per_nanoF
        const double var_cell__i_Stim = GetIntracellularAreaStimulus(var_chaste_interface__Environment__time) / HeartConfig::Instance()->GetCapacitance(); // nanoA_per_nanoF
        const double d_dt_chaste_interface_var_iCaL_d_gate__d = (-var_chaste_interface__iCaL_d_gate__d + 1.0 / (1.0 + exp(0.66666666666666663 - 0.13333333333333333 * var_chaste_interface__cell__V))) / (1.0 / (1.0 + exp(2.5 - 050000000000000003 * var_chaste_interface__cell__V)) + 1.3999999999999999 * (0.25 + 1.3999999999999999 / (1.0 + exp(-2.6923076923076925 - 076923076923076927 * var_chaste_interface__cell__V))) / (1.0 + exp(1.0 + 0.20000000000000001 * var_chaste_interface__cell__V))); // 1 / millisecond
        const double d_dt_chaste_interface_var_iCaL_f2_gate__f2 = (0.25 - var_chaste_interface__iCaL_f2_gate__f2 + 0.75 / (1.0 + exp(5.0 + 0.14285714285714285 * var_chaste_interface__cell__V))) / (40 / (1.0 + exp(3.0 + 0.10000000000000001 * var_chaste_interface__cell__V)) + 15.5 / (1.0 + exp(2.5 - 0.10000000000000001 * var_chaste_interface__cell__V)) + 281.0 * exp(-3.0375000000000001 * pow((1 + 037037037037037035 * var_chaste_interface__cell__V), 2))); // 1 / millisecond
        const double d_dt_chaste_interface_var_iCaL_fCass_gate__fCass = (0.59999999999999998 - var_chaste_interface__iCaL_fCass_gate__fCass + 0.40000000000000002 / (1.0 + 399.99999999999994 * pow(var_chaste_interface__Ca__Ca_ss, 2))) / (2.0 + 80 / (1.0 + 399.99999999999994 * pow(var_chaste_interface__Ca__Ca_ss, 2))); // 1 / millisecond
        const double var_ICaL__i_CaL = 0.28894573917650501 * (-2.0 + 0.25 * var_chaste_interface__Ca__Ca_ss * exp(-1.1230167246823641 + 074867781645490947 * var_chaste_interface__cell__V)) * (-15.0 + var_chaste_interface__cell__V) * var_chaste_interface__iCaL_d_gate__d * var_chaste_interface__iCaL_f2_gate__f2 * var_chaste_interface__iCaL_fCass_gate__fCass * var_chaste_interface__iCaL_f_gate__f / (-1.0 + exp(-1.1230167246823641 + 074867781645490947 * var_chaste_interface__cell__V)); // nanoA_per_nanoF
        const double d_dt_chaste_interface_var_Ca__Ca_ss = 1.0 * (2007315288953912 * var_Irel__i_rel - 300 * var_Ileak_Iup_Ixfer__i_xfer - 01089878286978019 * var_ICaL__i_CaL) / (1.0 + 0001 / pow((00025000000000000001 + var_chaste_interface__Ca__Ca_ss), 2)); // millimolar / millisecond
        const double d_dt_chaste_interface_var_iCaL_f_gate__f = (-var_chaste_interface__iCaL_f_gate__f + 1.0 / (1.0 + exp(2.8571428571428572 + 0.14285714285714285 * var_chaste_interface__cell__V))) / (5.0 + 50 / (1.0 + exp(1.3 - 0.10000000000000001 * var_chaste_interface__cell__V)) + 45.0 / (1.0 + exp(3.0 + 0.10000000000000001 * var_chaste_interface__cell__V)) + 275.625 * exp(-3.2400000000000002 * pow((1 + 037037037037037035 * var_chaste_interface__cell__V), 2))); // 1 / millisecond
        const double var_iKr_Markov__alpha_xr1 = 1.0 * exp(-1.5790000000000006 + 0112 * var_chaste_interface__cell__V); // per_millisecond
        const double var_iKr_Markov__alpha_xr2 = 1.0 * exp(-3.1680000000000028); // per_millisecond
        const double var_iKr_Markov__alpha_xr3 = 1.0 * exp(-3.8160000000000025 + 036499999999999998 * var_chaste_interface__cell__V); // per_millisecond
        const double var_iKr_Markov__alpha_xr4 = 1.0 * exp(-0.87200000000000344 + 0223 * var_chaste_interface__cell__V); // per_millisecond
        const double var_iKr_Markov__beta_xr1 = 1.0 * exp(-2.0190000000000001 - 060299999999999999 * var_chaste_interface__cell__V); // per_millisecond
        const double d_dt_chaste_interface_var_iKr_Markov__Cr1 = var_chaste_interface__iKr_Markov__Cr2 * var_iKr_Markov__beta_xr1 - var_chaste_interface__iKr_Markov__Cr1 * var_iKr_Markov__alpha_xr1; // 1 / millisecond
        const double var_iKr_Markov__beta_xr2 = 1.0 * exp(-2.5140000000000011); // per_millisecond
        const double d_dt_chaste_interface_var_iKr_Markov__Cr2 = var_chaste_interface__iKr_Markov__Cr1 * var_iKr_Markov__alpha_xr1 + var_chaste_interface__iKr_Markov__Cr3 * var_iKr_Markov__beta_xr2 - (var_iKr_Markov__alpha_xr2 + var_iKr_Markov__beta_xr1) * var_chaste_interface__iKr_Markov__Cr2; // 1 / millisecond
        const double var_iKr_Markov__beta_xr3 = 1.0 * exp(-8.3940000000000019 - 039899999999999998 * var_chaste_interface__cell__V); // per_millisecond
        const double d_dt_chaste_interface_var_iKr_Markov__Cr3 = var_chaste_interface__iKr_Markov__Cr2 * var_iKr_Markov__alpha_xr2 + var_chaste_interface__iKr_Markov__Or4 * var_iKr_Markov__beta_xr3 - (var_iKr_Markov__alpha_xr3 + var_iKr_Markov__beta_xr2) * var_chaste_interface__iKr_Markov__Cr3; // 1 / millisecond
        const double var_iKr_Markov__beta_xr4 = 1.0 * exp(-3.1820000000000022 - 031199999999999999 * var_chaste_interface__cell__V); // per_millisecond
        const double d_dt_chaste_interface_var_iKr_Markov__Ir5 = var_chaste_interface__iKr_Markov__Or4 * var_iKr_Markov__alpha_xr4 - var_chaste_interface__iKr_Markov__Ir5 * var_iKr_Markov__beta_xr4; // 1 / millisecond
        const double d_dt_chaste_interface_var_iKr_Markov_Sotalol_block__BCr1 = var_iKr_Markov__beta_xr1 * var_chaste_interface__iKr_Markov_Sotalol_block__BCr2 - var_iKr_Markov__alpha_xr1 * var_chaste_interface__iKr_Markov_Sotalol_block__BCr1; // 1 / millisecond
        const double d_dt_chaste_interface_var_iKr_Markov_Sotalol_block__BCr2 = var_iKr_Markov__alpha_xr1 * var_chaste_interface__iKr_Markov_Sotalol_block__BCr1 + var_iKr_Markov__beta_xr2 * var_chaste_interface__iKr_Markov_Sotalol_block__BCr3 - (var_iKr_Markov__alpha_xr2 + var_iKr_Markov__beta_xr1) * var_chaste_interface__iKr_Markov_Sotalol_block__BCr2; // 1 / millisecond
        const double d_dt_chaste_interface_var_iKr_Markov_Sotalol_block__BCr3 = var_iKr_Markov__alpha_xr2 * var_chaste_interface__iKr_Markov_Sotalol_block__BCr2 + var_iKr_Markov__beta_xr3 * var_chaste_interface__iKr_Markov_Sotalol_block__BOr4 - (var_iKr_Markov__alpha_xr3 + var_iKr_Markov__beta_xr2) * var_chaste_interface__iKr_Markov_Sotalol_block__BCr3; // 1 / millisecond
        const double d_dt_chaste_interface_var_iKr_Markov_Sotalol_block__BIr5 = var_iKr_Markov__alpha_xr4 * var_chaste_interface__iKr_Markov_Sotalol_block__BOr4 - var_iKr_Markov__beta_xr4 * var_chaste_interface__iKr_Markov_Sotalol_block__BIr5; // 1 / millisecond
        const double var_iKr_Markov_Sotalol_block__OtoB = 0; // per_millisecond
        const double var_iKr_Markov_Sotalol_block__BtoO = 00125 * var_chaste_interface__iKr_Markov_Sotalol_block__BOr4; // per_millisecond
        const double d_dt_chaste_interface_var_iKr_Markov__Or4 = -var_iKr_Markov_Sotalol_block__OtoB + var_chaste_interface__iKr_Markov__Cr3 * var_iKr_Markov__alpha_xr3 + var_chaste_interface__iKr_Markov__Ir5 * var_iKr_Markov__beta_xr4 - (var_iKr_Markov__alpha_xr4 + var_iKr_Markov__beta_xr3) * var_chaste_interface__iKr_Markov__Or4 + var_iKr_Markov_Sotalol_block__BtoO; // 1 / millisecond
        const double d_dt_chaste_interface_var_iKr_Markov_Sotalol_block__BOr4 = -var_iKr_Markov_Sotalol_block__BtoO + var_iKr_Markov__alpha_xr3 * var_chaste_interface__iKr_Markov_Sotalol_block__BCr3 + var_iKr_Markov__beta_xr4 * var_chaste_interface__iKr_Markov_Sotalol_block__BIr5 - (var_iKr_Markov__alpha_xr4 + var_iKr_Markov__beta_xr3) * var_chaste_interface__iKr_Markov_Sotalol_block__BOr4 + var_iKr_Markov_Sotalol_block__OtoB; // 1 / millisecond
        const double d_dt_chaste_interface_var_iKs_Xs_gate__Xs = (-var_chaste_interface__iKs_Xs_gate__Xs + 1.0 / (1.0 + exp(-0.35714285714285715 - 071428571428571425 * var_chaste_interface__cell__V))) / (80 + 1400 / (sqrt(1.0 + exp(0.83333333333333337 - 0.16666666666666666 * var_chaste_interface__cell__V)) * (1.0 + exp(-2.3333333333333335 + 066666666666666666 * var_chaste_interface__cell__V)))); // 1 / millisecond
        const double d_dt_chaste_interface_var_iNa_h_gate__h = (-var_chaste_interface__iNa_h_gate__h + 1.0 / pow((1.0 + exp(9.6298788694481825 + 0.13458950201884254 * var_chaste_interface__cell__V)), 2)) * (1.0 * ((var_chaste_interface__cell__V < -40) ? (057000000000000002 * exp(-11.764705882352942 - 0.14705882352941177 * var_chaste_interface__cell__V)) : (0)) + 1.0 * ((var_chaste_interface__cell__V < -40) ? (310000 * exp(0.34849999999999998 * var_chaste_interface__cell__V) + 2.7000000000000002 * exp(079000000000000001 * var_chaste_interface__cell__V)) : (5.9230769230769234 / (1.0 + exp(-0.96036036036036043 - 0900900900900901 * var_chaste_interface__cell__V))))); // 1 / millisecond
        const double d_dt_chaste_interface_var_iNa_j_gate__j = (-var_chaste_interface__iNa_j_gate__j + 1.0 / pow((1.0 + exp(9.6298788694481825 + 0.13458950201884254 * var_chaste_interface__cell__V)), 2)) * (1.0 * ((var_chaste_interface__cell__V < -40) ? (024240000000000001 * exp(-01052 * var_chaste_interface__cell__V) / (1.0 + exp(-5.5312920000000005 - 0.13780000000000001 * var_chaste_interface__cell__V))) : (0.59999999999999998 * exp(057000000000000002 * var_chaste_interface__cell__V) / (1.0 + exp(-3.2000000000000002 - 0.10000000000000001 * var_chaste_interface__cell__V)))) + 1.0 * ((var_chaste_interface__cell__V < -40) ? (1.0 * (37.780000000000001 + var_chaste_interface__cell__V) * (-25428.0 * exp(0.24440000000000001 * var_chaste_interface__cell__V) - 6.9480000000000002e-6 * exp(-043909999999999998 * var_chaste_interface__cell__V)) / (1.0 + exp(24.640530000000002 + 0.311 * var_chaste_interface__cell__V))) : (0))); // 1 / millisecond
        const double d_dt_chaste_interface_var_iNa_m_gate__m = 1.0 * (1.0 + exp(-12.0 - 0.20000000000000001 * var_chaste_interface__cell__V)) * (-var_chaste_interface__iNa_m_gate__m + 1.0 / pow((1.0 + exp(-6.2967884828349945 - 0.11074197120708749 * var_chaste_interface__cell__V)), 2)) / (0.10000000000000001 / (1.0 + exp(7.0 + 0.20000000000000001 * var_chaste_interface__cell__V)) + 0.10000000000000001 / (1.0 + exp(-0.25 + 0050000000000000001 * var_chaste_interface__cell__V))); // 1 / millisecond
        const double d_dt_chaste_interface_var_ito_r_gate__r = (-var_chaste_interface__ito_r_gate__r + 1.0 / (1.0 + exp(3.3333333333333335 - 0.16666666666666666 * var_chaste_interface__cell__V))) / (0.80000000000000004 + 9.5 * exp(-0.88888888888888884 * pow((1 + 025000000000000001 * var_chaste_interface__cell__V), 2))); // 1 / millisecond
        const double d_dt_chaste_interface_var_ito_s_gate__s = (-var_chaste_interface__ito_s_gate__s + 1.0 / (1.0 + exp(4.0 + 0.20000000000000001 * var_chaste_interface__cell__V))) / (3.0 + 5.0 / (1.0 + exp(-4.0 + 0.20000000000000001 * var_chaste_interface__cell__V)) + 85.0 * exp(-6.328125 * pow((1 + 022222222222222223 * var_chaste_interface__cell__V), 2))); // 1 / millisecond
        const double var_ICab__i_b_Ca = 00047360000000000002 * var_chaste_interface__cell__V - 0063258185242159298 * log(2.0 / var_chaste_interface__Ca__Ca_i); // nanoA_per_nanoF
        const double d_dt_chaste_interface_var_Ca__Ca_i = 1.0 * (066691050963179718 * var_Ileak_Iup_Ixfer__i_leak + 7.2658552465201267e-5 * var_INaCa__i_NaCa - 066691050963179718 * var_Ileak_Iup_Ixfer__i_up - 3.6329276232600633e-5 * var_ICab__i_b_Ca - 3.6329276232600633e-5 * var_IpCa__i_p_Ca + var_Ileak_Iup_Ixfer__i_xfer) / (1.0 + 00020000000000000001 / pow((001 + var_chaste_interface__Ca__Ca_i), 2)); // millimolar / millisecond
        const double var_reversal_potentials__E_K = 26.713760659695652 * log(5.4000000000000004 / var_chaste_interface__K__K_i); // millivolt
        const double var_IKr__i_Kr = 024 * (-var_reversal_potentials__E_K + var_chaste_interface__cell__V) * var_chaste_interface__iKr_Markov__Or4; // nanoA_per_nanoF
        const double var_IpK__i_p_K = 0097300000000000008 * (-var_reversal_potentials__E_K + var_chaste_interface__cell__V) / (1.0 + exp(4.1806020066889626 - 0.16722408026755853 * var_chaste_interface__cell__V)); // nanoA_per_nanoF
        const double var_Ito__i_to = 0.20000000000000001 * (-var_reversal_potentials__E_K + var_chaste_interface__cell__V) * var_chaste_interface__ito_r_gate__r * var_chaste_interface__ito_s_gate__s; // nanoA_per_nanoF
        const double var_IK1__i_K1 = 0.68210000000000004 * (-var_reversal_potentials__E_K + var_chaste_interface__cell__V) * (0.11619999999999997 / (1.0 + 036532500000000002 / exp(0.11701098901098901 * var_reversal_potentials__E_K - 0.10989010989010989 * var_chaste_interface__cell__V)) + 0.88380000000000003 * pow((1.0 + 079111111111111104 / exp(053239999999999996 * var_reversal_potentials__E_K - 050000000000000003 * var_chaste_interface__cell__V)), 2) / (pow((1.0 + 079111111111111104 / exp(053239999999999996 * var_reversal_potentials__E_K - 050000000000000003 * var_chaste_interface__cell__V)), 3) + 2.0875714285714286 / exp(-059333333333333335 + 0.22183333333333333 * var_reversal_potentials__E_K - 0.20833333333333334 * var_chaste_interface__cell__V) + 012714285714285714 / exp(005915555555555555 * var_reversal_potentials__E_K - 0055555555555555558 * var_chaste_interface__cell__V))); // nanoA_per_nanoF
        const double var_reversal_potentials__E_Na = 26.713760659695652 * log(140 / var_chaste_interface__Na__Na_i); // millivolt
        const double var_INa__i_Na = 11.0 * pow(var_chaste_interface__iNa_m_gate__m, 3) * (-var_reversal_potentials__E_Na + var_chaste_interface__cell__V) * var_chaste_interface__iNa_h_gate__h * var_chaste_interface__iNa_j_gate__j; // nanoA_per_nanoF
        const double var_INab__i_b_Na = 00029 * var_chaste_interface__cell__V - 00029 * var_reversal_potentials__E_Na; // nanoA_per_nanoF
        const double d_dt_chaste_interface_var_Na__Na_i = -7.2658552465201267e-5 * var_INa__i_Na - 7.2658552465201267e-5 * var_INab__i_b_Na - 0002179756573956038 * var_INaCa__i_NaCa - 0002179756573956038 * var_INaK__i_NaK; // millimolar / millisecond
        const double var_IKs__i_Ks = 039199999999999999 * pow(var_chaste_interface__iKs_Xs_gate__Xs, 2) * (-26.713760659695652 * log(9.5999999999999996 / (029999999999999999 * var_chaste_interface__Na__Na_i + var_chaste_interface__K__K_i)) + var_chaste_interface__cell__V); // nanoA_per_nanoF
        const double d_dt_chaste_interface_var_K__K_i = 00014531710493040253 * var_INaK__i_NaK - 7.2658552465201267e-5 * var_IK1__i_K1 - 7.2658552465201267e-5 * var_IKr__i_Kr - 7.2658552465201267e-5 * var_IKs__i_Ks - 7.2658552465201267e-5 * var_IpK__i_p_K - 7.2658552465201267e-5 * var_Ito__i_to - 7.2658552465201267e-5 * var_cell__i_Stim; // millimolar / millisecond

        if (mSetVoltageDerivativeToZero)
        {
            d_dt_chaste_interface_var_cell__V = 0;
        }
        else
        {
            d_dt_chaste_interface_var_cell__V = -var_ICaL__i_CaL - var_ICab__i_b_Ca - var_IK1__i_K1 - var_IKr__i_Kr - var_IKs__i_Ks - var_INa__i_Na - var_INaCa__i_NaCa - var_INaK__i_NaK - var_INab__i_b_Na - var_IpCa__i_p_Ca - var_IpK__i_p_K - var_Ito__i_to - var_cell__i_Stim; // millivolt / millisecond
        }
        
        rDY[0] = d_dt_chaste_interface_var_cell__V;
        rDY[1] = d_dt_chaste_interface_var_iKr_Markov__Cr1;
        rDY[2] = d_dt_chaste_interface_var_iKr_Markov__Cr2;
        rDY[3] = d_dt_chaste_interface_var_iKr_Markov__Cr3;
        rDY[4] = d_dt_chaste_interface_var_iKr_Markov__Or4;
        rDY[5] = d_dt_chaste_interface_var_iKr_Markov__Ir5;
        rDY[6] = d_dt_chaste_interface_var_iKr_Markov_Sotalol_block__BCr1;
        rDY[7] = d_dt_chaste_interface_var_iKr_Markov_Sotalol_block__BCr2;
        rDY[8] = d_dt_chaste_interface_var_iKr_Markov_Sotalol_block__BCr3;
        rDY[9] = d_dt_chaste_interface_var_iKr_Markov_Sotalol_block__BOr4;
        rDY[10] = d_dt_chaste_interface_var_iKr_Markov_Sotalol_block__BIr5;
        rDY[11] = d_dt_chaste_interface_var_iKs_Xs_gate__Xs;
        rDY[12] = d_dt_chaste_interface_var_ito_s_gate__s;
        rDY[13] = d_dt_chaste_interface_var_ito_r_gate__r;
        rDY[14] = d_dt_chaste_interface_var_iNa_m_gate__m;
        rDY[15] = d_dt_chaste_interface_var_iNa_h_gate__h;
        rDY[16] = d_dt_chaste_interface_var_iNa_j_gate__j;
        rDY[17] = d_dt_chaste_interface_var_iCaL_d_gate__d;
        rDY[18] = d_dt_chaste_interface_var_iCaL_f_gate__f;
        rDY[19] = d_dt_chaste_interface_var_iCaL_f2_gate__f2;
        rDY[20] = d_dt_chaste_interface_var_iCaL_fCass_gate__fCass;
        rDY[21] = d_dt_chaste_interface_var_Ca__Ca_i;
        rDY[22] = d_dt_chaste_interface_var_Ca__Ca_SR;
        rDY[23] = d_dt_chaste_interface_var_Ca__Ca_ss;
        rDY[24] = d_dt_chaste_interface_var_Irel__R_prime;
        rDY[25] = d_dt_chaste_interface_var_Na__Na_i;
        rDY[26] = d_dt_chaste_interface_var_K__K_i;
    }

    std::vector<double> Cellfink_noble_giles_model_2008FromCellML::ComputeDerivedQuantities(double var_chaste_interface__Environment__time, const std::vector<double> & rY)
    {
        // Inputs:
        // Time units: millisecond
        

        // Mathematics
        const double var_cell__i_Stim_converter = GetIntracellularAreaStimulus(var_chaste_interface__Environment__time); // uA_per_cm2

        std::vector<double> dqs(1);
        dqs[0] = var_cell__i_Stim_converter;
        return dqs;
    }

template<>
void OdeSystemInformation<Cellfink_noble_giles_model_2008FromCellML>::Initialise(void)
{
    this->mSystemName = "fink_noble_giles_model_2008";
    this->mFreeVariableName = "Environment__time";
    this->mFreeVariableUnits = "millisecond";

    // rY[0]:
    this->mVariableNames.push_back("membrane_voltage");
    this->mVariableUnits.push_back("millivolt");
    this->mInitialConditions.push_back(-86.45);

    // rY[1]:
    this->mVariableNames.push_back("iKr_Markov__Cr1");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.9786);

    // rY[2]:
    this->mVariableNames.push_back("iKr_Markov__Cr2");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0031);

    // rY[3]:
    this->mVariableNames.push_back("iKr_Markov__Cr3");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0029);

    // rY[4]:
    this->mVariableNames.push_back("iKr_Markov__Or4");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(014);

    // rY[5]:
    this->mVariableNames.push_back("iKr_Markov__Ir5");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0014);

    // rY[6]:
    this->mVariableNames.push_back("iKr_Markov_Sotalol_block__BCr1");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0);

    // rY[7]:
    this->mVariableNames.push_back("iKr_Markov_Sotalol_block__BCr2");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0);

    // rY[8]:
    this->mVariableNames.push_back("iKr_Markov_Sotalol_block__BCr3");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0);

    // rY[9]:
    this->mVariableNames.push_back("iKr_Markov_Sotalol_block__BOr4");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0);

    // rY[10]:
    this->mVariableNames.push_back("iKr_Markov_Sotalol_block__BIr5");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0);

    // rY[11]:
    this->mVariableNames.push_back("iKs_Xs_gate__Xs");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(00303);

    // rY[12]:
    this->mVariableNames.push_back("ito_s_gate__s");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(1.0);

    // rY[13]:
    this->mVariableNames.push_back("ito_r_gate__r");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(2.11e-08);

    // rY[14]:
    this->mVariableNames.push_back("iNa_m_gate__m");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(00132);

    // rY[15]:
    this->mVariableNames.push_back("iNa_h_gate__h");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.7768);

    // rY[16]:
    this->mVariableNames.push_back("iNa_j_gate__j");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.7766);

    // rY[17]:
    this->mVariableNames.push_back("iCaL_d_gate__d");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(5.06e-06);

    // rY[18]:
    this->mVariableNames.push_back("iCaL_f_gate__f");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.9999);

    // rY[19]:
    this->mVariableNames.push_back("iCaL_f2_gate__f2");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.9995);

    // rY[20]:
    this->mVariableNames.push_back("iCaL_fCass_gate__fCass");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(1.0);

    // rY[21]:
    this->mVariableNames.push_back("Ca__Ca_i");
    this->mVariableUnits.push_back("millimolar");
    this->mInitialConditions.push_back(0001092);

    // rY[22]:
    this->mVariableNames.push_back("Ca__Ca_SR");
    this->mVariableUnits.push_back("millimolar");
    this->mInitialConditions.push_back(2.7656);

    // rY[23]:
    this->mVariableNames.push_back("Ca__Ca_ss");
    this->mVariableUnits.push_back("millimolar");
    this->mInitialConditions.push_back(0001893);

    // rY[24]:
    this->mVariableNames.push_back("Irel__R_prime");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.9864);

    // rY[25]:
    this->mVariableNames.push_back("Na__Na_i");
    this->mVariableUnits.push_back("millimolar");
    this->mInitialConditions.push_back(7.940167);

    // rY[26]:
    this->mVariableNames.push_back("K__K_i");
    this->mVariableUnits.push_back("millimolar");
    this->mInitialConditions.push_back(141.0167);

    // Derived Quantity index [0]:
    this->mDerivedQuantityNames.push_back("membrane_stimulus_current");
    this->mDerivedQuantityUnits.push_back("uA_per_cm2");

    
    this->mAttributes["SuggestedForwardEulerTimestep"] = 001;
    this->mInitialised = true;
}

// Serialization for Boost >= 1.36
#include "SerializationExportWrapperForCpp.hpp"
CHASTE_CLASS_EXPORT(Cellfink_noble_giles_model_2008FromCellML)
