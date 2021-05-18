#ifndef PBG_H
#define PBG_H
#define YEAR_A 2011
#define YEAR_B 2016
#define FILENAME_B "Report2.txt"
using namespace std;
#include <iostream>
#include <iomanip>
#include "ReportGenerator.h"

/*
Class:    RegionalBreakdownReport
  Purpose:  a derived ReportGenerator control class, that collects data from the maps, does some calculations to create data,
            then adds the data to the ReportData collection pointer.

  Member function: void fillTotals(vector<string> &animalKeys , vector<vector<float>> &arr, vector<Record*> &records , int year)
     Purpose:- takes vector parameters, creates a temp array filters thorugh the records vector and fills temp with the total number of animals of each animal type in the records, for a specified year
     in: animalKeys; vector of animal keys, used to filter record.
     inout: arr; vector of vectors used to store, total number of animals for both years.with each element being a vector of percentages of each animal type, corresponding to animal keys, for a specified year.
     in: records; vector of record pointers, for data.
     in: year; specific year to filter for.

  Member function: void formatString(string &s, string animal ,float year1 , float year2 , float change)
     Purpose:- takes parameters and uses the stringstream class to format a string passed in and out by reference.
     inout: s; data string to be formatted usinf sstream and returned by reference
     in: animal; animal key
     in: year1; percentage of specified animal in year1
     in: year2; percentage of specified animal in year1
     in: change; percentage change between the two years

  Member function: void calcuatePercentages(vector<vector<float>> &arr)
     Purpose:-  takes param arr, accesses its two vectors, then computes the percentages of all elemnts of each respective vector.
     inout: arr; vector of vectors that stores the percentages of each animal type by year, respective to all animals in that year.

  Member function: void formatData(vector<string> &animalKeys, vector<float> &year1 , vector<float> &year2)
     Purpose:-
     in: animalKeys; vector of animal keys
     in: year1; vector of percentages of each animal type, corresponding to animal keys, for a specified year.
     in: year2; vector of percentages of each animal type, corresponding to animal keys, for a specified year.

  Member function:  float  sumRow(vector<float> &row);
     Purpose:-  takes a vector and sums all its elements
      in: row; the vector to be summed.
      out: the sum of the elements in the vector.

  Member function:  void compute();
      Purpose:- gets references to static data,create vectors to hold calculated results ,then calls multiple helper functions to do computations, filtering and storing.

  Member function:  void printReport();
      Purpose:- prints the data to screen and sends it to a file;

*/
class PercentageBreakDownReport : public ReportGenerator
{
  public:
    PercentageBreakDownReport(CompareBehaviour<float>*); //do we pass it in or create it here
    virtual ~PercentageBreakDownReport();
    virtual void compute();
    virtual void printReport()const;
    virtual void cleanup();

  private:
    void formatData(vector<string>&, vector<float>&, vector<float>& );
    void fillTotals(vector<string>& , vector<vector<float>>&, vector<Record*>& , int)const;
    void calcuatePercentages(vector<vector<float>>&)const;
    void formatString(string&, string,float, float, float)const;
    float sumRow(vector<float>&) const;
    ReportData<float>* data;


};

#endif
