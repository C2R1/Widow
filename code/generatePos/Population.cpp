#include "Population.h"

#include <random>
#include <iostream>
#include <map> 

Population::Population()
{

}

Population::~Population()
{

}

void Population::generatePop(int nbInd)
{
  for(auto i = 0; i < nbInd; ++i)
    posServos.insert(std::make_pair(generatePosServo(18,0,180),0));
}

std::vector<int> Population::generatePosServo(int nbServo, int borneMin, int borneMax)
{
  std::vector<int> posServos;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(borneMin, borneMax);
 
  for(auto i = 0; i < nbServo; ++i)
    posServos.push_back(dis(gen));
    
  return posServos;
}

std::vector<std::vector<int>> Population::getInds()
{
  std::vector<std::vector<int>> result;
  for(std::map<std::vector<int>,int>::iterator it = posServos.begin(); it != posServos.end(); ++it)
    result.push_back(it->first);
  return result;
}

int Population::size()
{
 return posServos.size();
}
