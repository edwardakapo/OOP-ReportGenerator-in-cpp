#ifndef HPRG_H
#define HPRG_H
#define YEAR_Y 2016
#define ANIMAL_X "Horses-Ponies"
#define FILENAME_C "Report3.txt"
using namespace std;
#include <iostream>
#include <iomanip>
#include "ReportGenerator.h"

/*
Class:    HorsesAndPoniesByRegionReport
  Purpose:  a derived ReportGenerator control class, that collects data from the maps, does some calculations to create data,
            then adds the data to the ReportData collection pointer.

  Member function:  void findMaximums(vector<string> &regionKeys, vector<string> &subRegions , vector<int> &maxHorses, vector<Record*> &records);
     Purpose:-  takes a vector of region keys and a vector of record pointers, loops through both, filters for subregion in each region, that has the most HorsesAndPonies,
     then adds the subregion and max number of horses , to the subregion and maxhorses veectors respectively.
     in:  regionKeys; a reference of a vector of region Keys
     inout:  subRegions; a reference of a vector of subRegions with the max number of horses, corresponding with maxHorses
     inout:  maxHorses; a reference of a vector of the maximum number of horses for each region
     in:  records; a reference of a vector of record pointers

  Member function: void formatData(vector<string> &regionKeys, vector<string> &subRegions , vector<int> &maxes)
     Purpose:-  takes a vector of regionKeys , subregions and max Number of horses for each subregion, then formats a string and adds it to the ReportData pointer.
     in:  regionKeys; a reference of a vector of region Keys
     in:  subRegions; a reference of a vector of subRegions with the max number of horses, corresponding with maxHorses
     in:  maxes; a reference of a vector of the maximum number of horses for each region

  Member function:  void formatString(string &s, string region, string subRegion , int max)
     Purpose:-  takes parameters and uses the stringstream class to format a string passed in and out by reference.
      inout: s; data string to be formatted usinf sstream and returned by reference
      in: region; the region
      in: subRegion; the subRegion
      in: max; the max number oh horses for the subRegion

  Member function:  void compute();
     Purpose:- gets references to static data,create vectors to hold calculated results ,then calls multiple helper functions to do computations, filtering and storing.

  Member function:  void printReport();
      Purpose:- prints the data to screen and sends it to a file;
*/

class HorsesAndPoniesByRegionReport : public ReportGenerator
{
  public:
    HorsesAndPoniesByRegionReport(CompareBehaviour<int>*); //do we pass it in or create it here
    virtual ~HorsesAndPoniesByRegionReport();
    virtual void compute();
    virtual void printReport() const;
    virtual void cleanup();


  private:
    void findMaximums(vector<string> &, vector<string> & , vector<int> &, vector<Record*> &)const;
    void formatData(vector<string> &, vector<string> & , vector<int> &);
    void formatString(string &, string, string, int) const;
    ReportData<int>* data;


};

#endif
