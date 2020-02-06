//! @file
//!
//! This source file was generated from CellML by chaste_codegen version 0.0.1
//!
//! Model: LivshitzRudy2007
//!
//! Processed by chaste_codegen: https://github.com/ModellingWebLab/chaste-codegen
//!     (translator: chaste_codegen, model type: normal)
//! on 2020-02-06 21:19:57
//!
//! <autogenerated>

#include "livshitz_rudy_2007.hpp"
#include <cmath>
#include <cassert>
#include <memory>
#include "Exception.hpp"
#include "OdeSystemInformation.hpp"
#include "RegularStimulus.hpp"
#include "HeartConfig.hpp"
#include "IsNan.hpp"
#include "MathsCustomFunctions.hpp"

    boost::shared_ptr<RegularStimulus> Celllivshitz_rudy_2007FromCellML::UseCellMLDefaultStimulus()
    {
        // Use the default stimulus specified by CellML metadata
        const double var_chaste_interface__cell__stim_amplitude = -15.0 * HeartConfig::Instance()->GetCapacitance(); // uA_per_uF
        const double var_chaste_interface__cell__stim_duration = 3.0; // millisecond
        const double var_chaste_interface__cell__stim_offset = 100.0; // millisecond
        const double var_chaste_interface__cell__stim_period = 400.0; // millisecond
        boost::shared_ptr<RegularStimulus> p_cellml_stim(new RegularStimulus(
                -fabs(var_chaste_interface__cell__stim_amplitude),
                var_chaste_interface__cell__stim_duration,
                var_chaste_interface__cell__stim_period,
                var_chaste_interface__cell__stim_offset
                ));
        mpIntracellularStimulus = p_cellml_stim;
        return p_cellml_stim;
    }

    Celllivshitz_rudy_2007FromCellML::Celllivshitz_rudy_2007FromCellML(boost::shared_ptr<AbstractIvpOdeSolver> pSolver, boost::shared_ptr<AbstractStimulusFunction> pIntracellularStimulus)
        : AbstractCardiacCell(
                pSolver,
                18,
                0,
                pIntracellularStimulus)
    {
        // Time units: millisecond
        //
        this->mpSystemInfo = OdeSystemInformation<Celllivshitz_rudy_2007FromCellML>::Instance();
        Init();

        // We have a default stimulus specified in the CellML file metadata
        this->mHasDefaultStimulusFromCellML = true;
        
    }

    Celllivshitz_rudy_2007FromCellML::~Celllivshitz_rudy_2007FromCellML()
    {
    }

    double Celllivshitz_rudy_2007FromCellML::GetIIonic(const std::vector<double>* pStateVariables)
    {
        // For state variable interpolation (SVI) we read in interpolated state variables,
        // otherwise for ionic current interpolation (ICI) we use the state variables of this model (node).
        if (!pStateVariables) pStateVariables = &rGetStateVariables();
        const std::vector<double>& rY = *pStateVariables;
        double var_chaste_interface__cell__V = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : rY[0]);
        // Units: mV; Initial value: -89.4356034692784
        double var_chaste_interface__INa__H = rY[1];
        // Units: dimensionless; Initial value: 0.994401369032678
        double var_chaste_interface__INa__m = rY[2];
        // Units: dimensionless; Initial value: 0.000734780346592185
        double var_chaste_interface__INa__J = rY[3];
        // Units: dimensionless; Initial value: 0.996100688673679
        double var_chaste_interface__ICaL__d = rY[4];
        // Units: dimensionless; Initial value: 3.2514786721066e-27
        double var_chaste_interface__ICaL__f = rY[5];
        // Units: dimensionless; Initial value: 0.997404948824816
        double var_chaste_interface__IKr__xr = rY[6];
        // Units: dimensionless; Initial value: 0.000162194715543637
        double var_chaste_interface__IKs__xs1 = rY[7];
        // Units: dimensionless; Initial value: 0.0285147332973946
        double var_chaste_interface__IKs__xs2 = rY[8];
        // Units: dimensionless; Initial value: 0.0764114040188678
        double var_chaste_interface__ICaT__b = rY[9];
        // Units: dimensionless; Initial value: 0.000927461915392873
        double var_chaste_interface__ICaT__g = rY[10];
        // Units: dimensionless; Initial value: 0.952834331760863
        double var_chaste_interface__Na__Na_i = rY[12];
        // Units: mM; Initial value: 16.612739313555
        double var_chaste_interface__K__K_i = rY[13];
        // Units: mM; Initial value: 139.730914103161
        double var_chaste_interface__Ca__Ca_T = rY[14];
        // Units: mM; Initial value: 0.0257059808595638
        
        const double var_Ca__Ca_i = -0.040960000000000003 + 0.33333333333333331 * var_chaste_interface__Ca__Ca_T + 0.66666666666666663 * sqrt(-0.00057837000000000014 + pow((0.12288000000000002 - var_chaste_interface__Ca__Ca_T), 2) + 0.0086400000000000001 * var_chaste_interface__Ca__Ca_T) * cos(0.33333333333333331 * acos(0.5 * pow((-0.00057837000000000014 + pow((0.12288000000000002 - var_chaste_interface__Ca__Ca_T), 2) + 0.0086400000000000001 * var_chaste_interface__Ca__Ca_T), (-1.5)) * (3.2129999999999999e-5 * var_chaste_interface__Ca__Ca_T - 2.0 * pow((0.12288000000000002 - var_chaste_interface__Ca__Ca_T), 3) + 9.0 * (0.00019279000000000003 - 0.0028800000000000002 * var_chaste_interface__Ca__Ca_T) * (0.12288000000000002 - var_chaste_interface__Ca__Ca_T)))); // mM
        const double var_ICaL__fca = 1.0 / (1.0 + 1666.6666666666667 * var_Ca__Ca_i); // dimensionless
        const double var_INaCa__inaca = 0.00025000000000000001 * (-2744000.0 * var_Ca__Ca_i + 1.8 * pow(var_chaste_interface__Na__Na_i, 3.0) * exp(0.037435883507802616 * var_chaste_interface__cell__V)) * exp(-0.031820500981632222 * var_chaste_interface__cell__V) / (1.0 + 0.0001 * (2744000.0 * var_Ca__Ca_i + 1.8 * pow(var_chaste_interface__Na__Na_i, 3.0) * exp(0.037435883507802616 * var_chaste_interface__cell__V)) * exp(-0.031820500981632222 * var_chaste_interface__cell__V)); // uA_per_uF
        const double var_INaK__inak = 1.6875 / ((1.0 + 100.0 * pow(1 / var_chaste_interface__Na__Na_i, 2.0)) * (1.0 + 0.1245 * exp(-0.0037435883507802616 * var_chaste_interface__cell__V) + 0.036499999999999998 * (-0.14285714285714285 + 0.14285714285714285 * exp(2.0802377414561666)) * exp(-0.037435883507802616 * var_chaste_interface__cell__V))); // uA_per_uF
        const double var_cell__caiont = 0.003016 * var_chaste_interface__cell__V - 2.0 * var_INaCa__inaca - 0.040282206767891383 * log(1.8 / var_Ca__Ca_i) + 1.1499999999999999 * var_Ca__Ca_i / (0.00050000000000000001 + var_Ca__Ca_i) + 0.050000000000000003 * pow(var_chaste_interface__ICaT__b, 2) * (-13.356169352749133 * log(1.8 / var_Ca__Ca_i) + var_chaste_interface__cell__V) * var_chaste_interface__ICaT__g + 7.8019226357407243 * (-0.61380000000000001 + 1.0 * var_Ca__Ca_i * exp(0.074871767015605231 * var_chaste_interface__cell__V)) * var_chaste_interface__ICaL__d * var_chaste_interface__ICaL__f * var_ICaL__fca * var_chaste_interface__cell__V / (-1.0 + exp(0.074871767015605231 * var_chaste_interface__cell__V)); // uA_per_uF
        const double var_reversal_potentials__EK = 26.712338705498265 * log(4.5 / var_chaste_interface__K__K_i); // mV
        const double var_reversal_potentials__ENa = 26.712338705498265 * log(140.0 / var_chaste_interface__Na__Na_i); // mV
        const double var_cell__naiont = 3.0 * var_INaCa__inaca + 3.0 * var_INaK__inak + 0.0040000000000000001 * var_chaste_interface__cell__V - 0.0040000000000000001 * var_reversal_potentials__ENa + 16.0 * pow(var_chaste_interface__INa__m, 3) * (-var_reversal_potentials__ENa + var_chaste_interface__cell__V) * var_chaste_interface__INa__H * var_chaste_interface__INa__J + 0.0024381008236689762 * (-105.0 + 0.75 * var_chaste_interface__Na__Na_i * exp(0.037435883507802616 * var_chaste_interface__cell__V)) * var_chaste_interface__ICaL__d * var_chaste_interface__ICaL__f * var_ICaL__fca * var_chaste_interface__cell__V / (-1.0 + exp(0.037435883507802616 * var_chaste_interface__cell__V)); // uA_per_uF
        const double var_cell__kiont = -2.0 * var_INaK__inak + 0.0055199999999999997 * (-var_reversal_potentials__EK + var_chaste_interface__cell__V) / (1.0 + exp(1.2521739130434781 - 0.16722408026755853 * var_chaste_interface__cell__V)) + 0.69834626081908668 * (-var_reversal_potentials__EK + var_chaste_interface__cell__V) / ((1.0 + exp(-14.1227775 + 0.23849999999999999 * var_chaste_interface__cell__V - 0.23849999999999999 * var_reversal_potentials__EK)) * (1.02 / (1.0 + exp(-14.1227775 + 0.23849999999999999 * var_chaste_interface__cell__V - 0.23849999999999999 * var_reversal_potentials__EK)) + (1.0 * exp(-36.698642499999998 + 0.061749999999999999 * var_chaste_interface__cell__V - 0.061749999999999999 * var_reversal_potentials__EK) + 0.49124000000000001 * exp(0.43983232 + 0.080320000000000003 * var_chaste_interface__cell__V - 0.080320000000000003 * var_reversal_potentials__EK)) / (1.0 + exp(-2.4444678999999998 + 0.51429999999999998 * var_reversal_potentials__EK - 0.51429999999999998 * var_chaste_interface__cell__V)))) + 0.023862446088641735 * (-var_reversal_potentials__EK + var_chaste_interface__cell__V) * var_chaste_interface__IKr__xr / (1.0 + exp(0.4017857142857143 + 0.044642857142857144 * var_chaste_interface__cell__V)) + (0.433 + 0.25979999999999998 / (1.0 + 6.4818210260626455e-7 * pow(1 / var_Ca__Ca_i, 1.3999999999999999))) * (-26.712338705498265 * log(7.0662000000000003 / (0.018329999999999999 * var_chaste_interface__Na__Na_i + var_chaste_interface__K__K_i)) + var_chaste_interface__cell__V) * var_chaste_interface__IKs__xs1 * var_chaste_interface__IKs__xs2 + 0.00069711623550831468 * (-3.375 + 0.75 * var_chaste_interface__K__K_i * exp(0.037435883507802616 * var_chaste_interface__cell__V)) * var_chaste_interface__ICaL__d * var_chaste_interface__ICaL__f * var_ICaL__fca * var_chaste_interface__cell__V / (-1.0 + exp(0.037435883507802616 * var_chaste_interface__cell__V)); // uA_per_uF
        const double var_chaste_interface__i_ionic = (var_cell__caiont + var_cell__kiont + var_cell__naiont) * HeartConfig::Instance()->GetCapacitance(); // uA_per_cm2

        const double i_ionic = var_chaste_interface__i_ionic;
        EXCEPT_IF_NOT(!std::isnan(i_ionic));
        return i_ionic;
    }

    void Celllivshitz_rudy_2007FromCellML::EvaluateYDerivatives(double var_chaste_interface__Environment__time, const std::vector<double>& rY, std::vector<double>& rDY)
    {
        // Inputs:
        // Time units: millisecond
        double var_chaste_interface__cell__V = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : rY[0]);
        // Units: mV; Initial value: -89.4356034692784
        double var_chaste_interface__INa__H = rY[1];
        // Units: dimensionless; Initial value: 0.994401369032678
        double var_chaste_interface__INa__m = rY[2];
        // Units: dimensionless; Initial value: 0.000734780346592185
        double var_chaste_interface__INa__J = rY[3];
        // Units: dimensionless; Initial value: 0.996100688673679
        double var_chaste_interface__ICaL__d = rY[4];
        // Units: dimensionless; Initial value: 3.2514786721066e-27
        double var_chaste_interface__ICaL__f = rY[5];
        // Units: dimensionless; Initial value: 0.997404948824816
        double var_chaste_interface__IKr__xr = rY[6];
        // Units: dimensionless; Initial value: 0.000162194715543637
        double var_chaste_interface__IKs__xs1 = rY[7];
        // Units: dimensionless; Initial value: 0.0285147332973946
        double var_chaste_interface__IKs__xs2 = rY[8];
        // Units: dimensionless; Initial value: 0.0764114040188678
        double var_chaste_interface__ICaT__b = rY[9];
        // Units: dimensionless; Initial value: 0.000927461915392873
        double var_chaste_interface__ICaT__g = rY[10];
        // Units: dimensionless; Initial value: 0.952834331760863
        double var_chaste_interface__Irel__Rel = rY[11];
        // Units: mM_per_ms; Initial value: 1.06874246141923e-23
        double var_chaste_interface__Na__Na_i = rY[12];
        // Units: mM; Initial value: 16.612739313555
        double var_chaste_interface__K__K_i = rY[13];
        // Units: mM; Initial value: 139.730914103161
        double var_chaste_interface__Ca__Ca_T = rY[14];
        // Units: mM; Initial value: 0.0257059808595638
        double var_chaste_interface__Ca__Ca_JSR_T = rY[15];
        // Units: mM; Initial value: 7.87371650296567
        double var_chaste_interface__Ca__Ca_NSR = rY[16];
        // Units: mM; Initial value: 2.71518235696672
        
        // Units: dimensionless; Initial value: 1e-12

        // Mathematics
        double d_dt_chaste_interface_var_cell__V;
        const double var_Ca__Ca_i = -0.040960000000000003 + 0.33333333333333331 * var_chaste_interface__Ca__Ca_T + 0.66666666666666663 * sqrt(-0.00057837000000000014 + pow((0.12288000000000002 - var_chaste_interface__Ca__Ca_T), 2) + 0.0086400000000000001 * var_chaste_interface__Ca__Ca_T) * cos(0.33333333333333331 * acos(0.5 * pow((-0.00057837000000000014 + pow((0.12288000000000002 - var_chaste_interface__Ca__Ca_T), 2) + 0.0086400000000000001 * var_chaste_interface__Ca__Ca_T), (-1.5)) * (3.2129999999999999e-5 * var_chaste_interface__Ca__Ca_T - 2.0 * pow((0.12288000000000002 - var_chaste_interface__Ca__Ca_T), 3) + 9.0 * (0.00019279000000000003 - 0.0028800000000000002 * var_chaste_interface__Ca__Ca_T) * (0.12288000000000002 - var_chaste_interface__Ca__Ca_T)))); // mM
        const double d_dt_chaste_interface_var_Ca__Over = 0.0; // 1 / ms
        const double var_ICaL__fca = 1.0 / (1.0 + 1666.6666666666667 * var_Ca__Ca_i); // dimensionless
        const double var_Irel__Ca_JSR_free = -5.4000000000000004 + 0.5 * var_chaste_interface__Ca__Ca_JSR_T + 5.4000000000000004 * sqrt(pow((1 - 0.092592592592592587 * var_chaste_interface__Ca__Ca_JSR_T), 2.0) + 0.027434842249657063 * var_chaste_interface__Ca__Ca_JSR_T); // mM
        const double var_Itr__itr = 0.0083333333333333332 * var_chaste_interface__Ca__Ca_NSR - 0.0083333333333333332 * var_Irel__Ca_JSR_free; // mM_per_ms
        const double d_dt_chaste_interface_var_Ca__Ca_JSR_T = -var_chaste_interface__Irel__Rel + var_Itr__itr; // mM / ms
        const double var_Iup_Ileak__iup = 0.0087500000000000008 * var_Ca__Ca_i / (0.00092000000000000003 + var_Ca__Ca_i); // mM_per_ms
        const double var_Iup_Ileak__ileak = 0.00058333333333333338 * var_chaste_interface__Ca__Ca_NSR; // mM_per_ms
        const double var_ICaL__dss0 = 1.0 / (1.0 + exp(-1.6025641025641024 - 0.16025641025641024 * var_chaste_interface__cell__V)); // dimensionless
        const double var_ICaL__ilca = 7.8019226357407243 * (-0.61380000000000001 + 1.0 * var_Ca__Ca_i * exp(0.074871767015605231 * var_chaste_interface__cell__V)) * var_chaste_interface__ICaL__d * var_chaste_interface__ICaL__f * var_ICaL__fca * var_chaste_interface__cell__V / (-1.0 + exp(0.074871767015605231 * var_chaste_interface__cell__V)); // uA_per_uF
        const double d_dt_chaste_interface_var_ICaL__d = 0.035000000000000003 * (10.0 + var_chaste_interface__cell__V) * (-var_chaste_interface__ICaL__d + 1.0 * var_ICaL__dss0 / (1.0 + exp(-2500.0 - 41.666666666666664 * var_chaste_interface__cell__V))) / ((1.0 - exp(-1.6025641025641024 - 0.16025641025641024 * var_chaste_interface__cell__V)) * var_ICaL__dss0); // 1 / ms
        const double d_dt_chaste_interface_var_ICaL__f = (0.02 + 0.019699999999999999 * exp(-0.113569 * pow((1 + 0.10000000000000001 * var_chaste_interface__cell__V), 2.0))) * (-var_chaste_interface__ICaL__f + 1.0 / (1.0 + exp(4.0 + 0.125 * var_chaste_interface__cell__V)) + 0.59999999999999998 / (1.0 + exp(2.5 - 0.050000000000000003 * var_chaste_interface__cell__V))); // 1 / ms
        const double d_dt_chaste_interface_var_ICaT__b = (-var_chaste_interface__ICaT__b + 1.0 / (1.0 + exp(-1.2962962962962963 - 0.092592592592592587 * var_chaste_interface__cell__V))) / (3.7000000000000002 + 6.0999999999999996 / (1.0 + exp(5.5555555555555554 + 0.22222222222222221 * var_chaste_interface__cell__V))); // 1 / ms
        const double d_dt_chaste_interface_var_ICaT__g = (-var_chaste_interface__ICaT__g + 1.0 / (1.0 + exp(10.714285714285715 + 0.17857142857142858 * var_chaste_interface__cell__V))) / (12.0 / (1.0 + exp(-416.66666666666669 * var_chaste_interface__cell__V)) + 1.0 * (1.0 - 1.0 / (1.0 + exp(-416.66666666666669 * var_chaste_interface__cell__V))) * (12.0 - 0.875 * var_chaste_interface__cell__V)); // 1 / ms
        const double d_dt_chaste_interface_var_IKr__xr = (-var_chaste_interface__IKr__xr + 1.0 / (1.0 + exp(-2.3729411764705883 - 0.23529411764705882 * var_chaste_interface__cell__V))) * (0.00060999999999999997 * (38.899999999999999 + var_chaste_interface__cell__V) / (-1.0 + exp(5.6404999999999994 + 0.14499999999999999 * var_chaste_interface__cell__V)) + 0.0013799999999999999 * (14.199999999999999 + var_chaste_interface__cell__V) / (1.0 - exp(-1.7465999999999999 - 0.123 * var_chaste_interface__cell__V))); // 1 / ms
        const double var_IKs__tauxs = 1.0 / (0.00013100000000000001 * (30.0 + var_chaste_interface__cell__V) / (-1.0 + exp(2.0609999999999999 + 0.068699999999999997 * var_chaste_interface__cell__V)) + 7.1899999999999999e-5 * (30.0 + var_chaste_interface__cell__V) / (1.0 - exp(-4.4399999999999995 - 0.14799999999999999 * var_chaste_interface__cell__V))); // ms
        const double var_IKs__xss = 1.0 / (1.0 + exp(0.089820359281437126 - 0.059880239520958084 * var_chaste_interface__cell__V)); // dimensionless
        const double d_dt_chaste_interface_var_IKs__xs1 = (-var_chaste_interface__IKs__xs1 + var_IKs__xss) / var_IKs__tauxs; // 1 / ms
        const double d_dt_chaste_interface_var_IKs__xs2 = 0.25 * (-var_chaste_interface__IKs__xs2 + var_IKs__xss) / var_IKs__tauxs; // 1 / ms
        const double var_INa__a = 1.0 - 1.0 / (1.0 + exp(-1666.6666666666667 - 41.666666666666664 * var_chaste_interface__cell__V)); // per_ms
        const double var_INa__aH = 0.13500000000000001 * var_INa__a * exp(-11.764705882352942 - 0.14705882352941177 * var_chaste_interface__cell__V); // per_ms
        const double var_INa__aj = 1.0 * (37.780000000000001 + var_chaste_interface__cell__V) * (-127140.0 * exp(0.24440000000000001 * var_chaste_interface__cell__V) - 3.4740000000000003e-5 * exp(-0.043909999999999998 * var_chaste_interface__cell__V)) * var_INa__a / (1.0 + exp(24.640530000000002 + 0.311 * var_chaste_interface__cell__V)); // per_ms
        const double var_INa__bH = (3.5600000000000001 * exp(0.079000000000000001 * var_chaste_interface__cell__V) + 310000.0 * exp(0.34999999999999998 * var_chaste_interface__cell__V)) * var_INa__a + 7.6923076923076916 * (1.0 - var_INa__a) / (1.0 + exp(-0.96036036036036043 - 0.0900900900900901 * var_chaste_interface__cell__V)); // per_ms
        const double var_INa__bj = 0.1212 * var_INa__a * exp(-0.01052 * var_chaste_interface__cell__V) / (1.0 + exp(-5.5312920000000005 - 0.13780000000000001 * var_chaste_interface__cell__V)) + 0.29999999999999999 * (1.0 - var_INa__a) * exp(-2.5349999999999999e-7 * var_chaste_interface__cell__V) / (1.0 + exp(-3.2000000000000002 - 0.10000000000000001 * var_chaste_interface__cell__V)); // per_ms
        const double d_dt_chaste_interface_var_INa__m = -0.080000000000000002 * var_chaste_interface__INa__m * exp(-0.090909090909090912 * var_chaste_interface__cell__V) + 0.32000000000000001 * (1.0 - var_chaste_interface__INa__m) * (47.130000000000003 + var_chaste_interface__cell__V) / (1.0 - exp(-4.7130000000000001 - 0.10000000000000001 * var_chaste_interface__cell__V)); // 1 / ms
        const double d_dt_chaste_interface_var_INa__H = (-var_chaste_interface__INa__H + 1.0 * var_INa__aH / (var_INa__aH + var_INa__bH)) * (1.0 * var_INa__aH + 1.0 * var_INa__bH); // 1 / ms
        const double d_dt_chaste_interface_var_INa__J = (-var_chaste_interface__INa__J + 1.0 * var_INa__aj / (var_INa__aj + var_INa__bj)) * (1.0 * var_INa__aj + 1.0 * var_INa__bj); // 1 / ms
        const double var_INaCa__inaca = 0.00025000000000000001 * (-2744000.0 * var_Ca__Ca_i + 1.8 * pow(var_chaste_interface__Na__Na_i, 3.0) * exp(0.037435883507802616 * var_chaste_interface__cell__V)) * exp(-0.031820500981632222 * var_chaste_interface__cell__V) / (1.0 + 0.0001 * (2744000.0 * var_Ca__Ca_i + 1.8 * pow(var_chaste_interface__Na__Na_i, 3.0) * exp(0.037435883507802616 * var_chaste_interface__cell__V)) * exp(-0.031820500981632222 * var_chaste_interface__cell__V)); // uA_per_uF
        const double var_INaK__inak = 1.6875 / ((1.0 + 100.0 * pow(1 / var_chaste_interface__Na__Na_i, 2.0)) * (1.0 + 0.1245 * exp(-0.0037435883507802616 * var_chaste_interface__cell__V) + 0.036499999999999998 * (-0.14285714285714285 + 0.14285714285714285 * exp(2.0802377414561666)) * exp(-0.037435883507802616 * var_chaste_interface__cell__V))); // uA_per_uF
        const double d_dt_chaste_interface_var_Irel__Rel = (0.21052631578947367 + 0.002589473684210526 / var_Irel__Ca_JSR_free) * (-var_chaste_interface__Irel__Rel - 0.59375 * var_ICaL__ilca / (1.0 + 1.0 * pow(1 / var_Irel__Ca_JSR_free, 9.0))); // mM_per_ms / ms
        const double var_cell__AF = 5.0619267243613002e-10 * M_PI; // uF_mole_per_C
        const double var_cell__vcell = 1.2100000000000001e-5 * M_PI; // uL
        const double var_cell__vjsr = 0.0047999999999999996 * var_cell__vcell; // uL
        const double var_cell__vmyo = 0.68000000000000005 * var_cell__vcell; // uL
        const double var_cell__vnsr = 0.055199999999999999 * var_cell__vcell; // uL
        const double d_dt_chaste_interface_var_Ca__Ca_NSR = -var_Iup_Ileak__ileak - var_Itr__itr * var_cell__vjsr / var_cell__vnsr + var_Iup_Ileak__iup; // mM / ms
        const double var_cell__caiont = 0.003016 * var_chaste_interface__cell__V - 2.0 * var_INaCa__inaca - 0.040282206767891383 * log(1.8 / var_Ca__Ca_i) + 1.1499999999999999 * var_Ca__Ca_i / (0.00050000000000000001 + var_Ca__Ca_i) + 0.050000000000000003 * pow(var_chaste_interface__ICaT__b, 2) * (-13.356169352749133 * log(1.8 / var_Ca__Ca_i) + var_chaste_interface__cell__V) * var_chaste_interface__ICaT__g + var_ICaL__ilca; // uA_per_uF
        const double d_dt_chaste_interface_var_Ca__Ca_T = (-var_Iup_Ileak__iup + var_Iup_Ileak__ileak) * var_cell__vnsr / var_cell__vmyo + var_chaste_interface__Irel__Rel * var_cell__vjsr / var_cell__vmyo - 0.5 * var_cell__AF * var_cell__caiont / var_cell__vmyo; // mM / ms
        const double var_reversal_potentials__EK = 26.712338705498265 * log(4.5 / var_chaste_interface__K__K_i); // mV
        const double var_reversal_potentials__ENa = 26.712338705498265 * log(140.0 / var_chaste_interface__Na__Na_i); // mV
        const double var_cell__naiont = 3.0 * var_INaCa__inaca + 3.0 * var_INaK__inak + 0.0040000000000000001 * var_chaste_interface__cell__V - 0.0040000000000000001 * var_reversal_potentials__ENa + 16.0 * pow(var_chaste_interface__INa__m, 3) * (-var_reversal_potentials__ENa + var_chaste_interface__cell__V) * var_chaste_interface__INa__H * var_chaste_interface__INa__J + 0.0024381008236689762 * (-105.0 + 0.75 * var_chaste_interface__Na__Na_i * exp(0.037435883507802616 * var_chaste_interface__cell__V)) * var_chaste_interface__ICaL__d * var_chaste_interface__ICaL__f * var_ICaL__fca * var_chaste_interface__cell__V / (-1.0 + exp(0.037435883507802616 * var_chaste_interface__cell__V)); // uA_per_uF
        const double d_dt_chaste_interface_var_Na__Na_i = -1.0 * var_cell__AF * var_cell__naiont / var_cell__vmyo; // mM / ms
        const double var_cell__kiont = -2.0 * var_INaK__inak + GetIntracellularAreaStimulus(var_chaste_interface__Environment__time) / HeartConfig::Instance()->GetCapacitance() + 0.0055199999999999997 * (-var_reversal_potentials__EK + var_chaste_interface__cell__V) / (1.0 + exp(1.2521739130434781 - 0.16722408026755853 * var_chaste_interface__cell__V)) + 0.69834626081908668 * (-var_reversal_potentials__EK + var_chaste_interface__cell__V) / ((1.0 + exp(-14.1227775 + 0.23849999999999999 * var_chaste_interface__cell__V - 0.23849999999999999 * var_reversal_potentials__EK)) * (1.02 / (1.0 + exp(-14.1227775 + 0.23849999999999999 * var_chaste_interface__cell__V - 0.23849999999999999 * var_reversal_potentials__EK)) + (1.0 * exp(-36.698642499999998 + 0.061749999999999999 * var_chaste_interface__cell__V - 0.061749999999999999 * var_reversal_potentials__EK) + 0.49124000000000001 * exp(0.43983232 + 0.080320000000000003 * var_chaste_interface__cell__V - 0.080320000000000003 * var_reversal_potentials__EK)) / (1.0 + exp(-2.4444678999999998 + 0.51429999999999998 * var_reversal_potentials__EK - 0.51429999999999998 * var_chaste_interface__cell__V)))) + 0.023862446088641735 * (-var_reversal_potentials__EK + var_chaste_interface__cell__V) * var_chaste_interface__IKr__xr / (1.0 + exp(0.4017857142857143 + 0.044642857142857144 * var_chaste_interface__cell__V)) + (0.433 + 0.25979999999999998 / (1.0 + 6.4818210260626455e-7 * pow(1 / var_Ca__Ca_i, 1.3999999999999999))) * (-26.712338705498265 * log(7.0662000000000003 / (0.018329999999999999 * var_chaste_interface__Na__Na_i + var_chaste_interface__K__K_i)) + var_chaste_interface__cell__V) * var_chaste_interface__IKs__xs1 * var_chaste_interface__IKs__xs2 + 0.00069711623550831468 * (-3.375 + 0.75 * var_chaste_interface__K__K_i * exp(0.037435883507802616 * var_chaste_interface__cell__V)) * var_chaste_interface__ICaL__d * var_chaste_interface__ICaL__f * var_ICaL__fca * var_chaste_interface__cell__V / (-1.0 + exp(0.037435883507802616 * var_chaste_interface__cell__V)); // uA_per_uF
        const double d_dt_chaste_interface_var_K__K_i = -1.0 * var_cell__AF * var_cell__kiont / var_cell__vmyo; // mM / ms

        if (mSetVoltageDerivativeToZero)
        {
            d_dt_chaste_interface_var_cell__V = 0.0;
        }
        else
        {
            d_dt_chaste_interface_var_cell__V = -var_cell__caiont - var_cell__kiont - var_cell__naiont; // mV / ms
        }
        
        rDY[0] = d_dt_chaste_interface_var_cell__V;
        rDY[1] = d_dt_chaste_interface_var_INa__H;
        rDY[2] = d_dt_chaste_interface_var_INa__m;
        rDY[3] = d_dt_chaste_interface_var_INa__J;
        rDY[4] = d_dt_chaste_interface_var_ICaL__d;
        rDY[5] = d_dt_chaste_interface_var_ICaL__f;
        rDY[6] = d_dt_chaste_interface_var_IKr__xr;
        rDY[7] = d_dt_chaste_interface_var_IKs__xs1;
        rDY[8] = d_dt_chaste_interface_var_IKs__xs2;
        rDY[9] = d_dt_chaste_interface_var_ICaT__b;
        rDY[10] = d_dt_chaste_interface_var_ICaT__g;
        rDY[11] = d_dt_chaste_interface_var_Irel__Rel;
        rDY[12] = d_dt_chaste_interface_var_Na__Na_i;
        rDY[13] = d_dt_chaste_interface_var_K__K_i;
        rDY[14] = d_dt_chaste_interface_var_Ca__Ca_T;
        rDY[15] = d_dt_chaste_interface_var_Ca__Ca_JSR_T;
        rDY[16] = d_dt_chaste_interface_var_Ca__Ca_NSR;
        rDY[17] = d_dt_chaste_interface_var_Ca__Over;
    }

template<>
void OdeSystemInformation<Celllivshitz_rudy_2007FromCellML>::Initialise(void)
{
    this->mSystemName = "LivshitzRudy2007";
    this->mFreeVariableName = "time";
    this->mFreeVariableUnits = "ms";

    // rY[0]:
    this->mVariableNames.push_back("membrane_voltage");
    this->mVariableUnits.push_back("mV");
    this->mInitialConditions.push_back(-89.4356034692784);

    // rY[1]:
    this->mVariableNames.push_back("membrane_fast_sodium_current_h_gate");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.994401369032678);

    // rY[2]:
    this->mVariableNames.push_back("membrane_fast_sodium_current_m_gate");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.000734780346592185);

    // rY[3]:
    this->mVariableNames.push_back("membrane_fast_sodium_current_j_gate");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.996100688673679);

    // rY[4]:
    this->mVariableNames.push_back("membrane_L_type_calcium_current_d_gate");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(3.2514786721066e-27);

    // rY[5]:
    this->mVariableNames.push_back("membrane_L_type_calcium_current_f_gate");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.997404948824816);

    // rY[6]:
    this->mVariableNames.push_back("IKr__xr");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.000162194715543637);

    // rY[7]:
    this->mVariableNames.push_back("IKs__xs1");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.0285147332973946);

    // rY[8]:
    this->mVariableNames.push_back("IKs__xs2");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.0764114040188678);

    // rY[9]:
    this->mVariableNames.push_back("ICaT__b");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.000927461915392873);

    // rY[10]:
    this->mVariableNames.push_back("ICaT__g");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.952834331760863);

    // rY[11]:
    this->mVariableNames.push_back("SR_release_current");
    this->mVariableUnits.push_back("mM_per_ms");
    this->mInitialConditions.push_back(1.06874246141923e-23);

    // rY[12]:
    this->mVariableNames.push_back("cytosolic_sodium_concentration");
    this->mVariableUnits.push_back("mM");
    this->mInitialConditions.push_back(16.612739313555);

    // rY[13]:
    this->mVariableNames.push_back("cytosolic_potassium_concentration");
    this->mVariableUnits.push_back("mM");
    this->mInitialConditions.push_back(139.730914103161);

    // rY[14]:
    this->mVariableNames.push_back("Ca__Ca_T");
    this->mVariableUnits.push_back("mM");
    this->mInitialConditions.push_back(0.0257059808595638);

    // rY[15]:
    this->mVariableNames.push_back("JSR_calcium_concentration");
    this->mVariableUnits.push_back("mM");
    this->mInitialConditions.push_back(7.87371650296567);

    // rY[16]:
    this->mVariableNames.push_back("Ca__Ca_NSR");
    this->mVariableUnits.push_back("mM");
    this->mInitialConditions.push_back(2.71518235696672);

    // rY[17]:
    this->mVariableNames.push_back("Ca__Over");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(1e-12);

    this->mInitialised = true;
}


// Serialization for Boost >= 1.36
#include "SerializationExportWrapperForCpp.hpp"
CHASTE_CLASS_EXPORT(Celllivshitz_rudy_2007FromCellML)

