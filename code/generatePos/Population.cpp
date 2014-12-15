#include "Population.h"

#include <random>
#include <iostream>
#include <map>
#include <algorithm>

Population::Population()
{
  _mutatePercent = 5;
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
	/** /
	std::cout << "TRIE" << std::endl;
	for(std::vector<std::pair<std::vector<int>, double>>::iterator it = posServos.begin(); it != posServos.end(); ++it)
  {
    std::vector<int> temp =  it->first;
	  std::cout << "[";
	  for(auto i = 0; i < temp.size(); ++i)
	    std::cout << temp.at(i) << ";";
	  std::cout << ", " << it->second << "]" << std::endl;
  }
  /**/
}

void Population::mutatePop()
{ 
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, 100);
  for(auto i = 0; i < posServos.size(); ++i)
  {
    if(dis(gen) <= _mutatePercent)
      mutateInd(i);
  }
  
	//Show content
	/** /
	std::cout << "TRIE" << std::endl;
	for(std::vector<std::pair<std::vector<int>, double>>::iterator it = posServos.begin(); it != posServos.end(); ++it)
  {
    std::vector<int> temp =  it->first;
	  std::cout << "[";
	  for(auto i = 0; i < temp.size(); ++i)
	    std::cout << temp.at(i) << ";";
	  std::cout << ", " << it->second << "]" << std::endl;
  }
  /**/
}

void Population::mutateInd(int ind)
{
  auto max = posServos.at(0).first.size() - 1;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, max);
  
  std::random_device rd2;
  std::mt19937 gen2(rd2());
  std::uniform_int_distribution<> dis2(0, 180);
 
  posServos.at(ind).first.at(dis(gen)) = dis2(gen2);
}


std::vector<int> Population::crossOver(std::vector<int> v1, std::vector<int> v2)
{
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(1, std::min(v1.size(), v2.size() - 1));
  auto pos = dis(gen);
  
  std::vector<int> res;  
  for(auto i = 0; i < pos && i < v1.size(); ++i)
    res.push_back(v1.at(i));
  for(auto i = pos;i < v2.size(); ++i)
    res.push_back(v2.at(i));
    
  return res;
}
