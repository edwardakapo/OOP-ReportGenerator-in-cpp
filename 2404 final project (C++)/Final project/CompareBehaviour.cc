#include <iostream>
using namespace std;
#include <string>
#include <sstream>
#include "CompareBehaviour.h"


CompareBehaviour::CompareBehaviour(){}

CompareBehaviour::~CompareBehaviour(){}


// -----------------------------AscBehaviour-----------------------------------

AscBehaviour::AscBehaviour(){}

template <class T>
bool AscBehaviour::compare(T one,T two){ return one < two ;}


// -----------------------------DescBehaviour-----------------------------------

DescBehaviour::DescBehaviour(){}

template <class T>
bool DescBehaviour::compare(T one,T two){ return one > two ;}
