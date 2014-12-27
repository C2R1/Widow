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
  _nbSim = 100;
}

Generator::Generator(int nbSim)
{
  population.generatePop(1000);
  _nbSim = nbSim;
}

Generator::~Generator()
{

}

/**
 * Write population into files
 * @param: basename: basename of the file
 */
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

/**
 * Evaluate the current population
 * @param: basename of the output of V-rep
 */
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
}

/**
 * Launch the simulation
 */
void Generator::launchSim()
{
  std::cout << "Simulate WIDOW" << std::endl;
  for(auto i = 0; i < _nbSim; ++i)
  {
    std::cout << "Save Population" << std::endl;
		writeVector("rsc/pos/posServo");
    std::cout << "Launch V-rep" << std::endl;
		system("cd rsc/vrep/; sh vrep.sh -h -s -q ../hexapod.ttt > log_vrep");
    std::cout << "Evaluate Population" << std::endl;
		evaluatePop("rsc/pos/posWidow");
    std::cout << "Sort Population" << std::endl;
		population.sortPop();
		population.debugWP("sorted"+std::to_string(i));
    std::cout << "Best score: " << population.best() << std::endl;
    std::cout << "Mutate Population" << std::endl;
		population.mutatePop();
    std::cout << "Generate new Population - n°" << i+1 << std::endl;
		population.generateNewPop();		
		population.debugWP("nP"+std::to_string(i));
  }
}

/**
 * Replace a string
 * @param: str: the base string
 * @param: from: the string to replace
 * @param: to: the new string wich replace the old string
 * @return if from is present in str
 */
bool Generator::replace(std::string& str, const std::string& from, const std::string& to)
{
  size_t start_pos = str.find(from);
  if(start_pos == std::string::npos)
    return false;
  str.replace(start_pos, from.length(), to);
    return true;
}
