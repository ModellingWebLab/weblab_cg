#ifdef CHASTE_CVODE
#ifndef CELLESPINOSA_MODEL_1998_NORMALFROMCELLMLCVODEOPT_HPP_
#define CELLESPINOSA_MODEL_1998_NORMALFROMCELLMLCVODEOPT_HPP_

//! @file
//!
//! This source file was generated from CellML by chaste_codegen version (version omitted as unimportant)
//!
//! Model: espinosa_model_1998_normal
//!
//! Processed by chaste_codegen: https://github.com/ModellingWebLab/chaste-codegen
//!     (translator: chaste_codegen, model type: AnalyticCvodeOpt)
//! on (date omitted as unimportant)
//!
//! <autogenerated>

#include "ChasteSerialization.hpp"
#include <boost/serialization/base_object.hpp>
#include "AbstractStimulusFunction.hpp"
#include "AbstractCvodeCell.hpp"

class Cellespinosa_model_1998_normalFromCellMLCvodeOpt : public AbstractCvodeCell
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
    Cellespinosa_model_1998_normalFromCellMLCvodeOpt(boost::shared_ptr<AbstractIvpOdeSolver> pOdeSolver /* unused; should be empty */, boost::shared_ptr<AbstractStimulusFunction> pIntracellularStimulus);
    ~Cellespinosa_model_1998_normalFromCellMLCvodeOpt();
    AbstractLookupTableCollection* GetLookupTableCollection();
    double GetIIonic(const std::vector<double>* pStateVariables=NULL);
    void EvaluateYDerivatives(double var_chaste_interface__environment__time_converted, const N_Vector rY, N_Vector rDY);
    N_Vector ComputeDerivedQuantities(double var_chaste_interface__environment__time_converted, const N_Vector & rY);
    void EvaluateAnalyticJacobian(double var_chaste_interface__environment__time_converted, N_Vector rY, N_Vector rDY, CHASTE_CVODE_DENSE_MATRIX rJacobian, N_Vector rTmp1, N_Vector rTmp2, N_Vector rTmp3);
};

// Needs to be included last
#include "SerializationExportWrapper.hpp"
CHASTE_CLASS_EXPORT(Cellespinosa_model_1998_normalFromCellMLCvodeOpt)

namespace boost
{
    namespace serialization
    {
        template<class Archive>
        inline void save_construct_data(
            Archive & ar, const Cellespinosa_model_1998_normalFromCellMLCvodeOpt * t, const unsigned int fileVersion)
        {
            const boost::shared_ptr<AbstractIvpOdeSolver> p_solver = t->GetSolver();
            const boost::shared_ptr<AbstractStimulusFunction> p_stimulus = t->GetStimulusFunction();
            ar << p_solver;
            ar << p_stimulus;
        }

        template<class Archive>
        inline void load_construct_data(
            Archive & ar, Cellespinosa_model_1998_normalFromCellMLCvodeOpt * t, const unsigned int fileVersion)
        {
            boost::shared_ptr<AbstractIvpOdeSolver> p_solver;
            boost::shared_ptr<AbstractStimulusFunction> p_stimulus;
            ar >> p_solver;
            ar >> p_stimulus;
            ::new(t)Cellespinosa_model_1998_normalFromCellMLCvodeOpt(p_solver, p_stimulus);
        }

    }

}

#endif // CELLESPINOSA_MODEL_1998_NORMALFROMCELLMLCVODEOPT_HPP_
#endif // CHASTE_CVODE