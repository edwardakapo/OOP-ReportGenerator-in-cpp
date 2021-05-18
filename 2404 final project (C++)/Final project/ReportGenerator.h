#ifndef REPORTGENERATOR_H
#define REPORTGENERATOR_H

#define FILE_IN "farms.dat"

using namespace std;
#include <fstream>
#include <iostream>
#include <sstream>
#include "ReportData.h"
#include "Record.h"
#include "Map.h"

/*
Class:    ReportGenerator
  Purpose:  abstract report generation base class, reads in data from a file specified above,
   populates the data members with information  and provides virtual function for the derived classed.

  Member function:  void loadRecords()
     Purpose:-  reads from file specified above, for every line creates a record object and puts it into the data vector. Then populates the maps

  Member function:  void cleanUp()
     Purpose:-  loops through vector and deletes all record pointers.

  Member function:  int formatToInt(string s)
     Purpose:- takes a string and changes it into an integer
     in:- s; string to be changed into an int

  Member function:  void populateMaps()
     Purpose:- loops through vector and calls the map add() function to add all the record pointers and some specified key to the maps.




*/

class ReportGenerator
{
  public:

    ReportGenerator();
    virtual ~ReportGenerator();
    virtual void compute() = 0;
    virtual void printReport() const = 0;
    virtual void cleanup() = 0;
    static void loadRecords();
    static void cleanUp();



  protected:

    static int formatToInt(string);
    static void populateMaps();
    static vector<Record*> data; // primary collection
    static Map<int> yearMap;
    static Map<string> regionMap;
    static Map<string> animalMap;

};

#endif
