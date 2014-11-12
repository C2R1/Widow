#include "Robot.h"

Robot::Robot()
{
  legs = new std::vector<Leg*>();
}

Robot::~Robot()
{
  delete legs;
}

void Robot::addLeg(int nbOrders)
{
	Leg *leg = new Leg();
	leg->generateOrders(nbOrders);
	legs->push_back(leg);
}

void Robot::addLeg(Leg* leg)
{
	legs->push_back(leg);
}
