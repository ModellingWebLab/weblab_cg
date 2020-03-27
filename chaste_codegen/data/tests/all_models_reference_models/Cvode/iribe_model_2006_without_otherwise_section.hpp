#ifdef CHASTE_CVODE
#ifndef CELLIRIBE_MODEL_2006_WITHOUT_OTHERWISE_SECTIONFROMCELLMLCVODE_HPP_
#define CELLIRIBE_MODEL_2006_WITHOUT_OTHERWISE_SECTIONFROMCELLMLCVODE_HPP_

//! @file
//!
//! This source file was generated from CellML by chaste_codegen version 0.0.1
//!
//! Model: iribe_model_2006
//!
//! Processed by chaste_codegen: https://github.com/ModellingWebLab/chaste-codegen
//!     (translator: chaste_codegen)
//! on 2020-03-25 17:45:13
//!
//! <autogenerated>

#include "ChasteSerialization.hpp"
#include <boost/serialization/base_object.hpp>

#include "AbstractStimulusFunction.hpp"
#include "AbstractCvodeCell.hpp"

class Celliribe_model_2006_without_otherwise_sectionFromCellMLCvode : public AbstractCvodeCell
{
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & archive, const unsigned int version)
    {
        archive & boost::serialization::base_object<AbstractCvodeCell >(*this);
        
    }
    
    // 
    // Settable parameters and readable variables
    // 
    
public:

    boost::shared_ptr<RegularStimulus> UseCellMLDefaultStimulus();
    double GetIntracellularCalciumConcentration();
    Celliribe_model_2006_without_otherwise_sectionFromCellMLCvode(boost::shared_ptr<AbstractIvpOdeSolver> pOdeSolver /* unused; should be empty */, boost::shared_ptr<AbstractStimulusFunction> pIntracellularStimulus);
    ~Celliribe_model_2006_without_otherwise_sectionFromCellMLCvode();
    double GetIIonic(const std::vector<double>* pStateVariables=NULL);
    void EvaluateYDerivatives(double var_chaste_interface__environment__time_converted, const N_Vector rY, N_Vector rDY);
};

// Needs to be included last
#include "SerializationExportWrapper.hpp"
CHASTE_CLASS_EXPORT(Celliribe_model_2006_without_otherwise_sectionFromCellMLCvode)

namespace boost
{
    namespace serialization
    {
        template<class Archive>
        inline void save_construct_data(
            Archive & ar, const Celliribe_model_2006_without_otherwise_sectionFromCellMLCvode * t, const unsigned int fileVersion)
        {
            const boost::shared_ptr<AbstractIvpOdeSolver> p_solver = t->GetSolver();
            const boost::shared_ptr<AbstractStimulusFunction> p_stimulus = t->GetStimulusFunction();
            ar << p_solver;
            ar << p_stimulus;
        }

        template<class Archive>
        inline void load_construct_data(
            Archive & ar, Celliribe_model_2006_without_otherwise_sectionFromCellMLCvode * t, const unsigned int fileVersion)
        {
            boost::shared_ptr<AbstractIvpOdeSolver> p_solver;
            boost::shared_ptr<AbstractStimulusFunction> p_stimulus;
            ar >> p_solver;
            ar >> p_stimulus;
            ::new(t)Celliribe_model_2006_without_otherwise_sectionFromCellMLCvode(p_solver, p_stimulus);
        }

    }

}

#endif // CELLIRIBE_MODEL_2006_WITHOUT_OTHERWISE_SECTIONFROMCELLMLCVODE_HPP_
#endif // CHASTE_CVODE
