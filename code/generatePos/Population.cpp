#include "Population.h"

#include <random>
#include <iostream>
#include <map>
#include <algorithm>

Population::Population()
{

}

Population::~Population()
{

}

void Population::generatePop(int nbInd)
{
  for(auto i = 0; i < nbInd; ++i)
    posServos.push_back(std::make_pair(generatePosServo(21,0,180),0));
}

std::vector<int> Population::generatePosServo(int nbServo, int borneMin, int borneMax)
{
  std::vector<int> _posServos;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(borneMin, borneMax);
 
  for(auto i = 0; i < nbServo; ++i)
    _posServos.push_back(dis(gen));
    
  return _posServos;
}

std::vector<std::vector<int>> Population::getInds()
{
  std::vector<std::vector<int>> result;
  for(std::vector<std::pair<std::vector<int>, double>>::iterator it = posServos.begin(); it != posServos.end(); ++it)
    result.push_back(it->first);
  return result;
}

int Population::size()
{
 return posServos.size();
}

void Population::setValue(int ind, double score)
{
  std::vector<std::vector<int>> result;
  auto i = 0; 
  for(std::vector<std::pair<std::vector<int>, double>>::iterator it = posServos.begin(); it != posServos.end(); ++it)
  {
	  if(i == ind)
		  it->second = score;
		++i;
  }
//  std::cout << score << std::endl;
}
void Population::sortPop()
{
  //Sort list
  std::sort(posServos.begin(), posServos.end(),
  [=](std::pair<std::vector<int>, double> A, std::pair<std::vector<int>, double> B)
	{
		return A.second > B.second;
	});
	
	//Show content
	std::cout << "TRIE" << std::endl;
	for(std::vector<std::pair<std::vector<int>, double>>::iterator it = posServos.begin(); it != posServos.end(); ++it)
  {
    std::vector<int> temp =  it->first;
	  std::cout << "[";
	  for(auto i = 0; i < temp.size(); ++i)
	    std::cout << temp.at(i) << ";";
	  std::cout << ", " << it->second << "]" << std::endl;
  }
}
