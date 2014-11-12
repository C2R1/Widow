#include <iostream>
#include "Robot.h"

int main()
{
	Robot *hexapode = new Robot();
	hexapode->addLeg(100);
	std::cout << hexapode->nbLegs() << std::endl;
	Leg *leg = new Leg();
	leg->generateOrders(100);
	hexapode->addLeg(leg);
	std::cout << hexapode->nbLegs() << std::endl;
	hexapode->addLeg(100);
	hexapode->addLeg(100);
	hexapode->addLeg(100);
	hexapode->addLeg(100);
	std::cout << hexapode->nbLegs() << std::endl;
	return 0;
}
