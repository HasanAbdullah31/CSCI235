/* Hasan Abdullah: InHand.cpp - implementation of InHand derived class */

#include <iostream>
#include "Hand.h"
#include "CardError.h"
#include "InHand.h"
using namespace std;

InHand::InHand() : CardError() {}

void InHand::Handler(Hand &hand) { //pass-by-ref b/c Handler changes hand
  cout<<"Duplicate cards in hand!"<<endl;
  cout<<"The program will now generate "<<hand.Size()<<" random cards."<<endl;
  hand.Replace(hand.Size());
}
