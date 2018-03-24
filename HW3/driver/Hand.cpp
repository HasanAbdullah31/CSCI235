/* Hasan Abdullah: Hand.cpp - the implementation file for class Hand */

#include <iostream>
#include "Card.h"
#include "Hand.h"
using namespace std;

Hand::Hand(const int n, Card* source) {
  size=0;
  for (int i=0; i<n; i++) {
    array[i]=source[i];
    array[i].PrintCard();
    cout<<endl;
    size++;
  }
  cout<<"Exiting Hand() constructor..."<<endl;
}

Card* Hand::GetArray() { return array; }

void Hand::PrintHand() {
  cout<<"In PrintHand()..."<<endl;
  cout<<"size="<<size<<endl;
  for (int i=0; i<size; i++) {
    this->GetArray()[i].PrintCard();
    cout<<endl;
  }
}
