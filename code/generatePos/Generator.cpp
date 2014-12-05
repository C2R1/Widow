#include "Generator.h"

#include <string>
#include <fstream>
#include <unistd.h>

Generator::Generator()
{
  population.generatePop(1000);
  writeVector("ind");
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

void Generator::launchSim()
{
   system("cd ~/Téléchargements/V-REP_PRO_EDU_V3_1_3_rev2b_64_Linux/; sh vrep.sh -s -q /home/AmarOk/Projets/hexapod.ttt");
}
