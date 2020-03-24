//! @file
//! 
//! This source file was generated from CellML.
//! 
//! Model: zhang_SAN_model_2000_all
//! 
//! Processed by pycml - CellML Tools in Python
//!     (translators: , pycml: , optimize: )
//! on Wed Mar 11 16:56:19 2020
//! 
//! <autogenerated>

#include "zhang_SAN_model_2000_all.hpp"
#include <cmath>
#include <cassert>
#include <memory>
#include "CardiacNewtonSolver.hpp"
#include "Exception.hpp"
#include "OdeSystemInformation.hpp"
#include "RegularStimulus.hpp"
#include "HeartConfig.hpp"
#include "IsNan.hpp"
#include "MathsCustomFunctions.hpp"

    Dynamiczhang_SAN_model_2000_allFromCellMLBackwardEuler::Dynamiczhang_SAN_model_2000_allFromCellMLBackwardEuler(boost::shared_ptr<AbstractIvpOdeSolver> /* unused; should be empty */, boost::shared_ptr<AbstractStimulusFunction> pIntracellularStimulus)
        : AbstractBackwardEulerCardiacCell<0>(
                15,
                0,
                pIntracellularStimulus)
    {
        // Time units: millisecond
        // 
        this->mpSystemInfo = OdeSystemInformation<Dynamiczhang_SAN_model_2000_allFromCellMLBackwardEuler>::Instance();
        Init();

    }
    
    Dynamiczhang_SAN_model_2000_allFromCellMLBackwardEuler::~Dynamiczhang_SAN_model_2000_allFromCellMLBackwardEuler()
    {
    }
    
    double Dynamiczhang_SAN_model_2000_allFromCellMLBackwardEuler::GetIIonic(const std::vector<double>* pStateVariables)
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
        
        const double var_sodium_current_h_gate__F_Na = ((0.095180000000000001 * exp( -0.063060000000000005 * (var_chaste_interface__membrane__V + 34.399999999999999))) / (1.0 + (1.6619999999999999 * exp( -0.22509999999999999 * (var_chaste_interface__membrane__V + 63.700000000000003))))) + 0.086929999999999993; // dimensionless
        const double var_sodium_current__i_Na = ((((pow(var_chaste_interface__sodium_current_m_gate__m, 3.0) * (((1.0 - var_sodium_current_h_gate__F_Na) * var_chaste_interface__sodium_current_h_gate__h1) + (var_sodium_current_h_gate__F_Na * var_chaste_interface__sodium_current_h_gate__h2)) * 0.0) * 3.8799692706433766e-07) * (exp(((var_chaste_interface__membrane__V - 76.171870705299781) * 96845.0) * 3.8799692706433766e-07) - 1.0)) / (exp((var_chaste_interface__membrane__V * 96845.0) * 3.8799692706433766e-07) - 1.0)) * var_chaste_interface__membrane__V; // nanoA
        const double var_L_type_Ca_channel__i_Ca_L = 0.0057938 * ((var_chaste_interface__L_type_Ca_channel_f_gate__f_L * var_chaste_interface__L_type_Ca_channel_d_gate__d_L) + (0.0060000000000000001 / (1.0 + exp((-(var_chaste_interface__membrane__V + 14.1)) * 0.16666666666666666)))) * (var_chaste_interface__membrane__V - 46.399999999999999); // nanoA
        const double var_T_type_Ca_channel__i_Ca_T = 0.0042780600000000002 * var_chaste_interface__T_type_Ca_channel_d_gate__d_T * var_chaste_interface__T_type_Ca_channel_f_gate__f_T * (var_chaste_interface__membrane__V - 45.0); // nanoA
        const double var_four_AP_sensitive_currents__i_to = 0.0049049999999999996 * var_chaste_interface__four_AP_sensitive_currents_q_gate__q * var_chaste_interface__four_AP_sensitive_currents_r_gate__r * (var_chaste_interface__membrane__V -  -86.631929397420336); // nanoA
        const double var_four_AP_sensitive_currents__i_sus = 6.6455040000000003e-05 * var_chaste_interface__four_AP_sensitive_currents_r_gate__r * (var_chaste_interface__membrane__V -  -86.631929397420336); // nanoA
        const double var_rapid_delayed_rectifying_potassium_current__i_K_r = 0.00079704000000000005 * ((0.59999999999999998 * var_chaste_interface__rapid_delayed_rectifying_potassium_current_P_af_gate__P_af) + (0.40000000000000002 * var_chaste_interface__rapid_delayed_rectifying_potassium_current_P_as_gate__P_as)) * var_chaste_interface__rapid_delayed_rectifying_potassium_current_P_i_gate__P_i * (var_chaste_interface__membrane__V -  -86.631929397420336); // nanoA
        const double var_slow_delayed_rectifying_potassium_current__i_K_s = 0.00034450000000000003 * pow(var_chaste_interface__slow_delayed_rectifying_potassium_current_xs_gate__xs, 2.0) * (var_chaste_interface__membrane__V -  -71.365322852196982); // nanoA
        const double var_hyperpolarisation_activated_current__i_f_Na = 0.0005465 * var_chaste_interface__hyperpolarisation_activated_current_y_gate__y * (var_chaste_interface__membrane__V - 76.171870705299781); // nanoA
        const double var_hyperpolarisation_activated_current__i_f_K = 0.0005465 * var_chaste_interface__hyperpolarisation_activated_current_y_gate__y * (var_chaste_interface__membrane__V -  -86.631929397420336); // nanoA
        const double var_sodium_background_current__i_b_Na = 5.8181799999999999e-05 * (var_chaste_interface__membrane__V - 76.171870705299781); // nanoA
        const double var_calcium_background_current__i_b_Ca = 1.3236e-05 * (var_chaste_interface__membrane__V - 131.78096240721496); // nanoA
        const double var_potassium_background_current__i_b_K = 2.5236359999999998e-05 * (var_chaste_interface__membrane__V -  -86.631929397420336); // nanoA
        const double var_sodium_calcium_exchanger__i_NaCa = (2.7228999999999998e-06 * ((exp(var_chaste_interface__membrane__V * 0.018714999999999999) * 1024.0) - (exp(var_chaste_interface__membrane__V *  -0.018714999999999999) * 274.40000000000003))) * 0.88508107342632591; // nanoA
        const double var_sodium_potassium_pump__i_p = 0.012418128885342827 / (1.5 + exp((-(var_chaste_interface__membrane__V + 60.0)) * 0.025000000000000001)); // nanoA
        const double var_chaste_interface__i_ionic = 0.001 * (((var_sodium_current__i_Na + var_L_type_Ca_channel__i_Ca_L + var_T_type_Ca_channel__i_Ca_T + var_four_AP_sensitive_currents__i_to + var_four_AP_sensitive_currents__i_sus + var_rapid_delayed_rectifying_potassium_current__i_K_r + var_slow_delayed_rectifying_potassium_current__i_K_s + var_hyperpolarisation_activated_current__i_f_Na + var_hyperpolarisation_activated_current__i_f_K + var_sodium_background_current__i_b_Na + var_calcium_background_current__i_b_Ca + var_potassium_background_current__i_b_K + var_sodium_calcium_exchanger__i_NaCa + var_sodium_potassium_pump__i_p + 0.0) * 49999.999999999993) * HeartConfig::Instance()->GetCapacitance()); // uA_per_cm2
        
        const double i_ionic = var_chaste_interface__i_ionic;
        EXCEPT_IF_NOT(!std::isnan(i_ionic));
        return i_ionic;
    }
    
    void Dynamiczhang_SAN_model_2000_allFromCellMLBackwardEuler::UpdateTransmembranePotential(double var_chaste_interface__environment__time)
    {
        // Time units: millisecond
        std::vector<double>& rY = rGetStateVariables();
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
        
        const double var_sodium_current_h_gate__F_Na = ((0.095180000000000001 * exp( -0.063060000000000005 * (var_chaste_interface__membrane__V + 34.399999999999999))) / (1.0 + (1.6619999999999999 * exp( -0.22509999999999999 * (var_chaste_interface__membrane__V + 63.700000000000003))))) + 0.086929999999999993; // dimensionless
        const double var_sodium_current__i_Na = ((((pow(var_chaste_interface__sodium_current_m_gate__m, 3.0) * (((1.0 - var_sodium_current_h_gate__F_Na) * var_chaste_interface__sodium_current_h_gate__h1) + (var_sodium_current_h_gate__F_Na * var_chaste_interface__sodium_current_h_gate__h2)) * 0.0) * 3.8799692706433766e-07) * (exp(((var_chaste_interface__membrane__V - 76.171870705299781) * 96845.0) * 3.8799692706433766e-07) - 1.0)) / (exp((var_chaste_interface__membrane__V * 96845.0) * 3.8799692706433766e-07) - 1.0)) * var_chaste_interface__membrane__V; // nanoA
        const double var_L_type_Ca_channel__i_Ca_L = 0.0057938 * ((var_chaste_interface__L_type_Ca_channel_f_gate__f_L * var_chaste_interface__L_type_Ca_channel_d_gate__d_L) + (0.0060000000000000001 / (1.0 + exp((-(var_chaste_interface__membrane__V + 14.1)) * 0.16666666666666666)))) * (var_chaste_interface__membrane__V - 46.399999999999999); // nanoA
        const double var_T_type_Ca_channel__i_Ca_T = 0.0042780600000000002 * var_chaste_interface__T_type_Ca_channel_d_gate__d_T * var_chaste_interface__T_type_Ca_channel_f_gate__f_T * (var_chaste_interface__membrane__V - 45.0); // nanoA
        const double var_four_AP_sensitive_currents__i_to = 0.0049049999999999996 * var_chaste_interface__four_AP_sensitive_currents_q_gate__q * var_chaste_interface__four_AP_sensitive_currents_r_gate__r * (var_chaste_interface__membrane__V -  -86.631929397420336); // nanoA
        const double var_four_AP_sensitive_currents__i_sus = 6.6455040000000003e-05 * var_chaste_interface__four_AP_sensitive_currents_r_gate__r * (var_chaste_interface__membrane__V -  -86.631929397420336); // nanoA
        const double var_rapid_delayed_rectifying_potassium_current__i_K_r = 0.00079704000000000005 * ((0.59999999999999998 * var_chaste_interface__rapid_delayed_rectifying_potassium_current_P_af_gate__P_af) + (0.40000000000000002 * var_chaste_interface__rapid_delayed_rectifying_potassium_current_P_as_gate__P_as)) * var_chaste_interface__rapid_delayed_rectifying_potassium_current_P_i_gate__P_i * (var_chaste_interface__membrane__V -  -86.631929397420336); // nanoA
        const double var_slow_delayed_rectifying_potassium_current__i_K_s = 0.00034450000000000003 * pow(var_chaste_interface__slow_delayed_rectifying_potassium_current_xs_gate__xs, 2.0) * (var_chaste_interface__membrane__V -  -71.365322852196982); // nanoA
        const double var_hyperpolarisation_activated_current__i_f_Na = 0.0005465 * var_chaste_interface__hyperpolarisation_activated_current_y_gate__y * (var_chaste_interface__membrane__V - 76.171870705299781); // nanoA
        const double var_hyperpolarisation_activated_current__i_f_K = 0.0005465 * var_chaste_interface__hyperpolarisation_activated_current_y_gate__y * (var_chaste_interface__membrane__V -  -86.631929397420336); // nanoA
        const double var_sodium_background_current__i_b_Na = 5.8181799999999999e-05 * (var_chaste_interface__membrane__V - 76.171870705299781); // nanoA
        const double var_calcium_background_current__i_b_Ca = 1.3236e-05 * (var_chaste_interface__membrane__V - 131.78096240721496); // nanoA
        const double var_potassium_background_current__i_b_K = 2.5236359999999998e-05 * (var_chaste_interface__membrane__V -  -86.631929397420336); // nanoA
        const double var_sodium_calcium_exchanger__i_NaCa = (2.7228999999999998e-06 * ((exp(var_chaste_interface__membrane__V * 0.018714999999999999) * 1024.0) - (exp(var_chaste_interface__membrane__V *  -0.018714999999999999) * 274.40000000000003))) * 0.88508107342632591; // nanoA
        const double var_sodium_potassium_pump__i_p = 0.012418128885342827 / (1.5 + exp((-(var_chaste_interface__membrane__V + 60.0)) * 0.025000000000000001)); // nanoA
        const double d_dt_chaste_interface__membrane__V = 0.001 * ( -49999.999999999993 * (var_sodium_current__i_Na + var_L_type_Ca_channel__i_Ca_L + var_T_type_Ca_channel__i_Ca_T + var_four_AP_sensitive_currents__i_to + var_four_AP_sensitive_currents__i_sus + var_rapid_delayed_rectifying_potassium_current__i_K_r + var_slow_delayed_rectifying_potassium_current__i_K_s + var_hyperpolarisation_activated_current__i_f_Na + var_hyperpolarisation_activated_current__i_f_K + var_sodium_background_current__i_b_Na + var_calcium_background_current__i_b_Ca + var_potassium_background_current__i_b_K + var_sodium_calcium_exchanger__i_NaCa + var_sodium_potassium_pump__i_p + 0.0)); // 'millivolt per millisecond'
        
        rY[0] += mDt*d_dt_chaste_interface__membrane__V;
    }
    
    void Dynamiczhang_SAN_model_2000_allFromCellMLBackwardEuler::ComputeOneStepExceptVoltage(double var_chaste_interface__environment__time)
    {
        // Time units: millisecond
        std::vector<double>& rY = rGetStateVariables();
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
        
        const double var_chaste_interface__environment__dt = mDt;

        const double var_sodium_current_m_gate__tau_m = (0.00062469999999999995 / ((0.83221659999999997 * exp( -0.33566000000000001 * (var_chaste_interface__membrane__V + 56.706200000000003))) + (0.62739999999999996 * exp(0.082299999999999998 * (var_chaste_interface__membrane__V + 65.013099999999994))))) + 4.5689999999999998e-05; // second
        const double var_sodium_current_h_gate__h1_infinity = 1.0 / (1.0 + exp((var_chaste_interface__membrane__V + 66.099999999999994) * 0.15625)); // dimensionless
        const double var_sodium_current_h_gate__tau_h1 = ((3.7170000000000002e-06 * exp( -0.28149999999999997 * (var_chaste_interface__membrane__V + 17.109999999999999))) / (1.0 + (0.0037320000000000001 * exp( -0.34260000000000002 * (var_chaste_interface__membrane__V + 37.759999999999998))))) + 0.00059770000000000005; // second
        const double var_sodium_current_h_gate__tau_h2 = ((3.1860000000000002e-08 * exp( -0.62190000000000001 * (var_chaste_interface__membrane__V + 18.800000000000001))) / (1.0 + (7.1890000000000005e-05 * exp( -0.66830000000000001 * (var_chaste_interface__membrane__V + 34.07))))) + 0.0035560000000000001; // second
        const double var_L_type_Ca_channel_d_gate__tau_d_L = 2.0 / (((( -28.390000000000001 * (var_chaste_interface__membrane__V + 35.0)) / (exp((-(var_chaste_interface__membrane__V + 35.0)) * 0.40000000000000002) - 1.0)) - ((84.900000000000006 * var_chaste_interface__membrane__V) / (exp( -0.20799999999999999 * var_chaste_interface__membrane__V) - 1.0))) + ((11.43 * (var_chaste_interface__membrane__V - 5.0)) / (exp(0.40000000000000002 * (var_chaste_interface__membrane__V - 5.0)) - 1.0))); // second
        const double var_L_type_Ca_channel_f_gate__tau_f_L = 1.2 / (((3.75 * (var_chaste_interface__membrane__V + 28.0)) / (exp((var_chaste_interface__membrane__V + 28.0) * 0.25) - 1.0)) + (30.0 / (1.0 + exp((-(var_chaste_interface__membrane__V + 28.0)) * 0.25)))); // second
        const double var_T_type_Ca_channel_d_gate__tau_d_T = 1.0 / ((1068.0 * exp((var_chaste_interface__membrane__V + 26.300000000000001) * 0.033333333333333333)) + (1068.0 * exp((-(var_chaste_interface__membrane__V + 26.300000000000001)) * 0.033333333333333333))); // second
        const double var_T_type_Ca_channel_f_gate__tau_f_T = 1.0 / ((15.300000000000001 * exp((-(var_chaste_interface__membrane__V + 71.0)) * 0.012004801920768308)) + (15.0 * exp((var_chaste_interface__membrane__V + 71.0) * 0.065019505851755519))); // second
        const double var_four_AP_sensitive_currents_q_gate__tau_q = 0.00033333333333333332 * (30.309999999999999 + (195.5 / ((0.56859999999999999 * exp( -0.081610000000000002 * (var_chaste_interface__membrane__V + 39.0))) + (0.71740000000000004 * exp((var_chaste_interface__membrane__V + 40.93) * 0.27189999999999998))))); // second
        const double var_four_AP_sensitive_currents_r_gate__tau_r = 0.0025000000000000001 * (1.1910000000000001 + (7.8380000000000001 / ((1.0369999999999999 * exp(0.090120000000000006 * (var_chaste_interface__membrane__V + 30.609999999999999))) + (0.36899999999999999 * exp( -0.11899999999999999 * (var_chaste_interface__membrane__V + 23.84)))))); // second
        const double var_rapid_delayed_rectifying_potassium_current_P_af_gate__tau_P_af = 1.0 / ((37.200000000000003 * exp((var_chaste_interface__membrane__V - 9.0) * 0.062893081761006289)) + (0.95999999999999996 * exp((-(var_chaste_interface__membrane__V - 9.0)) * 0.044444444444444446))); // second
        const double var_rapid_delayed_rectifying_potassium_current_P_af_gate__P_af_infinity = 1.0 / (1.0 + exp((-(var_chaste_interface__membrane__V + 14.199999999999999)) * 0.094339622641509441)); // dimensionless
        const double var_rapid_delayed_rectifying_potassium_current_P_as_gate__tau_P_as = 1.0 / ((4.2000000000000002 * exp((var_chaste_interface__membrane__V - 9.0) * 0.058823529411764705)) + (0.14999999999999999 * exp((-(var_chaste_interface__membrane__V - 9.0)) * 0.046296296296296294))); // second
        const double var_slow_delayed_rectifying_potassium_current_xs_gate__alpha_xs = 14.0 / (1.0 + exp((-(var_chaste_interface__membrane__V - 40.0)) * 0.1111111111111111)); // per_second
        const double var_hyperpolarisation_activated_current_y_gate__alpha_y = 1.0 * exp((-(var_chaste_interface__membrane__V + 78.909999999999997)) * 0.037551633496057078); // per_second
        
        rY[4] = (var_chaste_interface__L_type_Ca_channel_d_gate__d_L + ((0.001 * ((1.0 / (1.0 + exp((-(var_chaste_interface__membrane__V + 22.300000000000001)) * 0.16666666666666666))) / var_L_type_Ca_channel_d_gate__tau_d_L)) * var_chaste_interface__environment__dt)) / (1.0 - ((0.001 * ( -1.0 / var_L_type_Ca_channel_d_gate__tau_d_L)) * var_chaste_interface__environment__dt));
        rY[5] = (var_chaste_interface__L_type_Ca_channel_f_gate__f_L + ((0.001 * ((1.0 / (1.0 + exp((var_chaste_interface__membrane__V + 45.0) * 0.20000000000000001))) / var_L_type_Ca_channel_f_gate__tau_f_L)) * var_chaste_interface__environment__dt)) / (1.0 - ((0.001 * ( -1.0 / var_L_type_Ca_channel_f_gate__tau_f_L)) * var_chaste_interface__environment__dt));
        rY[6] = (var_chaste_interface__T_type_Ca_channel_d_gate__d_T + ((0.001 * ((1.0 / (1.0 + exp((-(var_chaste_interface__membrane__V + 37.0)) * 0.14705882352941177))) / var_T_type_Ca_channel_d_gate__tau_d_T)) * var_chaste_interface__environment__dt)) / (1.0 - ((0.001 * ( -1.0 / var_T_type_Ca_channel_d_gate__tau_d_T)) * var_chaste_interface__environment__dt));
        rY[7] = (var_chaste_interface__T_type_Ca_channel_f_gate__f_T + ((0.001 * ((1.0 / (1.0 + exp((var_chaste_interface__membrane__V + 71.0) * 0.1111111111111111))) / var_T_type_Ca_channel_f_gate__tau_f_T)) * var_chaste_interface__environment__dt)) / (1.0 - ((0.001 * ( -1.0 / var_T_type_Ca_channel_f_gate__tau_f_T)) * var_chaste_interface__environment__dt));
        rY[8] = (var_chaste_interface__four_AP_sensitive_currents_q_gate__q + ((0.001 * ((1.0 / (1.0 + exp((var_chaste_interface__membrane__V + 59.369999999999997) * 0.076335877862595422))) / var_four_AP_sensitive_currents_q_gate__tau_q)) * var_chaste_interface__environment__dt)) / (1.0 - ((0.001 * ( -1.0 / var_four_AP_sensitive_currents_q_gate__tau_q)) * var_chaste_interface__environment__dt));
        rY[9] = (var_chaste_interface__four_AP_sensitive_currents_r_gate__r + ((0.001 * ((1.0 / (1.0 + exp((-(var_chaste_interface__membrane__V - 10.93)) * 0.050761421319796954))) / var_four_AP_sensitive_currents_r_gate__tau_r)) * var_chaste_interface__environment__dt)) / (1.0 - ((0.001 * ( -1.0 / var_four_AP_sensitive_currents_r_gate__tau_r)) * var_chaste_interface__environment__dt));
        rY[14] = (var_chaste_interface__hyperpolarisation_activated_current_y_gate__y + ((0.001 * (var_hyperpolarisation_activated_current_y_gate__alpha_y * 1.0)) * var_chaste_interface__environment__dt)) / (1.0 - ((0.001 * ((var_hyperpolarisation_activated_current_y_gate__alpha_y *  -1.0) - ((1.0 * exp((var_chaste_interface__membrane__V + 75.129999999999995) * 0.047058823529411764)) * 1.0))) * var_chaste_interface__environment__dt));
        rY[10] = (var_chaste_interface__rapid_delayed_rectifying_potassium_current_P_af_gate__P_af + ((0.001 * (var_rapid_delayed_rectifying_potassium_current_P_af_gate__P_af_infinity / var_rapid_delayed_rectifying_potassium_current_P_af_gate__tau_P_af)) * var_chaste_interface__environment__dt)) / (1.0 - ((0.001 * ( -1.0 / var_rapid_delayed_rectifying_potassium_current_P_af_gate__tau_P_af)) * var_chaste_interface__environment__dt));
        rY[11] = (var_chaste_interface__rapid_delayed_rectifying_potassium_current_P_as_gate__P_as + ((0.001 * (var_rapid_delayed_rectifying_potassium_current_P_af_gate__P_af_infinity / var_rapid_delayed_rectifying_potassium_current_P_as_gate__tau_P_as)) * var_chaste_interface__environment__dt)) / (1.0 - ((0.001 * ( -1.0 / var_rapid_delayed_rectifying_potassium_current_P_as_gate__tau_P_as)) * var_chaste_interface__environment__dt));
        rY[12] = (var_chaste_interface__rapid_delayed_rectifying_potassium_current_P_i_gate__P_i + ((0.001 * ((1.0 / (1.0 + exp((var_chaste_interface__membrane__V + 18.600000000000001) * 0.099009900990099015))) * 500.0)) * var_chaste_interface__environment__dt)) / (1.0 - ( -0.5 * var_chaste_interface__environment__dt));
        rY[13] = (var_chaste_interface__slow_delayed_rectifying_potassium_current_xs_gate__xs + ((0.001 * (var_slow_delayed_rectifying_potassium_current_xs_gate__alpha_xs * 1.0)) * var_chaste_interface__environment__dt)) / (1.0 - ((0.001 * ((var_slow_delayed_rectifying_potassium_current_xs_gate__alpha_xs *  -1.0) - ((1.0 * exp((-var_chaste_interface__membrane__V) * 0.022222222222222223)) * 1.0))) * var_chaste_interface__environment__dt));
        rY[2] = (var_chaste_interface__sodium_current_h_gate__h1 + ((0.001 * (var_sodium_current_h_gate__h1_infinity / var_sodium_current_h_gate__tau_h1)) * var_chaste_interface__environment__dt)) / (1.0 - ((0.001 * ( -1.0 / var_sodium_current_h_gate__tau_h1)) * var_chaste_interface__environment__dt));
        rY[3] = (var_chaste_interface__sodium_current_h_gate__h2 + ((0.001 * (var_sodium_current_h_gate__h1_infinity / var_sodium_current_h_gate__tau_h2)) * var_chaste_interface__environment__dt)) / (1.0 - ((0.001 * ( -1.0 / var_sodium_current_h_gate__tau_h2)) * var_chaste_interface__environment__dt));
        rY[1] = (var_chaste_interface__sodium_current_m_gate__m + ((0.001 * (pow(1.0 / (1.0 + exp((-(var_chaste_interface__membrane__V + 30.32)) * 0.18315018315018314)), 0.33333333333333331) / var_sodium_current_m_gate__tau_m)) * var_chaste_interface__environment__dt)) / (1.0 - ((0.001 * ( -1.0 / var_sodium_current_m_gate__tau_m)) * var_chaste_interface__environment__dt));
        
    }
    
template<>
void OdeSystemInformation<Dynamiczhang_SAN_model_2000_allFromCellMLBackwardEuler>::Initialise(void)
{
    this->mSystemName = "zhang_SAN_model_2000_all";
    this->mFreeVariableName = "environment__time";
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
CHASTE_CLASS_EXPORT(Dynamiczhang_SAN_model_2000_allFromCellMLBackwardEuler)
extern "C"
{
    AbstractCardiacCellInterface* MakeCardiacCell(
            boost::shared_ptr<AbstractIvpOdeSolver> pSolver,
            boost::shared_ptr<AbstractStimulusFunction> pStimulus)
    {
        return new Dynamiczhang_SAN_model_2000_allFromCellMLBackwardEuler(pSolver, pStimulus);
    }
    
}

