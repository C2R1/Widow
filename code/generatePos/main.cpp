#include "Generator.h"

int main()
{
  Generator generator;
  generator.generatePosServo(21);
  generator.writeVector("posServos");
  return 0;
}
