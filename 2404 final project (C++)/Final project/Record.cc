#include "Record.h"

Record::Record(int yr  , string rg , string srg, string at, int nf, int na)
{
  year = yr;
  region = rg;
  subRegion = srg;
  animalType = at;
  numFarms = nf;
  numAnimals = na;
}
Record::~Record(){}
int Record::getYear(){ return year; }
string Record::getRegion(){ return region; }
string Record::getSubRegion(){ return subRegion; }
string Record::getAnimalType(){ return animalType; }
int Record::getNumFarms(){ return numFarms; }
int Record::getNumAnimals(){ return numAnimals; }
