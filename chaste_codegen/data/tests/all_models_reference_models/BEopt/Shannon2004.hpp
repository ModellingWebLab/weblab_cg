#ifndef CELLSHANNON2004FROMCELLMLBACKWARDEULER_HPP_
#define CELLSHANNON2004FROMCELLMLBACKWARDEULER_HPP_

//! @file
//!
//! This source file was generated from CellML by chaste_codegen version (version omitted as unimportant)
//!
//! Model: shannon_wang_puglisi_weber_bers_2004_model_updated
//!
//! Processed by chaste_codegen: https://github.com/ModellingWebLab/chaste-codegen
//!     (translator: chaste_codegen, model type: BackwardEuler)
//! on (date omitted as unimportant)
//!
//! <autogenerated>

#include "ChasteSerialization.hpp"
#include <boost/serialization/base_object.hpp>
#include "AbstractStimulusFunction.hpp"
#include "AbstractBackwardEulerCardiacCell.hpp"

class CellShannon2004FromCellMLBackwardEuler : public AbstractBackwardEulerCardiacCell<32>
{
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & archive, const unsigned int version)
    {
        archive & boost::serialization::base_object<AbstractBackwardEulerCardiacCell<32> >(*this);
        
    }

    //
    // Settable parameters and readable variables
    //

public:

    boost::shared_ptr<RegularStimulus> UseCellMLDefaultStimulus();
    double GetIntracellularCalciumConcentration();
    CellShannon2004FromCellMLBackwardEuler(boost::shared_ptr<AbstractIvpOdeSolver> /* unused; should be empty */, boost::shared_ptr<AbstractStimulusFunction> pIntracellularStimulus);
    ~CellShannon2004FromCellMLBackwardEuler();
    AbstractLookupTableCollection* GetLookupTableCollection();
    double GetIIonic(const std::vector<double>* pStateVariables=NULL);void ComputeResidual(double var_chaste_interface__environment__time, const double rCurrentGuess[32], double rResidual[32]);
    void ComputeJacobian(double var_chaste_interface__environment__time, const double rCurrentGuess[32], double rJacobian[32][32]);protected:
    void UpdateTransmembranePotential(double var_chaste_interface__environment__time);
    void ComputeOneStepExceptVoltage(double var_chaste_interface__environment__time);

    std::vector<double> ComputeDerivedQuantities(double var_chaste_interface__environment__time, const std::vector<double> & rY);
};

// Needs to be included last
#include "SerializationExportWrapper.hpp"
CHASTE_CLASS_EXPORT(CellShannon2004FromCellMLBackwardEuler)

namespace boost
{
    namespace serialization
    {
        template<class Archive>
        inline void save_construct_data(
            Archive & ar, const CellShannon2004FromCellMLBackwardEuler * t, const unsigned int fileVersion)
        {
            const boost::shared_ptr<AbstractIvpOdeSolver> p_solver = t->GetSolver();
            const boost::shared_ptr<AbstractStimulusFunction> p_stimulus = t->GetStimulusFunction();
            ar << p_solver;
            ar << p_stimulus;
        }

        template<class Archive>
        inline void load_construct_data(
            Archive & ar, CellShannon2004FromCellMLBackwardEuler * t, const unsigned int fileVersion)
        {
            boost::shared_ptr<AbstractIvpOdeSolver> p_solver;
            boost::shared_ptr<AbstractStimulusFunction> p_stimulus;
            ar >> p_solver;
            ar >> p_stimulus;
            ::new(t)CellShannon2004FromCellMLBackwardEuler(p_solver, p_stimulus);
        }

    }

}

#endif // CELLSHANNON2004FROMCELLMLBACKWARDEULER_HPP_