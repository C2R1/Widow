#pragma once

#include <vector>
#include <iostream>
#include <map>

class Population
{
  public:
    Population();
    ~Population();
    void generatePop(int nbInd);
    std::vector<int> generatePosServo(int nbServo, int borneMin, int borneMax);
    std::vector<std::vector<int>> getInds();
    int size();
    
  private:
    std::map<std::vector<int>, int> posServos;
};

