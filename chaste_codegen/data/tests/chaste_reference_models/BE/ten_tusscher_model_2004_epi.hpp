#ifndef DYNAMICTEN_TUSSCHER_MODEL_2004_EPIFROMCELLMLBACKWARDEULER_HPP_
#define DYNAMICTEN_TUSSCHER_MODEL_2004_EPIFROMCELLMLBACKWARDEULER_HPP_

//! @file
//! 
//! This source file was generated from CellML.
//! 
//! Model: tentusscher_model_2004_epi
//! 
//! Processed by pycml - CellML Tools in Python
//!     (translators: , pycml: , optimize: )
//! on Wed Mar 11 16:55:15 2020
//! 
//! <autogenerated>

#include "ChasteSerialization.hpp"
#include <boost/serialization/base_object.hpp>
#include "AbstractBackwardEulerCardiacCell.hpp"
#include "AbstractDynamicallyLoadableEntity.hpp"
#include "AbstractStimulusFunction.hpp"

class Dynamicten_tusscher_model_2004_epiFromCellMLBackwardEuler : public AbstractBackwardEulerCardiacCell<6>, public AbstractDynamicallyLoadableEntity
{
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & archive, const unsigned int version)
    {
        archive & boost::serialization::base_object<AbstractBackwardEulerCardiacCell<6> >(*this);
        archive & boost::serialization::base_object<AbstractDynamicallyLoadableEntity>(*this);
    }
    
    // 
    // Settable parameters and readable variables
    // 
    
public:
    boost::shared_ptr<RegularStimulus> UseCellMLDefaultStimulus();
    double GetIntracellularCalciumConcentration();
    Dynamicten_tusscher_model_2004_epiFromCellMLBackwardEuler(boost::shared_ptr<AbstractIvpOdeSolver> /* unused; should be empty */, boost::shared_ptr<AbstractStimulusFunction> pIntracellularStimulus);
    ~Dynamicten_tusscher_model_2004_epiFromCellMLBackwardEuler();
    double GetIIonic(const std::vector<double>* pStateVariables=NULL);
    void ComputeResidual(double var_chaste_interface__environment__time, const double rCurrentGuess[6], double rResidual[6]);
    void ComputeJacobian(double var_chaste_interface__environment__time, const double rCurrentGuess[6], double rJacobian[6][6]);
protected:
    void UpdateTransmembranePotential(double var_chaste_interface__environment__time);
    void ComputeOneStepExceptVoltage(double var_chaste_interface__environment__time);
};


// Needs to be included last
#include "SerializationExportWrapper.hpp"
CHASTE_CLASS_EXPORT(Dynamicten_tusscher_model_2004_epiFromCellMLBackwardEuler)

namespace boost
{
    namespace serialization
    {
        template<class Archive>
        inline void save_construct_data(
            Archive & ar, const Dynamicten_tusscher_model_2004_epiFromCellMLBackwardEuler * t, const unsigned int fileVersion)
        {
            const boost::shared_ptr<AbstractIvpOdeSolver> p_solver = t->GetSolver();
            const boost::shared_ptr<AbstractStimulusFunction> p_stimulus = t->GetStimulusFunction();
            ar << p_solver;
            ar << p_stimulus;
        }
        
        template<class Archive>
        inline void load_construct_data(
            Archive & ar, Dynamicten_tusscher_model_2004_epiFromCellMLBackwardEuler * t, const unsigned int fileVersion)
        {
            boost::shared_ptr<AbstractIvpOdeSolver> p_solver;
            boost::shared_ptr<AbstractStimulusFunction> p_stimulus;
            ar >> p_solver;
            ar >> p_stimulus;
            ::new(t)Dynamicten_tusscher_model_2004_epiFromCellMLBackwardEuler(p_solver, p_stimulus);
        }
        
    }
    
}

#endif // DYNAMICTEN_TUSSCHER_MODEL_2004_EPIFROMCELLMLBACKWARDEULER_HPP_
