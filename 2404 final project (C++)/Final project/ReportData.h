#ifndef REPORTDATA_H
#define REPORTDATA_H

using namespace std;
#include <vector>
#include "CompareBehaviour.h"

/*
Class:    ReportData
  Purpose: a templated collection class, meant to hold the results for one report, organized as an ordered collection
          of keys and formatted strings that each represent one row in the report. It is ordered according to the CompareBehaviour pointer thats passed in.

  Member function: void addadd(T k, string row)
     Purpose:- creates a new ReportRow object with the key and string, then uses the key with the CompareBehaviour pointers compare() function to insert
                the new ReportRow object into the vector, in the right order.
      in:-  k, the key we want to add
      in:- row , the row we want to add

  Member function: void cleanup()
     Purpose:-  calls the vecotr clear() method
*/

/*
Class:    ReportRow
  Purpose: a nested templated entity class, meant to represent one row of the Reportdata object, with a key and a string.

*/

template <class T>
class ReportData
{
template <class A>
  friend ostream& operator<<(ostream&, ReportData<A>&);
  public:
    ReportData(CompareBehaviour<T>* = NULL);
    void add(T, string);
    void cleanup();

  private:

    template <class V>
    class ReportRow
    {
      public:
        ReportRow(V k, string row)
        {
          key =  k;
          data = row;
        }
      V key;
      string data;
    };

    vector<ReportRow<T>> arrRows;
    CompareBehaviour<T>* behaviour;
};

#endif

/*---------------functions-------------*/

template <class T>
ReportData<T>::ReportData(CompareBehaviour<T>* b)
{
  behaviour = b;
}

template <class T>
void ReportData<T>::add(T k, string row)
{
  ReportRow<T> temp(k ,row);
typename vector<ReportRow<T>>::iterator iter;
 for(iter = arrRows.begin() ; iter != arrRows.end() ; ++iter)
    if(behaviour->compare(k , (*iter).key))
    {
      arrRows.insert(iter,1, temp);
      return;
    }
    arrRows.insert(iter,1,temp);
    return;
}

template <class T>
void ReportData<T>::cleanup()
{
  arrRows.clear();
}

template <class T>
ostream& operator<<(ostream& output, ReportData<T>& rData)
{
  for(int i = 0 ; i < rData.arrRows.size() ; ++i)
  {
    output<<rData.arrRows[i].data<<endl;

  }
  return output;
}
