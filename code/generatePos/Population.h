#ifndef POPULATION_H
#define POPULATION_H

#include <vector>
#include <iostream>
#include <map>

/**
 * A population of servos position
 */
class Population
{
  public:
    Population();
    ~Population();
    
    std::vector<int> generatePosServo(int nbServo, int borneMin, int borneMax);
    void generatePop(int nbInd);
    void generateNewPop();
    
    std::vector<std::vector<int>> getInds();
    inline int size() {return posServos.size();};
    void setValue(int ind, double score);
    
		void mutateInd(int ind);
		void mutatePop();
		void sortPop();
		std::vector<int> crossOver(std::vector<int> v1, std::vector<int> v2);
		
		static int decNumber(int nb);
    
  private:
    std::vector<std::pair<std::vector<int>, double>> posServos;
    int _mutatePercent;
};

#endif
