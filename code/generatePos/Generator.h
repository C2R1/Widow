#pragma once

#include <vector>
#include <iostream>

#include "Population.h"

class Generator
{
  public:
    Generator();
    ~Generator();
    void writeVector(std::string basename);
    void launchSim();
    void evaluatePop(std::string filename);
    
  private:
    Population population;
};
