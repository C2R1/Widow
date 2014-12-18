#ifndef GENERATOR_H
#define GENERATOR_H

#include <vector>
#include <iostream>

#include "Population.h"

/**
 * Generate and use a Population
 */
class Generator
{
  public:
    Generator();
    ~Generator();
    void writeVector(std::string basename);
    void evaluatePop(std::string filename);
    void launchSim();
    
    static bool replace(std::string& str, const std::string& from, const std::string& to);
    
  private:
    Population population;
};

#endif
