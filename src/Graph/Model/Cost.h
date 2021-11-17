#pragma once

#ifndef SYMUCORE_COST_H
#define SYMUCORE_COST_H

#include "SymuCoreExports.h"

#include "Utils/SymuCoreConstants.h"

#include <map>

#pragma warning(push)
#pragma warning(disable : 4251)

namespace SymuCore {

class SYMUCORE_DLL_DEF Cost {

public:

    Cost(double dCostValue = 0, CostFunction eCostFunction = CF_TravelTime);
    virtual ~Cost();

    //getters
	double getCostValue() const;
    double getCostValue(CostFunction eCostFunction) const;

    //setters
    void setUsedCostFunction(CostFunction eCostFunction);
    void setCostValue(CostFunction eCostFunction, double dbValue);
    void sumCostFunctions(std::map<CostFunction, double> weights);

    void plus(Cost *otherCost);

private:

    CostFunction m_usedCostFunction;
    std::map<CostFunction, double> m_costsMap;
};
}

#pragma warning(pop)

#endif // SYMUCORE_PATTERNSSWITCH_H
