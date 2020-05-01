#ifndef CELLHUND_RUDY_2004_AFROMCELLMLGRL1_HPP_
#define CELLHUND_RUDY_2004_AFROMCELLMLGRL1_HPP_

//! @file
//!
//! This source file was generated from CellML by chaste_codegen version 0.0.1
//!
//! Model: hund_rudy_2004
//!
//! Processed by chaste_codegen: https://github.com/ModellingWebLab/chaste-codegen
//!     (translator: chaste_codegen)
//! on (date omitted as unimportant)
//!
//! <autogenerated>

#include "ChasteSerialization.hpp"
#include <boost/serialization/base_object.hpp>

#include "AbstractStimulusFunction.hpp"
#include "AbstractGeneralizedRushLarsenCardiacCell.hpp"

class Cellhund_rudy_2004_aFromCellMLGRL1 : public AbstractGeneralizedRushLarsenCardiacCell
{
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & archive, const unsigned int version)
    {
        archive & boost::serialization::base_object<AbstractGeneralizedRushLarsenCardiacCell >(*this);
        
    }

    //
    // Settable parameters and readable variables
    //

public:

    boost::shared_ptr<RegularStimulus> UseCellMLDefaultStimulus();
    double GetIntracellularCalciumConcentration();
    Cellhund_rudy_2004_aFromCellMLGRL1(boost::shared_ptr<AbstractIvpOdeSolver> /* unused; should be empty */, boost::shared_ptr<AbstractStimulusFunction> pIntracellularStimulus);
    ~Cellhund_rudy_2004_aFromCellMLGRL1();
    double GetIIonic(const std::vector<double>* pStateVariables=NULL);
    void UpdateTransmembranePotential(double var_chaste_interface__Environment__time);
    void ComputeOneStepExceptVoltage(double var_chaste_interface__Environment__time);
    
    double EvaluateYDerivative0(double var_chaste_interface__Environment__time, std::vector<double>& rY);
    double EvaluatePartialDerivative0(double var_chaste_interface__Environment__time, std::vector<double>& rY, double delta, bool forceNumerical=false);
    double EvaluateYDerivative1(double var_chaste_interface__Environment__time, std::vector<double>& rY);
    double EvaluatePartialDerivative1(double var_chaste_interface__Environment__time, std::vector<double>& rY, double delta, bool forceNumerical=false);
    double EvaluateYDerivative2(double var_chaste_interface__Environment__time, std::vector<double>& rY);
    double EvaluatePartialDerivative2(double var_chaste_interface__Environment__time, std::vector<double>& rY, double delta, bool forceNumerical=false);
    double EvaluateYDerivative3(double var_chaste_interface__Environment__time, std::vector<double>& rY);
    double EvaluatePartialDerivative3(double var_chaste_interface__Environment__time, std::vector<double>& rY, double delta, bool forceNumerical=false);
    double EvaluateYDerivative4(double var_chaste_interface__Environment__time, std::vector<double>& rY);
    double EvaluatePartialDerivative4(double var_chaste_interface__Environment__time, std::vector<double>& rY, double delta, bool forceNumerical=false);
    double EvaluateYDerivative5(double var_chaste_interface__Environment__time, std::vector<double>& rY);
    double EvaluatePartialDerivative5(double var_chaste_interface__Environment__time, std::vector<double>& rY, double delta, bool forceNumerical=false);
    double EvaluateYDerivative6(double var_chaste_interface__Environment__time, std::vector<double>& rY);
    double EvaluatePartialDerivative6(double var_chaste_interface__Environment__time, std::vector<double>& rY, double delta, bool forceNumerical=false);
    double EvaluateYDerivative7(double var_chaste_interface__Environment__time, std::vector<double>& rY);
    double EvaluatePartialDerivative7(double var_chaste_interface__Environment__time, std::vector<double>& rY, double delta, bool forceNumerical=false);
    double EvaluateYDerivative8(double var_chaste_interface__Environment__time, std::vector<double>& rY);
    double EvaluatePartialDerivative8(double var_chaste_interface__Environment__time, std::vector<double>& rY, double delta, bool forceNumerical=false);
    double EvaluateYDerivative9(double var_chaste_interface__Environment__time, std::vector<double>& rY);
    double EvaluatePartialDerivative9(double var_chaste_interface__Environment__time, std::vector<double>& rY, double delta, bool forceNumerical=false);
    double EvaluateYDerivative10(double var_chaste_interface__Environment__time, std::vector<double>& rY);
    double EvaluatePartialDerivative10(double var_chaste_interface__Environment__time, std::vector<double>& rY, double delta, bool forceNumerical=false);
    double EvaluateYDerivative11(double var_chaste_interface__Environment__time, std::vector<double>& rY);
    double EvaluatePartialDerivative11(double var_chaste_interface__Environment__time, std::vector<double>& rY, double delta, bool forceNumerical=false);
    double EvaluateYDerivative12(double var_chaste_interface__Environment__time, std::vector<double>& rY);
    double EvaluatePartialDerivative12(double var_chaste_interface__Environment__time, std::vector<double>& rY, double delta, bool forceNumerical=false);
    double EvaluateYDerivative13(double var_chaste_interface__Environment__time, std::vector<double>& rY);
    double EvaluatePartialDerivative13(double var_chaste_interface__Environment__time, std::vector<double>& rY, double delta, bool forceNumerical=false);
    double EvaluateYDerivative14(double var_chaste_interface__Environment__time, std::vector<double>& rY);
    double EvaluatePartialDerivative14(double var_chaste_interface__Environment__time, std::vector<double>& rY, double delta, bool forceNumerical=false);
    double EvaluateYDerivative15(double var_chaste_interface__Environment__time, std::vector<double>& rY);
    double EvaluatePartialDerivative15(double var_chaste_interface__Environment__time, std::vector<double>& rY, double delta, bool forceNumerical=false);
    double EvaluateYDerivative16(double var_chaste_interface__Environment__time, std::vector<double>& rY);
    double EvaluatePartialDerivative16(double var_chaste_interface__Environment__time, std::vector<double>& rY, double delta, bool forceNumerical=false);
    double EvaluateYDerivative17(double var_chaste_interface__Environment__time, std::vector<double>& rY);
    double EvaluatePartialDerivative17(double var_chaste_interface__Environment__time, std::vector<double>& rY, double delta, bool forceNumerical=false);
    double EvaluateYDerivative18(double var_chaste_interface__Environment__time, std::vector<double>& rY);
    double EvaluatePartialDerivative18(double var_chaste_interface__Environment__time, std::vector<double>& rY, double delta, bool forceNumerical=false);
    double EvaluateYDerivative19(double var_chaste_interface__Environment__time, std::vector<double>& rY);
    double EvaluatePartialDerivative19(double var_chaste_interface__Environment__time, std::vector<double>& rY, double delta, bool forceNumerical=false);
    double EvaluateYDerivative20(double var_chaste_interface__Environment__time, std::vector<double>& rY);
    double EvaluatePartialDerivative20(double var_chaste_interface__Environment__time, std::vector<double>& rY, double delta, bool forceNumerical=false);
    double EvaluateYDerivative21(double var_chaste_interface__Environment__time, std::vector<double>& rY);
    double EvaluatePartialDerivative21(double var_chaste_interface__Environment__time, std::vector<double>& rY, double delta, bool forceNumerical=false);
    double EvaluateYDerivative22(double var_chaste_interface__Environment__time, std::vector<double>& rY);
    double EvaluatePartialDerivative22(double var_chaste_interface__Environment__time, std::vector<double>& rY, double delta, bool forceNumerical=false);
    double EvaluateYDerivative23(double var_chaste_interface__Environment__time, std::vector<double>& rY);
    double EvaluatePartialDerivative23(double var_chaste_interface__Environment__time, std::vector<double>& rY, double delta, bool forceNumerical=false);
    double EvaluateYDerivative24(double var_chaste_interface__Environment__time, std::vector<double>& rY);
    double EvaluatePartialDerivative24(double var_chaste_interface__Environment__time, std::vector<double>& rY, double delta, bool forceNumerical=false);
    double EvaluateYDerivative25(double var_chaste_interface__Environment__time, std::vector<double>& rY);
    double EvaluatePartialDerivative25(double var_chaste_interface__Environment__time, std::vector<double>& rY, double delta, bool forceNumerical=false);
    double EvaluateYDerivative26(double var_chaste_interface__Environment__time, std::vector<double>& rY);
    double EvaluatePartialDerivative26(double var_chaste_interface__Environment__time, std::vector<double>& rY, double delta, bool forceNumerical=false);
    double EvaluateYDerivative27(double var_chaste_interface__Environment__time, std::vector<double>& rY);
    double EvaluatePartialDerivative27(double var_chaste_interface__Environment__time, std::vector<double>& rY, double delta, bool forceNumerical=false);
    double EvaluateYDerivative28(double var_chaste_interface__Environment__time, std::vector<double>& rY);
    double EvaluatePartialDerivative28(double var_chaste_interface__Environment__time, std::vector<double>& rY, double delta, bool forceNumerical=false);

    std::vector<double> ComputeDerivedQuantities(double var_chaste_interface__Environment__time, const std::vector<double> & rY);
};

// Needs to be included last
#include "SerializationExportWrapper.hpp"
CHASTE_CLASS_EXPORT(Cellhund_rudy_2004_aFromCellMLGRL1)

namespace boost
{
    namespace serialization
    {
        template<class Archive>
        inline void save_construct_data(
            Archive & ar, const Cellhund_rudy_2004_aFromCellMLGRL1 * t, const unsigned int fileVersion)
        {
            const boost::shared_ptr<AbstractIvpOdeSolver> p_solver = t->GetSolver();
            const boost::shared_ptr<AbstractStimulusFunction> p_stimulus = t->GetStimulusFunction();
            ar << p_solver;
            ar << p_stimulus;
        }

        template<class Archive>
        inline void load_construct_data(
            Archive & ar, Cellhund_rudy_2004_aFromCellMLGRL1 * t, const unsigned int fileVersion)
        {
            boost::shared_ptr<AbstractIvpOdeSolver> p_solver;
            boost::shared_ptr<AbstractStimulusFunction> p_stimulus;
            ar >> p_solver;
            ar >> p_stimulus;
            ::new(t)Cellhund_rudy_2004_aFromCellMLGRL1(p_solver, p_stimulus);
        }

    }

}

#endif // CELLHUND_RUDY_2004_AFROMCELLMLGRL1_HPP_