#pragma once

#ifndef SYMUCORE_NullPenalty_H
#define SYMUCORE_NullPenalty_H

#include "AbstractPenalty.h"

namespace SymuCore {

class SYMUCORE_DLL_DEF NullPenalty : public AbstractPenalty {

public:

    NullPenalty();
    NullPenalty(Node* pParentNode, const PatternsSwitch & patternsSwitch);
    virtual ~NullPenalty();

    virtual void prepareTimeFrames(double startPeriodTime, double endPeriodTime, double travelTimesUpdatePeriod, const std::vector<SubPopulation *> &listSubPopulations, int nbSimulationInstances, int iInstance);
    virtual void fillMeasuredCostsForTravelTimesUpdatePeriod(int iTravelTimesUpdatePeriodIndex, const std::vector<SubPopulation *> &listSubPopulations);

    virtual Cost* getPenaltyCost(int iSimulationInstance, double t, SubPopulation* pSubPopulation);

    virtual void fillFromSecondaryInstance(AbstractPenalty * pFrom, int iInstance);


protected:
    Cost m_NullCost;
};
}

#endif // SYMUCORE_NullPenalty_H
