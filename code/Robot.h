#pragma once

#include "Leg.h"
#include <vector>

class Robot
{
public:
  Robot();
  ~Robot();
  void addLeg(int nbOrders);
  void addLeg(Leg* leg);
  int nbLegs() { return legs->size(); };
  
private:
	std::vector<Leg*> *legs;
};
