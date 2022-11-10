#include "SubPopulation.h"

#include"Demand/Motive.h"
#include"Demand/Trip.h"
#include"Demand/Population.h"
#include <iostream>       // std::cerr
#include <stdexcept>      // std::out_of_range

using namespace SymuCore;

SubPopulation::SubPopulation()
{
    m_dbInitialWalkSpeed = -1;
    m_dbInitialWalkRadius = -1;
    m_pPopulation = NULL;
    m_pMotive = NULL;
    m_costFunctionWeightMap[CF_TravelTime] = 1;
}

SubPopulation::SubPopulation(const std::string& strName)
{
    m_strName = strName;
    m_dbInitialWalkSpeed = -1;
    m_dbInitialWalkRadius = -1;
    m_pPopulation = NULL;
    m_pMotive = NULL;
    m_costFunctionWeightMap[CF_TravelTime] = 1;
}

SubPopulation::~SubPopulation()
{
}

std::string SubPopulation::GetStrName() const
{
    return m_strName;
}

void SubPopulation::SetStrName(const std::string &strName)
{
    m_strName = strName;
}

Motive *SubPopulation::GetMotive() const
{
    return m_pMotive;
}

void SubPopulation::SetMotive(Motive *Motive)
{
    m_pMotive = Motive;
}

void SubPopulation::SetPopulation(Population *pPopulation)
{
    m_pPopulation = pPopulation;
}

Population *SubPopulation::GetPopulation() const
{
    return m_pPopulation;
}

void SubPopulation::SetInitialWalkSpeed(double dbWalkSpeed)
{
    m_dbInitialWalkSpeed = dbWalkSpeed;
}

double SubPopulation::GetInitialWalkSpeed() const
{
    if (m_dbInitialWalkSpeed == -1)
        return m_pPopulation->GetInitialWalkSpeed();

    return m_dbInitialWalkSpeed;
}

void SubPopulation::SetInitialWalkRadius(double dbWalkRadius)
{
    m_dbInitialWalkRadius = dbWalkRadius;
}

double SubPopulation::GetInitialWalkRadius() const
{
    if (m_dbInitialWalkRadius == -1)
        return m_pPopulation->GetInitialWalkRadius();

    return m_dbInitialWalkRadius;
}

const std::vector<Trip *> &SubPopulation::GetListUsers() const
{
    return m_listUsers;
}

std::vector<Trip *> &SubPopulation::GetListUsers()
{
    return m_listUsers;
}

void SubPopulation::SetListUsers(const std::vector<Trip *> &listUsers)
{
    m_listUsers = listUsers;
}


double SubPopulation::GetCostFunctionWeight(CostFunction function) const
{
    try{
	    return m_costFunctionWeightMap.at(function);
    }
    catch (const std::out_of_range& oor) {
        //If weight not found, it is not defined, and we consider it 0
        return 0;
    }
    catch(const std::exception e){
        std::cerr << "Unexpected Error: " << e.what() << '\n';
        return 0;
    }
}


void SubPopulation::SetCostFunctionWeight(CostFunction function, double dWeight)
{
    m_costFunctionWeightMap[function] = dWeight;
}

std::map<CostFunction, double> SubPopulation::GetCostFunctionWeightMap() const
{
    return m_costFunctionWeightMap;
}