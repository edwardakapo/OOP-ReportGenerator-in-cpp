#ifndef RECORD_H
#define RECORD_H
using namespace std;
#include <string>


/*
Class:    Record
  Purpose:  an entity object used for storing the information from one line of a file.
*/


class Record
{
  public:
    Record(int = 0 , string = "xxxx", string = "xxxxx", string = "xxxxxx", int = 0, int = 0);
    ~Record();
    int getYear();
    string getRegion();
    string getSubRegion();
    string getAnimalType();
    int getNumFarms();
    int getNumAnimals();
  private:
    int year;
    string region;
    string subRegion;
    string animalType;
    int numFarms;
    int numAnimals;
};
#endif
