#ifndef RBG_H
#define RBG_H
#define YEAR_X 2016
#define FILENAME_A "Report1.txt"
#include <iostream>
#include <iomanip>
using namespace std;
#include "ReportGenerator.h"

/*
Class:    RegionalBreakdownReport
  Purpose:  a derived ReportGenerator control class, that collects data from the maps, does some calculations to create data,
            then adds the data to the ReportData collection pointer.

  Member function:  void fillTotals(vector<string> &animalKeys, vector<vector<float>> &arr , vector<Record*> &records);
     Purpose:-  takes vector parameters, creates a temp array filters thorugh the records vector and fills temp with the total numbers of farms for each animal type in the animal vector.
     in:  animalKeys;  a reference of a vector of animal Keys
     inout: arr ; a reference of a vector of vectors with the total number of each animal type, for every region, each vector element corresponding with animals vector
     in:  records; a reference of a vector of records.

  Member function: void formatData(string region, vector<float> &row,  int total , vector<float> &totalByAnimal);
     Purpose:-  takes a parameters then loops through every element in row, calculates the percentages, formats a string with the required information and adds it to the ReportData pointer.
     in: region; the region.
     in: row; a reference of a vector that contained total number of every animal type for the specified region.
     in: total; a total number of animals of every type in every region
     in: totalByAnimal; a vector of total number of animal by type, summed in every region.

  Member function:  void getTotals(int &total, vector<float> &totalbyAnimals, vector<vector<float>> &arr);
     Purpose:-  takes arr and sums for each animal type across all vactors, puts each sum in a vector of sums, totalbyAnimals, then sums all the elements of totalsByAnimal to get total.
      inout: total; total number of animalsfarms.
      inout: totalbyAnimals; a vector of total number of aniamlsfarms by animal type
      in: arr ; a vector of vectors that holds stats about number of animal farms, formatted to corresponds with a vector of aniaml keys.


  Member function:  void formatString(string &s, float x);
     Purpose:-  takes parameters and uses the stringstream class to format a string passed in and out by reference.
      inout: s; data string to be formatted usinf sstream and returned by reference
      in:  x; the percentage to be added

  Member function:  float  sumRow(vector<float> &row);
      Purpose:-  takes a vector and sums all its elements
        in: row; the vector to be summed.
        out: the sum of the elements in the vector.

  Member function:  void compute();
     Purpose:- gets references to static data,create vectors to hold calculated results ,then calls multiple helper functions to do computations, filtering and storing.

  Member function:  void printReport();
      Purpose:- prints the data to screen and sends it to a file;
*/
class RegionalBreakdownReport : public ReportGenerator
{
  public:
    RegionalBreakdownReport(CompareBehaviour<float>*);
    virtual ~RegionalBreakdownReport();
    virtual void compute();
    virtual void printReport() const;
    virtual void cleanup();
  private:
    void formatData(string, vector<float>& , int , vector<float>& );
    void fillTotals(vector<string>&,vector<vector<float>>&,vector<Record*>&) const;
    void getTotals(int&,vector<float>&,vector<vector<float>>&) const;
    void formatString(string&, float) const;
    float  sumRow(vector<float>&) const;
    ReportData<float>* data;

};

#endif
