#pragma once

#include <vector>
#include <iostream>

class Generator
{
  public:
    Generator();
    ~Generator();
    void generatePosServo(int nbServo, int borneMin = 0, int borneMax = 180);
    void writeVector(std::string filename);
    void launchSim();
    
  private:
    std::vector<int> posServos;
};
