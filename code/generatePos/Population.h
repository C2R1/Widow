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
    void setValue(int ind, float score);
    
  private:
    std::map<std::vector<int>, float> posServos;
};

