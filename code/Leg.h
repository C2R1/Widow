#pragma once
#include <vector>

struct Order
{
	int angleServo1;
	int angleServo2;
	int angleServo3;
};

class Leg
{
public:
  Leg();
  Leg(int _maxAngle);
  ~Leg();
  void generateOrders(int nbOrders);
  std::vector<Order> getOrders() { return orders; };
  
private:
  std::vector<Order> orders;
  int maxAngle;
};
