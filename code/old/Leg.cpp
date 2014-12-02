#include "Leg.h"
#include <iostream>
#include <random>

Leg::Leg()
{
	maxAngle = 360;
}

Leg::Leg(int _maxAngle)
{
	maxAngle = _maxAngle;
}

Leg::~Leg()
{

}

void Leg::generateOrders(int nbOrders)
{

  std::default_random_engine rng(std::random_device{}());
  std::uniform_real_distribution<double> distAngle(0, maxAngle);

	for(int i = 0; i < nbOrders; ++i)
	{
		Order order;
		order.angleServo1 = distAngle(rng);
		order.angleServo2 = distAngle(rng);
		order.angleServo3 = distAngle(rng);
		orders.push_back(order);
	}
}
