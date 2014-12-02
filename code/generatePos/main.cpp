#include <vector>
#include <iostream>
#include <string>
#include <random>
#include <fstream>

std::vector<int> generatePosServo(int nbServo, int borneMin = 0, int borneMax = 180)
{
  std::vector<int> result;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(borneMin, borneMax);
 
  for(auto i = 0; i < nbServo; ++i)
    result.push_back(dis(gen));
    
  return result;  
}

void writeVector(std::vector<int> posServo, std::string filename)
{
  std::ofstream fs(filename); 
  if(!fs)
  {
    std::cerr<<"Cannot open the output file."<<std::endl;
    return ;
  }
  
  for(auto it = posServo.begin(); it != posServo.end(); ++it)
    fs << *it << std::endl;
    
  fs.close();
}

int main()
{
  std::vector<int> posServoVect = generatePosServo(21);
  writeVector(posServoVect, "posServos");
  return 0;
}
