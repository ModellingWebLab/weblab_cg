#ifndef DYNAMICZHANG_SAN_MODEL_2000_ALLFROMCELLMLBACKWARDEULER_HPP_
#define DYNAMICZHANG_SAN_MODEL_2000_ALLFROMCELLMLBACKWARDEULER_HPP_

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

#include "ChasteSerialization.hpp"
#include <boost/serialization/base_object.hpp>
#include "AbstractBackwardEulerCardiacCell.hpp"
#include "AbstractDynamicallyLoadableEntity.hpp"
#include "AbstractStimulusFunction.hpp"

class Dynamiczhang_SAN_model_2000_allFromCellMLBackwardEuler : public AbstractBackwardEulerCardiacCell<0>, public AbstractDynamicallyLoadableEntity
{
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & archive, const unsigned int version)
    {
        archive & boost::serialization::base_object<AbstractBackwardEulerCardiacCell<0> >(*this);
        archive & boost::serialization::base_object<AbstractDynamicallyLoadableEntity>(*this);
    }
    
    // 
    // Settable parameters and readable variables
    // 
    
public:
    Dynamiczhang_SAN_model_2000_allFromCellMLBackwardEuler(boost::shared_ptr<AbstractIvpOdeSolver> /* unused; should be empty */, boost::shared_ptr<AbstractStimulusFunction> pIntracellularStimulus);
    ~Dynamiczhang_SAN_model_2000_allFromCellMLBackwardEuler();
    double GetIIonic(const std::vector<double>* pStateVariables=NULL);
protected:
    void UpdateTransmembranePotential(double var_chaste_interface__environment__time);
    void ComputeOneStepExceptVoltage(double var_chaste_interface__environment__time);
};


// Needs to be included last
#include "SerializationExportWrapper.hpp"
CHASTE_CLASS_EXPORT(Dynamiczhang_SAN_model_2000_allFromCellMLBackwardEuler)

namespace boost
{
    namespace serialization
    {
        template<class Archive>
        inline void save_construct_data(
            Archive & ar, const Dynamiczhang_SAN_model_2000_allFromCellMLBackwardEuler * t, const unsigned int fileVersion)
        {
            const boost::shared_ptr<AbstractIvpOdeSolver> p_solver = t->GetSolver();
            const boost::shared_ptr<AbstractStimulusFunction> p_stimulus = t->GetStimulusFunction();
            ar << p_solver;
            ar << p_stimulus;
        }
        
        template<class Archive>
        inline void load_construct_data(
            Archive & ar, Dynamiczhang_SAN_model_2000_allFromCellMLBackwardEuler * t, const unsigned int fileVersion)
        {
            boost::shared_ptr<AbstractIvpOdeSolver> p_solver;
            boost::shared_ptr<AbstractStimulusFunction> p_stimulus;
            ar >> p_solver;
            ar >> p_stimulus;
            ::new(t)Dynamiczhang_SAN_model_2000_allFromCellMLBackwardEuler(p_solver, p_stimulus);
        }
        
    }
    
}

#endif // DYNAMICZHANG_SAN_MODEL_2000_ALLFROMCELLMLBACKWARDEULER_HPP_
