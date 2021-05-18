#ifndef COMPAREBEHAVIOUR_H
#define COMPAREBEHAVIOUR_H
using namespace std;

/*
Class:    CompareBehaviour
  Purpose:  abstract Templated Comparison behaviour base class, which has its virtual bool compare(T,T) method to order report data.
*/

/*
Class:    AscBehaviour
  Purpose:  derived Comparison behaviour class, which has its virtual bool compare(T,T) method to order report data in ascending order.

  Member function:  virtual bool compare(T,T)
     Purpose:-  returns true if T one is less than T two.

*/

/*
Class:    DescBehaviour
  Purpose:  derived Comparison behaviour class, which has its virtual bool compare(T,T) method to order report data in ascending order.

  Member function:  virtual bool compare(T,T)
     Purpose:-  returns true if T one is greater than T two.
*/


template <class T>
class CompareBehaviour
{
  public:
    CompareBehaviour();
    virtual ~CompareBehaviour(){};
    virtual bool compare(T,T) const = 0;
};

template <class V>
class AscBehaviour : public CompareBehaviour<V>
{
  public:
    AscBehaviour();
    virtual ~AscBehaviour(){};
    virtual bool compare(V,V) const;
};

template <class C>
class DescBehaviour : public CompareBehaviour<C>
{
public:
  DescBehaviour();
  virtual ~DescBehaviour(){};
  virtual bool compare(C,C) const;
};
#endif

// -----------------------------CompareBehaviour-functions-------------------------------

template <class T>
CompareBehaviour<T>::CompareBehaviour(){}

// -----------------------------AscBehaviour-functions----------------------------------
template <class V>
AscBehaviour<V>::AscBehaviour(){}

template <class V>
bool AscBehaviour<V>::compare(V one,V two) const{ return one < two ;}

// -----------------------------DescBehaviour-functions----------------------------------
template <class C>
DescBehaviour<C>::DescBehaviour(){}

template <class C>
bool DescBehaviour<C>::compare(C one,C two) const{ return one > two ;}
