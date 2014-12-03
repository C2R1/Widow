#include "Generator.h"

#include <string>
#include <random>
#include <fstream>

Generator::Generator()
{

}

Generator::~Generator()
{

}

void Generator::generatePosServo(int nbServo, int borneMin, int borneMax)
{
  posServos.clear();
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(borneMin, borneMax);
 
  for(auto i = 0; i < nbServo; ++i)
    posServos.push_back(dis(gen));
}

void Generator::writeVector(std::string filename)
{
  std::ofstream fs(filename); 
  if(!fs)
  {
    std::cerr<<"Cannot open the output file."<<std::endl;
    return ;
  }
  
  for(auto it = posServos.begin(); it != posServos.end(); ++it)
    fs << *it << std::endl;
    
  fs.close();
}
