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
    static bool replace(std::string& str, const std::string& from, const std::string& to);
    
  private:
    Population population;
};
