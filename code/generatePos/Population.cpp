#include "Population.h"

#include <random>
#include <iostream>
#include <map>
#include <algorithm>
#include <fstream>

Population::Population()
{
  _mutatePercent = 5;
}

Population::~Population()
{

}

/**
 * Generate a std::vector<int>
 * @param: nbServo: the size of the vector
 * @param: borneMin: the min of the int
 * @param: borneMax: the max of the int
 * @return the vector
 */
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

/**
 * Generate the first population
 * @param: nbInd: the size of the population
 */
void Population::generatePop(int nbInd)
{
  for(auto i = 0; i < nbInd; ++i)
    posServos.push_back(std::make_pair(generatePosServo(21,0,180),0));
}

/**
 * Generate a new generation
 */
void Population::generateNewPop()
{
  auto nbInd = posServos.size();
  std::vector<std::pair<std::vector<int>, double>> newPop;
  //1/4 best
  for(auto i = 0; i < nbInd/4; ++i)
    newPop.push_back(std::make_pair(posServos.at(i).first, 0.));
    
  //1/2 crossOver
  auto weight = (1/2)*(posServos.size()-1)*posServos.size(); 
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, weight);
  for(auto i = 0; i < nbInd/2; ++i)
    newPop.push_back(std::make_pair(crossOver(posServos.at(decNumber(dis(gen))).first,
                                              posServos.at(decNumber(dis(gen))).first), 0.));
  
  //1/4 new ind  
  for(auto i = 0; i < nbInd; ++i)
    posServos.push_back(std::make_pair(generatePosServo(21,0,180),0));
  posServos = newPop;
}


/**
 * @return all individuals of the population
 */
std::vector<std::vector<int>> Population::getInds()
{
  std::vector<std::vector<int>> result;
  for(std::vector<std::pair<std::vector<int>, double>>::iterator it = posServos.begin(); it != posServos.end(); ++it)
    result.push_back(it->first);
  return result;
}

/**
 * Set the score of an individual
 * @param: ind: the position of the individual
 * @param: score: the score to set
 */
void Population::setValue(int ind, double score)
{
  posServos.at(ind).second = score;
}

/**
 * @return: a string which represent the best individual
 */
std::string Population::best()
{
  std::string res = std::to_string(posServos.at(0).second) + " [";
  
  std::vector<int> temp = posServos.at(0).first;
  for(auto i = 0; i < temp.size(); ++i)
    res += std::to_string(temp.at(i)) + ";";
  return res + "]";
}

/**
 * Mutate one int of a std::vector<int>
 * @param: ind: the pos of the individual to mutate
 */
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

/**
 * Mutate all the population with a probability of _mutatePercent
 */
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
}

/**
 * Sort the population with the score
 */
void Population::sortPop()
{
  //Sort list
  std::sort(posServos.begin(), posServos.end(),
  [=](std::pair<std::vector<int>, double> A, std::pair<std::vector<int>, double> B)
	{
		return A.second > B.second;
	});
}

/**
 * Mix 2 vector<int>
 * @param: v1: first vector
 * @param: v2: second vector
 * @return the result of the mixing
 */
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

/**
 * Find the number x where x! <= nb <=  (x+1)!
 */
int Population::decNumber(int nb)
{
  int res = 0;
  
  while(nb > (res*(res+1))/2)
    ++res;
  
  return res;
}

void Population::debugWP(std::string filename)
{
  std::ofstream fs(filename);
	if(!fs)
	{
	 std::cerr<<"Cannot open the output file."<<std::endl;
	 return ;
	}
	for(std::vector<std::pair<std::vector<int>, double>>::iterator it = posServos.begin(); it != posServos.end(); ++it)
  {
    std::vector<int> temp =  it->first;
	  fs << "[";
	  for(auto i = 0; i < temp.size(); ++i)
	    fs << temp.at(i) << ";";
	  fs << ", " << it->second << "]" << std::endl;
  }
  fs.close();
}
