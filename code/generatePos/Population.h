#ifndef POPULATION_H
#define POPULATION_H

#include <vector>
#include <iostream>
#include <map>

class Population
{
  public:
    Population();
    ~Population();
    void generatePop(int nbInd);
    void generateNewPop();
    std::vector<int> generatePosServo(int nbServo, int borneMin, int borneMax);
    std::vector<std::vector<int>> getInds();
    int size();
    void setValue(int ind, double score);
		void sortPop();
		void mutateInd(int ind);
		void mutatePop();
		std::vector<int> crossOver(std::vector<int> v1, std::vector<int> v2);
		
		int decNumber(int nb);
    
  private:
    std::vector<std::pair<std::vector<int>, double>> posServos;
    int _mutatePercent;
};

#endif
