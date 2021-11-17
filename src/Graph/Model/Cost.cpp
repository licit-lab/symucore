﻿#include "Cost.h"

#include <limits>
#include <iostream>       // std::cerr
#include <stdexcept>      // std::out_of_range

using namespace SymuCore;

Cost::Cost(double dCostValue, CostFunction eCostFunction)
{
    setUsedCostFunction(eCostFunction);
    setCostValue(eCostFunction,dCostValue);
}

Cost::~Cost()
{

}

void Cost::setUsedCostFunction(CostFunction eCostFunction)
{
    m_usedCostFunction = eCostFunction;
}

void Cost::setCostValue(CostFunction eCostFunction, double dbValue)
{
    m_costsMap[eCostFunction] = dbValue;
}

double Cost::getCostValue(CostFunction eCostFunction) const
{
    std::map<CostFunction, double>::const_iterator iter = m_costsMap.find(eCostFunction);
    if (iter != m_costsMap.end())
    {
        return iter->second;
    }
    else
    {
        return 0;
    }
}

double Cost::getCostValue() const
{
    try{
	    return m_costsMap.at(m_usedCostFunction);
    }
    catch (const std::out_of_range& oor) {
        //If Cost not found, it is not yet defined
        return 0;
    }
    catch(const std::exception e){
        std::cerr << "Unexpected Error in Cost: " << e.what() << '\n';
        return 0;
    }
}

// OTK - TODO - Pourquoi pas un vrai opérateur + ?
void Cost::plus(Cost * otherCost)
{
    CostFunction key;
    if(!otherCost)
    {
        for(std::map<CostFunction, double>::iterator it = m_costsMap.begin(); it != m_costsMap.end(); ++it) {
            key = it->first;
            m_costsMap[key] = std::numeric_limits<double>::infinity();
        }
    }
    else
    {
        for(std::map<CostFunction, double>::iterator it = m_costsMap.begin(); it != m_costsMap.end(); ++it) {
            key = it->first;
            m_costsMap[key] += otherCost->getCostValue(key);
        }
    }
}

void Cost::sumCostFunctions(std::map<CostFunction, double> weights)
{
    m_costsMap[CF_Total_Cost_Sum] = 0;
    for(std::map<CostFunction, double>::iterator it = weights.begin(); it != weights.end(); ++it) {
        double weightedCost = 0;
        try{
            weightedCost = m_costsMap.at(it->first) * it->second;
        }
        catch (const std::out_of_range& oor) {
            //If Cost not found, it is not yet defined
            weightedCost = std::numeric_limits<double>::infinity();
        }
        catch(const std::exception e){
            std::cerr << "Unexpected Error in Cost Sum: " << e.what() << '\n';
        }
        m_costsMap[CF_Total_Cost_Sum] += weightedCost;
    }
    setUsedCostFunction(CF_Total_Cost_Sum);
}
