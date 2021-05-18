#include "HorsesAndPoniesByRegionReport.h"

HorsesAndPoniesByRegionReport::HorsesAndPoniesByRegionReport(CompareBehaviour<int>* compare)
{
  data = new ReportData<int>(compare);
}
HorsesAndPoniesByRegionReport::~HorsesAndPoniesByRegionReport()
{
  delete data;
}

void HorsesAndPoniesByRegionReport::compute()
{
  Map<string> &regionMapCopy = ReportGenerator::regionMap;
  Map<string> &animalMapCopy = ReportGenerator::animalMap;

  vector<string>& regionMapCopyKeys = regionMapCopy.getKeys();
  vector<string> regionKeys;

  for(int i = 0 ; i < regionMapCopyKeys.size() ; ++i)
  {
    if(regionMapCopyKeys[i] != "CAN")
    {
      regionKeys.push_back(regionMapCopyKeys[i]);
    }
  }

  vector<string> subRegions;
  vector<int> maxHorses;
  for(int i = 0 ; i < regionKeys.size() ; ++i)
  {
    maxHorses.push_back(0);
    subRegions.push_back(" ");
  }


  try {
    vector<Record*>& holder = animalMapCopy[ANIMAL_X];
    findMaximums(regionKeys, subRegions ,maxHorses ,holder);
  }
  catch(string str) {
    cout<<endl<< "Error! "<< str <<endl<<endl;
    return;
  }

  formatData(regionKeys,subRegions,maxHorses);
}


void HorsesAndPoniesByRegionReport::findMaximums(vector<string> &regionKeys, vector<string> &subRegions , vector<int> &maxHorses, vector<Record*> &records) const
{
  for(int i = 0 ; i < regionKeys.size() ; ++i)
  {
    for( int j = 0 ; j < records.size() ; ++j)
    {
      if( records[j]->getYear() == YEAR_Y && records[j]->getRegion() == regionKeys[i] && records[j]->getSubRegion() != "All")
      {
        if(records[j]->getNumAnimals() > maxHorses[i])
        {
          maxHorses[i] = records[j]->getNumAnimals();
          subRegions[i] = records[j]->getSubRegion();
        }
      }
    }
  }
}


void HorsesAndPoniesByRegionReport::formatData(vector<string> &regionKeys, vector<string> &subRegions , vector<int> &maxes)
{
 for(int i = 0 ; i < regionKeys.size() ; ++i)
 {
   string dataString;
  formatString(dataString,regionKeys[i], subRegions[i],maxes[i]);
  data->add(maxes[i] , dataString);
 }
}

void HorsesAndPoniesByRegionReport::formatString(string &s, string region, string subRegion , int max) const
{
  ostringstream ss;
  ss <<setw(5) << region;
  ss <<setw(35) << subRegion;
  ss <<setw(15) << max;
  s = s + ss.str();
}

void HorsesAndPoniesByRegionReport::printReport() const
{
  string header;
  ostringstream ss;
  ss <<setw(55) << "SUB-REGION WITH MOST HORSES/PONIES BY REGION IN 2016"<<endl;
  ss<<setw(55) << "----------------------------------------------------"<<endl;
  header += ss.str();

  cout<<endl<<endl<< header<<endl;
  cout<<(*data);

  ofstream reportFile;
  reportFile.open(FILENAME_C);
  reportFile<<endl<<endl<< header<<endl;
  reportFile <<(*data);
  reportFile.close();
}

void HorsesAndPoniesByRegionReport::cleanup()
{
  data->cleanup();
}
