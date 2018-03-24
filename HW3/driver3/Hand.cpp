/* Hasan Abdullah: Hand.cpp - the implementation file for class Hand */

#include <iostream>
#include "Array1.h"
#include "Card.h"
#include "Hand.h"
using namespace std;

Hand::Hand() { SIZE=array.Size(); }

Hand::Hand(Array1<Card> source) {
  array=source;
  SIZE=array.Size();
}

Card Hand::Get(int i) { return array.Get(i); }

int Hand::Min(int start) { return array.Min(start); }

void Hand::Swap(int index1, int index2) { array.Swap(index1,index2); }

void Hand::Arrange() { array.Sort(); }

void Hand::Print() { array.Print(); }
