#ifndef MAP_H
#define MAP_H
using namespace std;
#include <vector>
#include "Record.h"


/*
Class:    Map
  Purpose:  a templated collection class, that is used to model a parallel array of keys and values, where the keys array at [i] corresponds with the values array at [i].

  Member function:  void add(T k, Record* rec)
     Purpose:-  takes in a key and a Record*, then inserts the values into the corresponding collection for the key, if the keys isn't in the vector of keys, then inserts them into the collection of keys and values.
     in:- k, the key we want to add
     in:- rec , the record pointer we want to add

  Member function:  int getSize()
     Purpose:-  returns the size of the keys vector.

  Member function:  vector<T>& getKeys()
     Purpose:- returns a reference to the keys vector.

  Member function:  vector<Record*>& operator[](T K);
     Purpose:- provides an implementation for the [] operator by taking in a key as parameter, then returns a reference to the element of the values
            collection corresponding to that key.
     in:- k, the key, whose corresponding value we want.
*/

template <class T >
class Map
{
  public:
    Map();
    void add(T, Record*);
    int getSize() const;
    vector<T>& getKeys();
    vector<Record*>& operator[](T) ;
  private:
    vector<T> keys;
    vector<vector<Record*>> values;
};
#endif

/*---------------functions-------------*/
template <class T>
Map<T>::Map(){}


template <class T>
int Map<T>::getSize() const
 {
   return keys.size();
  }

template <class T>
vector<T>& Map<T>::getKeys() { return keys;}

template <class T>
void Map<T>::add(T k, Record* rec)
{
  for(int i = 0 ; i < keys.size() ; ++i)
  {
    if(k == keys.at(i))
    {
      values.at(i).push_back(rec);
      return;
    }
  }
    keys.push_back(k);
    vector<Record*> v;
    v.push_back(rec);
    values.push_back(v);
}

template <class T>
vector<Record*>& Map<T>::operator[](T k)
{
  for( int i = 0 ; i < keys.size() ; ++i)
  {
    if(k == keys.at(i))
    {
      return values.at(i);
    }
  }
  throw((string) "ERROR(100) : Given Key not Found");
}
