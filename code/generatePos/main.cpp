#include "Generator.h"

int main()
{
  Generator generator;
  generator.generatePosServo(21);
  generator.writeVector("posServos");
  generator.launchSim();
  return 0;
}
