//! @file
//!
//! This source file was generated from CellML by chaste_codegen version 0.0.1
//!
//! Model: zhang_SAN_model_2000_all
//!
//! Processed by chaste_codegen: https://github.com/ModellingWebLab/chaste-codegen
//!     (translator: chaste_codegen, model type: normal)
//! on (date omitted as unimportant)
//!
//! <autogenerated>

#include "zhang_SAN_model_2000_all.hpp"
#include <cmath>
#include <cassert>
#include <memory>
#include "Exception.hpp"
#include "OdeSystemInformation.hpp"
#include "RegularStimulus.hpp"
#include "HeartConfig.hpp"
#include "IsNan.hpp"
#include "MathsCustomFunctions.hpp"


    Cellzhang_SAN_model_2000_allFromCellMLRushLarsen::Cellzhang_SAN_model_2000_allFromCellMLRushLarsen(boost::shared_ptr<AbstractIvpOdeSolver> /* unused; should be empty */, boost::shared_ptr<AbstractStimulusFunction> pIntracellularStimulus)
        : AbstractRushLarsenCardiacCell(
                15,
                0,
                pIntracellularStimulus)
    {
        // Time units: millisecond
        // 
        this->mpSystemInfo = OdeSystemInformation<Cellzhang_SAN_model_2000_allFromCellMLRushLarsen>::Instance();
        Init();
        
    }

    Cellzhang_SAN_model_2000_allFromCellMLRushLarsen::~Cellzhang_SAN_model_2000_allFromCellMLRushLarsen()
    {
    }
    
    double Cellzhang_SAN_model_2000_allFromCellMLRushLarsen::GetIIonic(const std::vector<double>* pStateVariables)
    {
        // For state variable interpolation (SVI) we read in interpolated state variables,
        // otherwise for ionic current interpolation (ICI) we use the state variables of this model (node).
        if (!pStateVariables) pStateVariables = &rGetStateVariables();
        const std::vector<double>& rY = *pStateVariables;
        double var_chaste_interface__membrane__V = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : rY[0]);
        // Units: millivolt; Initial value: -39.013558536
        double var_chaste_interface__sodium_current_m_gate__m = rY[1];
        // Units: dimensionless; Initial value: 0.092361701692
        double var_chaste_interface__sodium_current_h_gate__h1 = rY[2];
        // Units: dimensionless; Initial value: 0.015905380261
        double var_chaste_interface__sodium_current_h_gate__h2 = rY[3];
        // Units: dimensionless; Initial value: 0.01445216109
        double var_chaste_interface__L_type_Ca_channel_d_gate__d_L = rY[4];
        // Units: dimensionless; Initial value: 0.04804900895
        double var_chaste_interface__L_type_Ca_channel_f_gate__f_L = rY[5];
        // Units: dimensionless; Initial value: 0.48779845203
        double var_chaste_interface__T_type_Ca_channel_d_gate__d_T = rY[6];
        // Units: dimensionless; Initial value: 0.42074047435
        double var_chaste_interface__T_type_Ca_channel_f_gate__f_T = rY[7];
        // Units: dimensionless; Initial value: 0.038968420558
        double var_chaste_interface__four_AP_sensitive_currents_q_gate__q = rY[8];
        // Units: dimensionless; Initial value: 0.29760539675
        double var_chaste_interface__four_AP_sensitive_currents_r_gate__r = rY[9];
        // Units: dimensionless; Initial value: 0.064402950262
        double var_chaste_interface__rapid_delayed_rectifying_potassium_current_P_af_gate__P_af = rY[10];
        // Units: dimensionless; Initial value: 0.13034201158
        double var_chaste_interface__rapid_delayed_rectifying_potassium_current_P_as_gate__P_as = rY[11];
        // Units: dimensionless; Initial value: 0.46960956028
        double var_chaste_interface__rapid_delayed_rectifying_potassium_current_P_i_gate__P_i = rY[12];
        // Units: dimensionless; Initial value: 0.87993375273
        double var_chaste_interface__slow_delayed_rectifying_potassium_current_xs_gate__xs = rY[13];
        // Units: dimensionless; Initial value: 0.082293827208
        double var_chaste_interface__hyperpolarisation_activated_current_y_gate__y = rY[14];
        // Units: dimensionless; Initial value: 0.03889291759
        
        const double var_membrane__FCell = 0; // dimensionless
        const double var_L_type_Ca_channel__i_Ca_L = (0.0057938 + 0.060092679999999996 * var_membrane__FCell) * (-46.399999999999999 + var_chaste_interface__membrane__V) * (0.0060000000000000001 / (1.0 + exp(-2.3500000000000001 - 0.16666666666666666 * var_chaste_interface__membrane__V)) + var_chaste_interface__L_type_Ca_channel_d_gate__d_L * var_chaste_interface__L_type_Ca_channel_f_gate__f_L); // nanoA
        const double var_T_type_Ca_channel__i_Ca_T = (0.0042780600000000002 + 0.00960424 * var_membrane__FCell) * (-45.0 + var_chaste_interface__membrane__V) * var_chaste_interface__T_type_Ca_channel_d_gate__d_T * var_chaste_interface__T_type_Ca_channel_f_gate__f_T; // nanoA
        const double var_persistent_calcium_current__i_Ca_p = 0; // nanoA
        const double var_calcium_background_current__i_b_Ca = (1.3236e-5 + 2.9715999999999998e-5 * var_membrane__FCell) * (-131.78096240721496 + var_chaste_interface__membrane__V); // nanoA
        const double var_four_AP_sensitive_currents__i_sus = (6.6455040000000003e-5 + 0.01131730496 * var_membrane__FCell) * (86.631929397420322 + var_chaste_interface__membrane__V) * var_chaste_interface__four_AP_sensitive_currents_r_gate__r; // nanoA
        const double var_four_AP_sensitive_currents__i_to = (0.0049049999999999996 + 0.03159 * var_membrane__FCell) * (86.631929397420322 + var_chaste_interface__membrane__V) * var_chaste_interface__four_AP_sensitive_currents_q_gate__q * var_chaste_interface__four_AP_sensitive_currents_r_gate__r; // nanoA
        const double var_hyperpolarisation_activated_current__i_f_K = (0.0005465 + 0.0063284999999999999 * var_membrane__FCell) * (86.631929397420322 + var_chaste_interface__membrane__V) * var_chaste_interface__hyperpolarisation_activated_current_y_gate__y; // nanoA
        const double var_potassium_background_current__i_b_K = (2.5236359999999998e-5 + 5.6655639999999996e-5 * var_membrane__FCell) * (86.631929397420322 + var_chaste_interface__membrane__V); // nanoA
        const double var_rapid_delayed_rectifying_potassium_current__i_K_r = (0.00079704000000000005 + 0.01520296 * var_membrane__FCell) * (86.631929397420322 + var_chaste_interface__membrane__V) * (0.40000000000000002 * var_chaste_interface__rapid_delayed_rectifying_potassium_current_P_as_gate__P_as + 0.59999999999999998 * var_chaste_interface__rapid_delayed_rectifying_potassium_current_P_af_gate__P_af) * var_chaste_interface__rapid_delayed_rectifying_potassium_current_P_i_gate__P_i; // nanoA
        const double var_hyperpolarisation_activated_current__i_f_Na = (0.0005465 + 0.0063284999999999999 * var_membrane__FCell) * (-76.171870705299767 + var_chaste_interface__membrane__V) * var_chaste_interface__hyperpolarisation_activated_current_y_gate__y; // nanoA
        const double var_slow_delayed_rectifying_potassium_current__i_K_s = pow(var_chaste_interface__slow_delayed_rectifying_potassium_current_xs_gate__xs, 2) * (0.00034450000000000003 + 0.0100555 * var_membrane__FCell) * (71.365322852196982 + var_chaste_interface__membrane__V); // nanoA
        const double var_sodium_background_current__i_b_Na = (5.8181799999999999e-5 + 0.0001306182 * var_membrane__FCell) * (-76.171870705299767 + var_chaste_interface__membrane__V); // nanoA
        const double var_sodium_calcium_exchanger__i_NaCa = 0.8850810734263258 * (2.7228999999999998e-6 + 6.1129400000000006e-6 * var_membrane__FCell) * (1024.0 * exp(0.018714999999999999 * var_chaste_interface__membrane__V) - 274.40000000000003 * exp(-0.018714999999999999 * var_chaste_interface__membrane__V)); // nanoA
        const double var_sodium_current__i_Na = 0.61339074024148932 * pow(var_chaste_interface__sodium_current_m_gate__m, 3) * (-1.0 + exp(-2.8622008809294686 + 0.037575562401545783 * var_chaste_interface__membrane__V)) * ((0.086929999999999993 + 0.095180000000000001 * exp(-2.1692640000000001 - 0.063060000000000005 * var_chaste_interface__membrane__V) / (1.0 + 1.6619999999999999 * exp(-14.33887 - 0.22509999999999999 * var_chaste_interface__membrane__V))) * var_chaste_interface__sodium_current_h_gate__h2 + (0.91307000000000005 - 0.095180000000000001 * exp(-2.1692640000000001 - 0.063060000000000005 * var_chaste_interface__membrane__V) / (1.0 + 1.6619999999999999 * exp(-14.33887 - 0.22509999999999999 * var_chaste_interface__membrane__V))) * var_chaste_interface__sodium_current_h_gate__h1) * var_membrane__FCell * var_chaste_interface__membrane__V / (-1.0 + exp(0.037575562401545783 * var_chaste_interface__membrane__V)); // nanoA
        const double var_sodium_potassium_pump__i_p = 0.25965524392018974 * (0.047825449999999999 + 0.10736815 * var_membrane__FCell) / (1.5 + exp(-1.5 - 0.025000000000000001 * var_chaste_interface__membrane__V)); // nanoA
        const double var_chaste_interface__i_ionic = (0.001 * var_L_type_Ca_channel__i_Ca_L + 0.001 * var_T_type_Ca_channel__i_Ca_T + 0.001 * var_calcium_background_current__i_b_Ca + 0.001 * var_four_AP_sensitive_currents__i_sus + 0.001 * var_four_AP_sensitive_currents__i_to + 0.001 * var_hyperpolarisation_activated_current__i_f_K + 0.001 * var_hyperpolarisation_activated_current__i_f_Na + 0.001 * var_persistent_calcium_current__i_Ca_p + 0.001 * var_potassium_background_current__i_b_K + 0.001 * var_rapid_delayed_rectifying_potassium_current__i_K_r + 0.001 * var_slow_delayed_rectifying_potassium_current__i_K_s + 0.001 * var_sodium_background_current__i_b_Na + 0.001 * var_sodium_calcium_exchanger__i_NaCa + 0.001 * var_sodium_current__i_Na + 0.001 * var_sodium_potassium_pump__i_p) * HeartConfig::Instance()->GetCapacitance(); // uA_per_cm2

        const double i_ionic = var_chaste_interface__i_ionic;
        EXCEPT_IF_NOT(!std::isnan(i_ionic));
        return i_ionic;
    }

    void Cellzhang_SAN_model_2000_allFromCellMLRushLarsen::EvaluateEquations(double var_chaste_interface__environment__time_converted, std::vector<double> &rDY, std::vector<double> &rAlphaOrTau, std::vector<double> &rBetaOrInf)
    {
        std::vector<double>& rY = rGetStateVariables();
        double var_chaste_interface__membrane__V = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : rY[0]);
        // Units: millivolt; Initial value: -39.013558536
        
        // Units: dimensionless; Initial value: 0.092361701692
        
        // Units: dimensionless; Initial value: 0.015905380261
        
        // Units: dimensionless; Initial value: 0.01445216109
        double var_chaste_interface__L_type_Ca_channel_d_gate__d_L = rY[4];
        // Units: dimensionless; Initial value: 0.04804900895
        double var_chaste_interface__L_type_Ca_channel_f_gate__f_L = rY[5];
        // Units: dimensionless; Initial value: 0.48779845203
        double var_chaste_interface__T_type_Ca_channel_d_gate__d_T = rY[6];
        // Units: dimensionless; Initial value: 0.42074047435
        double var_chaste_interface__T_type_Ca_channel_f_gate__f_T = rY[7];
        // Units: dimensionless; Initial value: 0.038968420558
        double var_chaste_interface__four_AP_sensitive_currents_q_gate__q = rY[8];
        // Units: dimensionless; Initial value: 0.29760539675
        double var_chaste_interface__four_AP_sensitive_currents_r_gate__r = rY[9];
        // Units: dimensionless; Initial value: 0.064402950262
        double var_chaste_interface__rapid_delayed_rectifying_potassium_current_P_af_gate__P_af = rY[10];
        // Units: dimensionless; Initial value: 0.13034201158
        double var_chaste_interface__rapid_delayed_rectifying_potassium_current_P_as_gate__P_as = rY[11];
        // Units: dimensionless; Initial value: 0.46960956028
        double var_chaste_interface__rapid_delayed_rectifying_potassium_current_P_i_gate__P_i = rY[12];
        // Units: dimensionless; Initial value: 0.87993375273
        double var_chaste_interface__slow_delayed_rectifying_potassium_current_xs_gate__xs = rY[13];
        // Units: dimensionless; Initial value: 0.082293827208
        double var_chaste_interface__hyperpolarisation_activated_current_y_gate__y = rY[14];
        // Units: dimensionless; Initial value: 0.03889291759

        // Mathematics
        double d_dt_chaste_interface_var_membrane__V;
        const double var_L_type_Ca_channel_f_gate__f_L_infinity = 1.0 / (1.0 + exp(9.0 + 0.20000000000000001 * var_chaste_interface__membrane__V)); // dimensionless
        const double var_T_type_Ca_channel_d_gate__d_T_infinity = 1.0 / (1.0 + exp(-5.4411764705882355 - 0.14705882352941177 * var_chaste_interface__membrane__V)); // dimensionless
        const double var_T_type_Ca_channel_d_gate__tau_d_T = 1.0 / (1068.0 * exp(0.87666666666666671 + 0.033333333333333333 * var_chaste_interface__membrane__V) + 1068.0 * exp(-0.87666666666666671 - 0.033333333333333333 * var_chaste_interface__membrane__V)); // second
        const double var_T_type_Ca_channel_f_gate__f_T_infinity = 1.0 / (1.0 + exp(7.8888888888888893 + 0.1111111111111111 * var_chaste_interface__membrane__V)); // dimensionless
        const double var_four_AP_sensitive_currents_q_gate__q_infinity = 1.0 / (1.0 + exp(4.5320610687022898 + 0.076335877862595422 * var_chaste_interface__membrane__V)); // dimensionless
        const double var_four_AP_sensitive_currents_r_gate__r_infinity = 1.0 / (1.0 + exp(0.5548223350253807 - 0.050761421319796954 * var_chaste_interface__membrane__V)); // dimensionless
        const double var_hyperpolarisation_activated_current_y_gate__beta_y = 1.0 * exp(3.5355294117647058 + 0.047058823529411764 * var_chaste_interface__membrane__V); // per_second
        const double var_L_type_Ca_channel_d_gate__tau_d_L = 2.0 / (11.43 * (-5.0 + var_chaste_interface__membrane__V) / (-1.0 + exp(-2.0 + 0.40000000000000002 * var_chaste_interface__membrane__V)) - 28.390000000000001 * (35.0 + var_chaste_interface__membrane__V) / (-1.0 + exp(-14.0 - 0.40000000000000002 * var_chaste_interface__membrane__V)) - 84.900000000000006 * var_chaste_interface__membrane__V / (-1.0 + exp(-0.20799999999999999 * var_chaste_interface__membrane__V))); // second
        const double var_four_AP_sensitive_currents_r_gate__tau_r = 0.0029775000000000001 + 0.019595000000000001 / (1.0369999999999999 * exp(2.7585732000000003 + 0.090120000000000006 * var_chaste_interface__membrane__V) + 0.36899999999999999 * exp(-2.8369599999999999 - 0.11899999999999999 * var_chaste_interface__membrane__V)); // second
        const double var_hyperpolarisation_activated_current_y_gate__alpha_y = 1.0 * exp(-2.9631993991738641 - 0.037551633496057078 * var_chaste_interface__membrane__V); // per_second
        const double var_L_type_Ca_channel_d_gate__d_L_infinity = 1.0 / (1.0 + exp(-3.7166666666666668 - 0.16666666666666666 * var_chaste_interface__membrane__V)); // dimensionless
        const double var_L_type_Ca_channel_f_gate__tau_f_L = 1.2 / (30.0 / (1.0 + exp(-7.0 - 0.25 * var_chaste_interface__membrane__V)) + 3.75 * (28.0 + var_chaste_interface__membrane__V) / (-1.0 + exp(7.0 + 0.25 * var_chaste_interface__membrane__V))); // second
        const double var_T_type_Ca_channel_f_gate__tau_f_T = 1.0 / (15.0 * exp(4.6163849154746419 + 0.065019505851755519 * var_chaste_interface__membrane__V) + 15.300000000000001 * exp(-0.85234093637454988 - 0.012004801920768308 * var_chaste_interface__membrane__V)); // second
        const double var_four_AP_sensitive_currents_q_gate__tau_q = 0.010103333333333334 + 0.065166666666666664 / (0.56859999999999999 * exp(-3.1827900000000002 - 0.081610000000000002 * var_chaste_interface__membrane__V) + 0.71740000000000004 * exp(11.128867 + 0.27189999999999998 * var_chaste_interface__membrane__V)); // second
        const double var_rapid_delayed_rectifying_potassium_current_P_af_gate__P_af_infinity = 1.0 / (1.0 + exp(-1.3396226415094339 - 0.094339622641509441 * var_chaste_interface__membrane__V)); // dimensionless
        const double var_rapid_delayed_rectifying_potassium_current_P_af_gate__tau_P_af = 1.0 / (0.95999999999999996 * exp(0.40000000000000002 - 0.044444444444444446 * var_chaste_interface__membrane__V) + 37.200000000000003 * exp(-0.56603773584905659 + 0.062893081761006289 * var_chaste_interface__membrane__V)); // second
        const double var_rapid_delayed_rectifying_potassium_current_P_as_gate__P_as_infinity = 1.0 / (1.0 + exp(-1.3396226415094339 - 0.094339622641509441 * var_chaste_interface__membrane__V)); // dimensionless
        const double var_rapid_delayed_rectifying_potassium_current_P_as_gate__tau_P_as = 1.0 / (4.2000000000000002 * exp(-0.52941176470588236 + 0.058823529411764705 * var_chaste_interface__membrane__V) + 0.14999999999999999 * exp(0.41666666666666663 - 0.046296296296296294 * var_chaste_interface__membrane__V)); // second
        const double var_rapid_delayed_rectifying_potassium_current_P_i_gate__P_i_infinity = 1.0 / (1.0 + exp(1.8415841584158419 + 0.099009900990099015 * var_chaste_interface__membrane__V)); // dimensionless
        const double var_rapid_delayed_rectifying_potassium_current_P_i_gate__tau_P_i = 0.002; // second
        const double var_slow_delayed_rectifying_potassium_current_xs_gate__alpha_xs = 14.0 / (1.0 + exp(4.4444444444444446 - 0.1111111111111111 * var_chaste_interface__membrane__V)); // per_second
        const double var_slow_delayed_rectifying_potassium_current_xs_gate__beta_xs = 1.0 * exp(-0.022222222222222223 * var_chaste_interface__membrane__V); // per_second
        const double var_sodium_current_h_gate__h1_infinity = 1.0 / (1.0 + exp(10.328124999999998 + 0.15625 * var_chaste_interface__membrane__V)); // dimensionless
        const double var_sodium_current_h_gate__h2_infinity = 1.0 / (1.0 + exp(10.328124999999998 + 0.15625 * var_chaste_interface__membrane__V)); // dimensionless
        const double var_sodium_current_h_gate__tau_h1 = 0.00059770000000000005 + 3.7170000000000002e-6 * exp(-4.8164649999999991 - 0.28149999999999997 * var_chaste_interface__membrane__V) / (1.0 + 0.0037320000000000001 * exp(-12.936576000000001 - 0.34260000000000002 * var_chaste_interface__membrane__V)); // second
        const double var_sodium_current_h_gate__tau_h2 = 0.0035560000000000001 + 3.1860000000000002e-8 * exp(-11.69172 - 0.62190000000000001 * var_chaste_interface__membrane__V) / (1.0 + 7.1890000000000005e-5 * exp(-22.768981 - 0.66830000000000001 * var_chaste_interface__membrane__V)); // second
        const double var_sodium_current_m_gate__m_infinity = 1.0 * pow(1 / (1.0 + exp(-5.5531135531135529 - 0.18315018315018314 * var_chaste_interface__membrane__V)), 0.33333333333333331); // dimensionless
        const double var_sodium_current_m_gate__tau_m = 4.5689999999999998e-5 + 0.00062469999999999995 / (0.62739999999999996 * exp(5.3505781299999997 + 0.082299999999999998 * var_chaste_interface__membrane__V) + 0.83221659999999997 * exp(-19.034003092000003 - 0.33566000000000001 * var_chaste_interface__membrane__V)); // second

        if (mSetVoltageDerivativeToZero)
        {
            d_dt_chaste_interface_var_membrane__V = 0.0;
        }
        else
        {
            d_dt_chaste_interface_var_membrane__V = 0.19948974038278122 + 0.033065025136302481 * exp(-0.018714999999999999 * var_chaste_interface__membrane__V) - 0.62090644426714181 / (1.5 + exp(-1.5 - 0.025000000000000001 * var_chaste_interface__membrane__V)) - 0.12339134744742616 * exp(0.018714999999999999 * var_chaste_interface__membrane__V) - 0.0048327079999999998 * var_chaste_interface__membrane__V - 0.003322752 * (86.631929397420322 + var_chaste_interface__membrane__V) * var_chaste_interface__four_AP_sensitive_currents_r_gate__r - 0.027324999999999999 * (86.631929397420322 + var_chaste_interface__membrane__V) * var_chaste_interface__hyperpolarisation_activated_current_y_gate__y - 0.027324999999999999 * (-76.171870705299767 + var_chaste_interface__membrane__V) * var_chaste_interface__hyperpolarisation_activated_current_y_gate__y - 0.017225000000000001 * pow(var_chaste_interface__slow_delayed_rectifying_potassium_current_xs_gate__xs, 2) * (71.365322852196982 + var_chaste_interface__membrane__V) - 0.28969 * (-46.399999999999999 + var_chaste_interface__membrane__V) * (0.0060000000000000001 / (1.0 + exp(-2.3500000000000001 - 0.16666666666666666 * var_chaste_interface__membrane__V)) + var_chaste_interface__L_type_Ca_channel_d_gate__d_L * var_chaste_interface__L_type_Ca_channel_f_gate__f_L) - 0.21390300000000001 * (-45.0 + var_chaste_interface__membrane__V) * var_chaste_interface__T_type_Ca_channel_d_gate__d_T * var_chaste_interface__T_type_Ca_channel_f_gate__f_T - 0.039851999999999999 * (86.631929397420322 + var_chaste_interface__membrane__V) * (0.40000000000000002 * var_chaste_interface__rapid_delayed_rectifying_potassium_current_P_as_gate__P_as + 0.59999999999999998 * var_chaste_interface__rapid_delayed_rectifying_potassium_current_P_af_gate__P_af) * var_chaste_interface__rapid_delayed_rectifying_potassium_current_P_i_gate__P_i - 0.24524999999999997 * (86.631929397420322 + var_chaste_interface__membrane__V) * var_chaste_interface__four_AP_sensitive_currents_q_gate__q * var_chaste_interface__four_AP_sensitive_currents_r_gate__r; // millivolt / millisecond
        }
        
        rDY[0] = d_dt_chaste_interface_var_membrane__V;
        rAlphaOrTau[1] = 1000.0 * var_sodium_current_m_gate__tau_m;
        rBetaOrInf[1] = var_sodium_current_m_gate__m_infinity;
        rAlphaOrTau[2] = 1000.0 * var_sodium_current_h_gate__tau_h1;
        rBetaOrInf[2] = var_sodium_current_h_gate__h1_infinity;
        rAlphaOrTau[3] = 1000.0 * var_sodium_current_h_gate__tau_h2;
        rBetaOrInf[3] = var_sodium_current_h_gate__h2_infinity;
        rAlphaOrTau[4] = 1000.0 * var_L_type_Ca_channel_d_gate__tau_d_L;
        rBetaOrInf[4] = var_L_type_Ca_channel_d_gate__d_L_infinity;
        rAlphaOrTau[5] = 1000.0 * var_L_type_Ca_channel_f_gate__tau_f_L;
        rBetaOrInf[5] = var_L_type_Ca_channel_f_gate__f_L_infinity;
        rAlphaOrTau[6] = 1000.0 * var_T_type_Ca_channel_d_gate__tau_d_T;
        rBetaOrInf[6] = var_T_type_Ca_channel_d_gate__d_T_infinity;
        rAlphaOrTau[7] = 1000.0 * var_T_type_Ca_channel_f_gate__tau_f_T;
        rBetaOrInf[7] = var_T_type_Ca_channel_f_gate__f_T_infinity;
        rAlphaOrTau[8] = 1000.0 * var_four_AP_sensitive_currents_q_gate__tau_q;
        rBetaOrInf[8] = var_four_AP_sensitive_currents_q_gate__q_infinity;
        rAlphaOrTau[9] = 1000.0 * var_four_AP_sensitive_currents_r_gate__tau_r;
        rBetaOrInf[9] = var_four_AP_sensitive_currents_r_gate__r_infinity;
        rAlphaOrTau[10] = 1000.0 * var_rapid_delayed_rectifying_potassium_current_P_af_gate__tau_P_af;
        rBetaOrInf[10] = var_rapid_delayed_rectifying_potassium_current_P_af_gate__P_af_infinity;
        rAlphaOrTau[11] = 1000.0 * var_rapid_delayed_rectifying_potassium_current_P_as_gate__tau_P_as;
        rBetaOrInf[11] = var_rapid_delayed_rectifying_potassium_current_P_as_gate__P_as_infinity;
        rAlphaOrTau[12] = 1000.0 * var_rapid_delayed_rectifying_potassium_current_P_i_gate__tau_P_i;
        rBetaOrInf[12] = var_rapid_delayed_rectifying_potassium_current_P_i_gate__P_i_infinity;
        rAlphaOrTau[13] = 0.001 * var_slow_delayed_rectifying_potassium_current_xs_gate__alpha_xs;
        rBetaOrInf[13] = 0.001 * var_slow_delayed_rectifying_potassium_current_xs_gate__beta_xs;
        rAlphaOrTau[14] = 0.001 * var_hyperpolarisation_activated_current_y_gate__alpha_y;
        rBetaOrInf[14] = 0.001 * var_hyperpolarisation_activated_current_y_gate__beta_y;
    }
    void Cellzhang_SAN_model_2000_allFromCellMLRushLarsen::ComputeOneStepExceptVoltage(const std::vector<double> &rDY, const std::vector<double> &rAlphaOrTau, const std::vector<double> &rBetaOrInf)
    {
        std::vector<double>& rY = rGetStateVariables();
        
        rY[1] = rBetaOrInf[1] + (rY[1] - rBetaOrInf[1])*exp(-mDt/rAlphaOrTau[1]);
        rY[2] = rBetaOrInf[2] + (rY[2] - rBetaOrInf[2])*exp(-mDt/rAlphaOrTau[2]);
        rY[3] = rBetaOrInf[3] + (rY[3] - rBetaOrInf[3])*exp(-mDt/rAlphaOrTau[3]);
        rY[4] = rBetaOrInf[4] + (rY[4] - rBetaOrInf[4])*exp(-mDt/rAlphaOrTau[4]);
        rY[5] = rBetaOrInf[5] + (rY[5] - rBetaOrInf[5])*exp(-mDt/rAlphaOrTau[5]);
        rY[6] = rBetaOrInf[6] + (rY[6] - rBetaOrInf[6])*exp(-mDt/rAlphaOrTau[6]);
        rY[7] = rBetaOrInf[7] + (rY[7] - rBetaOrInf[7])*exp(-mDt/rAlphaOrTau[7]);
        rY[8] = rBetaOrInf[8] + (rY[8] - rBetaOrInf[8])*exp(-mDt/rAlphaOrTau[8]);
        rY[9] = rBetaOrInf[9] + (rY[9] - rBetaOrInf[9])*exp(-mDt/rAlphaOrTau[9]);
        rY[10] = rBetaOrInf[10] + (rY[10] - rBetaOrInf[10])*exp(-mDt/rAlphaOrTau[10]);
        rY[11] = rBetaOrInf[11] + (rY[11] - rBetaOrInf[11])*exp(-mDt/rAlphaOrTau[11]);
        rY[12] = rBetaOrInf[12] + (rY[12] - rBetaOrInf[12])*exp(-mDt/rAlphaOrTau[12]);
        {
            const double tau_inv = rAlphaOrTau[13] + rBetaOrInf[13];
            const double y_inf = rAlphaOrTau[13] / tau_inv;
            rY[13] = y_inf + (rY[13] - y_inf)*exp(-mDt*tau_inv);
        }
        {
            const double tau_inv = rAlphaOrTau[14] + rBetaOrInf[14];
            const double y_inf = rAlphaOrTau[14] / tau_inv;
            rY[14] = y_inf + (rY[14] - y_inf)*exp(-mDt*tau_inv);
        }
    }

template<>
void OdeSystemInformation<Cellzhang_SAN_model_2000_allFromCellMLRushLarsen>::Initialise(void)
{
    this->mSystemName = "zhang_SAN_model_2000_all";
    this->mFreeVariableName = "environment__time_converted";
    this->mFreeVariableUnits = "millisecond";

    // rY[0]:
    this->mVariableNames.push_back("membrane_voltage");
    this->mVariableUnits.push_back("millivolt");
    this->mInitialConditions.push_back(-39.013558536);

    // rY[1]:
    this->mVariableNames.push_back("sodium_current_m_gate__m");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.092361701692);

    // rY[2]:
    this->mVariableNames.push_back("sodium_current_h_gate__h1");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.015905380261);

    // rY[3]:
    this->mVariableNames.push_back("sodium_current_h_gate__h2");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.01445216109);

    // rY[4]:
    this->mVariableNames.push_back("L_type_Ca_channel_d_gate__d_L");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.04804900895);

    // rY[5]:
    this->mVariableNames.push_back("L_type_Ca_channel_f_gate__f_L");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.48779845203);

    // rY[6]:
    this->mVariableNames.push_back("T_type_Ca_channel_d_gate__d_T");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.42074047435);

    // rY[7]:
    this->mVariableNames.push_back("T_type_Ca_channel_f_gate__f_T");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.038968420558);

    // rY[8]:
    this->mVariableNames.push_back("four_AP_sensitive_currents_q_gate__q");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.29760539675);

    // rY[9]:
    this->mVariableNames.push_back("four_AP_sensitive_currents_r_gate__r");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.064402950262);

    // rY[10]:
    this->mVariableNames.push_back("rapid_delayed_rectifying_potassium_current_P_af_gate__P_af");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.13034201158);

    // rY[11]:
    this->mVariableNames.push_back("rapid_delayed_rectifying_potassium_current_P_as_gate__P_as");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.46960956028);

    // rY[12]:
    this->mVariableNames.push_back("rapid_delayed_rectifying_potassium_current_P_i_gate__P_i");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.87993375273);

    // rY[13]:
    this->mVariableNames.push_back("slow_delayed_rectifying_potassium_current_xs_gate__xs");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.082293827208);

    // rY[14]:
    this->mVariableNames.push_back("hyperpolarisation_activated_current_y_gate__y");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.03889291759);

    this->mInitialised = true;
}

// Serialization for Boost >= 1.36
#include "SerializationExportWrapperForCpp.hpp"
CHASTE_CLASS_EXPORT(Cellzhang_SAN_model_2000_allFromCellMLRushLarsen)
