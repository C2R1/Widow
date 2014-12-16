#include "Generator.h"

#include <string>
#include <sstream>
#include <fstream>
#include <unistd.h>
#include <cmath>  
#include <cstdlib>
#include <iostream>

Generator::Generator()
{
  population.generatePop(1000);
  writeVector("posServo");
}

Generator::~Generator()
{

}

void Generator::writeVector(std::string basename)
{
  std::vector<std::vector<int>> inds = population.getInds();
  for(auto i = 0; i < population.size(); ++i)
  {
    std::ofstream fs(basename + std::to_string(i));
		if(!fs)
		{
		  std::cerr<<"Cannot open the output file."<<std::endl;
		  return ;
		}
		
		std::vector<int> ind = inds.at(i);
		
		for(auto it = ind.begin(); it != ind.end(); ++it)
      fs << *it << std::endl;
  
    fs.close();
  }    
}

void Generator::evaluatePop(std::string filename)
{
  for(auto i = 0; i < population.size(); ++i)
  {
    std::ifstream fs(filename + std::to_string(i));
		if(!fs)
		{
		  std::cerr<<"Cannot open the output file."<<std::endl;
		  return ;
		}
		
		std::string sx, sy, sz;
		double x, y, z;
				
		std::getline(fs, sx);
		std::getline(fs, sy);
		std::getline(fs, sz);
		//Avoid ','
		replace(sx, ",", ".");
		replace(sy, ",", ".");
		replace(sz, ",", ".");
		//Converts string into double
    x = std::atof(sx.c_str());
    y = std::atof(sy.c_str());
    z = std::atof(sz.c_str());
		//Set the Score
		population.setValue(i, std::abs(z)*100-std::abs(x)-std::abs(y));
   
    fs.close();
  }
  
  population.sortPop();
  population.mutatePop();
  population.generateNewPop();
}

void Generator::launchSim()
{
   system("cd ~/Téléchargements/V-REP_PRO_EDU_V3_1_3_rev2b_64_Linux/; sh vrep.sh -s -q /home/AmarOk/Projets/hexapod.ttt");
}

bool Generator::replace(std::string& str, const std::string& from, const std::string& to)
{
  size_t start_pos = str.find(from);
  if(start_pos == std::string::npos)
    return false;
  str.replace(start_pos, from.length(), to);
    return true;
}
