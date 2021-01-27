//! @file
//!
//! This source file was generated from CellML by chaste_codegen version (version omitted as unimportant)
//!
//! Model: hodgkin_huxley_squid_axon_model_1952_modified
//!
//! Processed by chaste_codegen: https://github.com/ModellingWebLab/chaste-codegen
//!     (translator: chaste_codegen, model type: RushLarsenOpt)
//! on (date omitted as unimportant)
//!
//! <autogenerated>

#include "hodgkin_huxley_squid_axon_model_1952_modified.hpp"
#include <cmath>
#include <cassert>
#include <memory>
#include "Exception.hpp"
#include "OdeSystemInformation.hpp"
#include "RegularStimulus.hpp"
#include "HeartConfig.hpp"
#include "IsNan.hpp"
#include "MathsCustomFunctions.hpp"

class Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLRushLarsenOpt_LookupTables : public AbstractLookupTableCollection
{
public:
    static Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLRushLarsenOpt_LookupTables* Instance()
    {
        if (mpInstance.get() == NULL)
        {
            mpInstance.reset(new Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLRushLarsenOpt_LookupTables);
        }
        return mpInstance.get();
    }

    void FreeMemory()
    {

        if (_lookup_table_0)
        {
            delete[] _lookup_table_0;
            _lookup_table_0 = NULL;
        }

        mNeedsRegeneration.assign(mNeedsRegeneration.size(), true);
    }

    // Row lookup methods
    // using linear-interpolation

    double* _lookup_0_row(unsigned i, double _factor_)
    {
        for (unsigned j=0; j<6; j++)
        {
            const double y1 = _lookup_table_0[i][j];
            const double y2 = _lookup_table_0[i+1][j];
            _lookup_table_0_row[j] = y1 + (y2-y1)*_factor_;
        }
        return _lookup_table_0_row;
    }


    const double * IndexTable0(double var_chaste_interface__membrane__V)
    {
        const double _offset_0 = var_chaste_interface__membrane__V - mTableMins[0];
        const double _offset_0_over_table_step = _offset_0 * mTableStepInverses[0];
        const unsigned _table_index_0 = (unsigned)(_offset_0_over_table_step);
        const double _factor_0 = _offset_0_over_table_step - _table_index_0;
        const double* const _lt_0_row = Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLRushLarsenOpt_LookupTables::Instance()->_lookup_0_row(_table_index_0, _factor_0);
        return _lt_0_row;
    }


// LCOV_EXCL_START
    bool CheckIndex0(double& var_chaste_interface__membrane__V)
    {
        bool _oob_0 = false;
        if (var_chaste_interface__membrane__V>mTableMaxs[0] || var_chaste_interface__membrane__V<mTableMins[0])
        {
// LCOV_EXCL_START
            _oob_0 = true;
// LCOV_EXCL_STOP
        }
        return _oob_0;
    }
// LCOV_EXCL_STOP

    ~Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLRushLarsenOpt_LookupTables()
    {

        if (_lookup_table_0)
        {
            delete[] _lookup_table_0;
            _lookup_table_0 = NULL;
        }

    }

protected:
    Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLRushLarsenOpt_LookupTables(const Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLRushLarsenOpt_LookupTables&);
    Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLRushLarsenOpt_LookupTables& operator= (const Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLRushLarsenOpt_LookupTables&);
    Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLRushLarsenOpt_LookupTables()
    {
        assert(mpInstance.get() == NULL);
        mKeyingVariableNames.resize(1);
        mNumberOfTables.resize(1);
        mTableMins.resize(1);
        mTableSteps.resize(1);
        mTableStepInverses.resize(1);
        mTableMaxs.resize(1);
        mNeedsRegeneration.resize(1);

        mKeyingVariableNames[0] = "membrane_voltage";
        mNumberOfTables[0] = 6;
        mTableMins[0] = -250.0001;
        mTableMaxs[0] = 549.9999;
        mTableSteps[0] = 0.001;
        mTableStepInverses[0] = 1000.0;
        mNeedsRegeneration[0] = true;
        _lookup_table_0 = NULL;

        Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLRushLarsenOpt_LookupTables::RegenerateTables();
    }

    void RegenerateTables()
    {
        AbstractLookupTableCollection::EventHandler::BeginEvent(AbstractLookupTableCollection::EventHandler::GENERATE_TABLES);


        if (mNeedsRegeneration[0])
        {
            if (_lookup_table_0)
            {
                delete[] _lookup_table_0;
                _lookup_table_0 = NULL;
            }
            const unsigned _table_size_0 = 1 + (unsigned)((mTableMaxs[0]-mTableMins[0])/mTableSteps[0]+0.5);
            _lookup_table_0 = new double[_table_size_0][6];

            for (unsigned i=0 ; i<_table_size_0; i++)
            {
                const double var_chaste_interface__membrane__V = mTableMins[0] + i*mTableSteps[0];
                _lookup_table_0[i][0] = ((fabs(65.0 + var_chaste_interface__membrane__V) < 1.0000000000287557e-6) ? (-1.0000000000287556e-8 / (-1.0 + exp(-1.0000000000287557e-7)) - 499999.99998562218 * (64.999999000000003 + var_chaste_interface__membrane__V) * (1.0000000000287556e-8 / (-1.0 + exp(1.0000000000287557e-7)) + 1.0000000000287556e-8 / (-1.0 + exp(-1.0000000000287557e-7)))) : (-0.01 * (65.0 + var_chaste_interface__membrane__V) / (-1.0 + exp(-6.5 - 0.10000000000000001 * var_chaste_interface__membrane__V))));
            }

            for (unsigned i=0 ; i<_table_size_0; i++)
            {
                const double var_chaste_interface__membrane__V = mTableMins[0] + i*mTableSteps[0];
                _lookup_table_0[i][1] = exp(0.9375 + 0.012500000000000001 * var_chaste_interface__membrane__V);
            }

            for (unsigned i=0 ; i<_table_size_0; i++)
            {
                const double var_chaste_interface__membrane__V = mTableMins[0] + i*mTableSteps[0];
                _lookup_table_0[i][2] = exp(-3.75 - 0.050000000000000003 * var_chaste_interface__membrane__V);
            }

            for (unsigned i=0 ; i<_table_size_0; i++)
            {
                const double var_chaste_interface__membrane__V = mTableMins[0] + i*mTableSteps[0];
                _lookup_table_0[i][3] = 1 / (1.0 + exp(-4.5 - 0.10000000000000001 * var_chaste_interface__membrane__V));
            }

            for (unsigned i=0 ; i<_table_size_0; i++)
            {
                const double var_chaste_interface__membrane__V = mTableMins[0] + i*mTableSteps[0];
                _lookup_table_0[i][4] = ((fabs(50.0 + var_chaste_interface__membrane__V) < 1.0000000000287557e-6) ? (-1.0000000000287557e-7 / (-1.0 + exp(-1.0000000000287557e-7)) - 499999.99998562218 * (49.999999000000003 + var_chaste_interface__membrane__V) * (1.0000000000287557e-7 / (-1.0 + exp(1.0000000000287557e-7)) + 1.0000000000287557e-7 / (-1.0 + exp(-1.0000000000287557e-7)))) : (-0.10000000000000001 * (50.0 + var_chaste_interface__membrane__V) / (-1.0 + exp(-5.0 - 0.10000000000000001 * var_chaste_interface__membrane__V))));
            }

            for (unsigned i=0 ; i<_table_size_0; i++)
            {
                const double var_chaste_interface__membrane__V = mTableMins[0] + i*mTableSteps[0];
                _lookup_table_0[i][5] = exp(-4.166666666666667 - 0.055555555555555552 * var_chaste_interface__membrane__V);
            }

            mNeedsRegeneration[0] = false;
        }

        AbstractLookupTableCollection::EventHandler::EndEvent(AbstractLookupTableCollection::EventHandler::GENERATE_TABLES);
    }

private:
    /** The single instance of the class */
    static std::shared_ptr<Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLRushLarsenOpt_LookupTables> mpInstance;

    // Row lookup methods memory
    double _lookup_table_0_row[6];

    // Lookup tables
    double (*_lookup_table_0)[6];

};

std::shared_ptr<Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLRushLarsenOpt_LookupTables> Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLRushLarsenOpt_LookupTables::mpInstance;


    Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLRushLarsenOpt::Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLRushLarsenOpt(boost::shared_ptr<AbstractIvpOdeSolver> /* unused; should be empty */, boost::shared_ptr<AbstractStimulusFunction> pIntracellularStimulus)
        : AbstractRushLarsenCardiacCell(
                4,
                0,
                pIntracellularStimulus)
    {
        // Time units: millisecond
        //
        this->mpSystemInfo = OdeSystemInformation<Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLRushLarsenOpt>::Instance();
        Init();
        
    }

    Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLRushLarsenOpt::~Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLRushLarsenOpt()
    {
    }

    AbstractLookupTableCollection* Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLRushLarsenOpt::GetLookupTableCollection()
    {
        return Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLRushLarsenOpt_LookupTables::Instance();
    }
    
    double Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLRushLarsenOpt::GetIIonic(const std::vector<double>* pStateVariables)
    {
        // For state variable interpolation (SVI) we read in interpolated state variables,
        // otherwise for ionic current interpolation (ICI) we use the state variables of this model (node).
        if (!pStateVariables) pStateVariables = &rGetStateVariables();
        const std::vector<double>& rY = *pStateVariables;
        double var_chaste_interface__membrane__V = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : rY[0]);
        // Units: millivolt; Initial value: -75.0
        double var_chaste_interface__sodium_channel_m_gate__m = rY[1];
        // Units: dimensionless; Initial value: 0.05
        double var_chaste_interface__sodium_channel_h_gate__h = rY[2];
        // Units: dimensionless; Initial value: 0.6
        double var_chaste_interface__potassium_channel_n_gate__n = rY[3];
        // Units: dimensionless; Initial value: 0.325
        

        const double var_leakage_current__i_L = 19.316099999999999 + 0.29999999999999999 * var_chaste_interface__membrane__V; // microA_per_cm2
        const double var_potassium_channel__i_K = 36.0 * pow(var_chaste_interface__potassium_channel_n_gate__n, 4) * (87.0 + var_chaste_interface__membrane__V); // microA_per_cm2
        const double var_sodium_channel__i_Na = 120.0 * pow(var_chaste_interface__sodium_channel_m_gate__m, 3) * (-40.0 + var_chaste_interface__membrane__V) * var_chaste_interface__sodium_channel_h_gate__h; // microA_per_cm2
        const double var_chaste_interface__i_ionic = var_leakage_current__i_L + var_potassium_channel__i_K + var_sodium_channel__i_Na; // uA_per_cm2

        const double i_ionic = var_chaste_interface__i_ionic;
        EXCEPT_IF_NOT(!std::isnan(i_ionic));
        return i_ionic;
    }

    void Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLRushLarsenOpt::EvaluateEquations(double var_chaste_interface__environment__time, std::vector<double> &rDY, std::vector<double> &rAlphaOrTau, std::vector<double> &rBetaOrInf)
    {
        std::vector<double>& rY = rGetStateVariables();
        double var_chaste_interface__membrane__V = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : rY[0]);
        // Units: millivolt; Initial value: -75.0
        double var_chaste_interface__sodium_channel_m_gate__m = rY[1];
        // Units: dimensionless; Initial value: 0.05
        double var_chaste_interface__sodium_channel_h_gate__h = rY[2];
        // Units: dimensionless; Initial value: 0.6
        double var_chaste_interface__potassium_channel_n_gate__n = rY[3];
        // Units: dimensionless; Initial value: 0.325

        // Lookup table indexing
        const bool _oob_0 = Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLRushLarsenOpt_LookupTables::Instance()->CheckIndex0(var_chaste_interface__membrane__V);
// LCOV_EXCL_START
        if (_oob_0)
            EXCEPTION(DumpState("membrane_voltage outside lookup table range", rY , var_chaste_interface__environment__time));
// LCOV_EXCL_STOP
        const double* const _lt_0_row = Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLRushLarsenOpt_LookupTables::Instance()->IndexTable0(var_chaste_interface__membrane__V);

        // Mathematics
        double d_dt_chaste_interface_var_membrane__V;
        const double var_potassium_channel_n_gate__alpha_n = _lt_0_row[0]; // per_millisecond
        const double var_potassium_channel_n_gate__beta_n = 0.125 * _lt_0_row[1]; // per_millisecond
        const double var_sodium_channel_h_gate__alpha_h = 0.070000000000000007 * _lt_0_row[2]; // per_millisecond
        const double var_sodium_channel_h_gate__beta_h = _lt_0_row[3]; // per_millisecond
        const double var_sodium_channel_m_gate__alpha_m = _lt_0_row[4]; // per_millisecond
        const double var_sodium_channel_m_gate__beta_m = 4.0 * _lt_0_row[5]; // per_millisecond

        if (mSetVoltageDerivativeToZero)
        {
            d_dt_chaste_interface_var_membrane__V = 0.0;
        }
        else
        {
            const double var_leakage_current__g_L = 0.29999999999999999; // milliS_per_cm2
            const double var_membrane__Cm = 1.0; // microF_per_cm2
            const double var_membrane__E_R = -75.0; // millivolt
            const double var_leakage_current__E_L = 10.613 + var_membrane__E_R; // millivolt
            const double var_leakage_current__i_L = (-var_leakage_current__E_L + var_chaste_interface__membrane__V) * var_leakage_current__g_L; // microA_per_cm2
            const double var_membrane__i_Stim = GetIntracellularAreaStimulus(var_chaste_interface__environment__time); // microA_per_cm2
            const double var_potassium_channel__E_K = -12.0 + var_membrane__E_R; // millivolt
            const double var_potassium_channel__g_K = 36.0; // milliS_per_cm2
            const double var_potassium_channel__i_K = pow(var_chaste_interface__potassium_channel_n_gate__n, 4) * (-var_potassium_channel__E_K + var_chaste_interface__membrane__V) * var_potassium_channel__g_K; // microA_per_cm2
            const double var_sodium_channel__E_Na = 115.0 + var_membrane__E_R; // millivolt
            const double var_sodium_channel__g_Na = 120.0; // milliS_per_cm2
            const double var_sodium_channel__i_Na = pow(var_chaste_interface__sodium_channel_m_gate__m, 3) * (-var_sodium_channel__E_Na + var_chaste_interface__membrane__V) * var_sodium_channel__g_Na * var_chaste_interface__sodium_channel_h_gate__h; // microA_per_cm2
            d_dt_chaste_interface_var_membrane__V = (-var_leakage_current__i_L - var_membrane__i_Stim - var_potassium_channel__i_K - var_sodium_channel__i_Na) / var_membrane__Cm; // millivolt / millisecond
        }
        
        rDY[0] = d_dt_chaste_interface_var_membrane__V;
        rAlphaOrTau[1] = var_sodium_channel_m_gate__alpha_m;
        rBetaOrInf[1] = var_sodium_channel_m_gate__beta_m;
        rAlphaOrTau[2] = var_sodium_channel_h_gate__alpha_h;
        rBetaOrInf[2] = var_sodium_channel_h_gate__beta_h;
        rAlphaOrTau[3] = var_potassium_channel_n_gate__alpha_n;
        rBetaOrInf[3] = var_potassium_channel_n_gate__beta_n;
    }
    void Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLRushLarsenOpt::ComputeOneStepExceptVoltage(const std::vector<double> &rDY, const std::vector<double> &rAlphaOrTau, const std::vector<double> &rBetaOrInf)
    {

        std::vector<double>& rY = rGetStateVariables();
        
        {
            const double tau_inv = rAlphaOrTau[1] + rBetaOrInf[1];
            const double y_inf = rAlphaOrTau[1] / tau_inv;
            rY[1] = y_inf + (rY[1] - y_inf)*exp(-mDt*tau_inv);
        }
        {
            const double tau_inv = rAlphaOrTau[2] + rBetaOrInf[2];
            const double y_inf = rAlphaOrTau[2] / tau_inv;
            rY[2] = y_inf + (rY[2] - y_inf)*exp(-mDt*tau_inv);
        }
        {
            const double tau_inv = rAlphaOrTau[3] + rBetaOrInf[3];
            const double y_inf = rAlphaOrTau[3] / tau_inv;
            rY[3] = y_inf + (rY[3] - y_inf)*exp(-mDt*tau_inv);
        }
    }

    std::vector<double> Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLRushLarsenOpt::ComputeDerivedQuantities(double var_chaste_interface__environment__time, const std::vector<double> & rY)
    {
        // Inputs:
        // Time units: millisecond
        

        // Mathematics
        const double var_membrane__i_Stim = GetIntracellularAreaStimulus(var_chaste_interface__environment__time); // microA_per_cm2

        std::vector<double> dqs(2);
        dqs[0] = var_membrane__i_Stim;
        dqs[1] = var_chaste_interface__environment__time;
        return dqs;
    }

template<>
void OdeSystemInformation<Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLRushLarsenOpt>::Initialise(void)
{
    this->mSystemName = "hodgkin_huxley_squid_axon_model_1952_modified";
    this->mFreeVariableName = "time";
    this->mFreeVariableUnits = "millisecond";

    // rY[0]:
    this->mVariableNames.push_back("membrane_voltage");
    this->mVariableUnits.push_back("millivolt");
    this->mInitialConditions.push_back(-75.0);

    // rY[1]:
    this->mVariableNames.push_back("sodium_channel_m_gate__m");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.05);

    // rY[2]:
    this->mVariableNames.push_back("sodium_channel_h_gate__h");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.6);

    // rY[3]:
    this->mVariableNames.push_back("potassium_channel_n_gate__n");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.325);

    // Derived Quantity index [0]:
    this->mDerivedQuantityNames.push_back("membrane_stimulus_current");
    this->mDerivedQuantityUnits.push_back("microA_per_cm2");

    // Derived Quantity index [1]:
    this->mDerivedQuantityNames.push_back("time");
    this->mDerivedQuantityUnits.push_back("millisecond");

    this->mInitialised = true;
}

// Serialization for Boost >= 1.36
#include "SerializationExportWrapperForCpp.hpp"
CHASTE_CLASS_EXPORT(Cellhodgkin_huxley_squid_axon_model_1952_modifiedFromCellMLRushLarsenOpt)

