#include "ReportGenerator.h"

vector<Record*> ReportGenerator::data;
Map<int> ReportGenerator::yearMap;
Map<string> ReportGenerator::regionMap;
Map<string> ReportGenerator::animalMap;

ReportGenerator::ReportGenerator(){}
ReportGenerator::~ReportGenerator(){}
void ReportGenerator::cleanUp()
{
  for(int i = 0 ; i < data.size() ; ++i)
  {
    delete data[i];
  }
  data.clear();
}

void ReportGenerator::loadRecords()
{
  string year, region, subRegion, animalType, numFarms, numAnimals;
  ifstream infile( FILE_IN , ios::in);
  if(!infile)
  {
    cout << "ERROR(101): could not open file" << endl;
    exit(1);
  }
  while( infile >> year >> region >> subRegion >> animalType >> numFarms >> numAnimals)
  {
    Record* rec = new Record(formatToInt(year),region,subRegion,animalType,formatToInt(numFarms),formatToInt(numAnimals));
    data.push_back(rec);
  }
  populateMaps();
}

int ReportGenerator::formatToInt(string s) 
{
  stringstream str(s);
  int x = 0;
  str >> x;
  return x;
}

void ReportGenerator::populateMaps()
{
  for(int i = 0 ; i < data.size(); ++i)
  {
    yearMap.add(data.at(i)->getYear() , data.at(i));
    regionMap.add(data.at(i)->getRegion() , data.at(i));
    animalMap.add(data.at(i)->getAnimalType() , data.at(i));
  }
}
