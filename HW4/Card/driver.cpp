/* Hasan Abdullah: driver.cpp - the main program */

#include <iostream>
#include <cstdlib> //for srand() used for PRNG
#include <ctime>   //for time() used for PRNG
#include "Card.h"
#include "Hand.h"
#include "CardError.h"
#include "SymbolFail.h"
#include "SuitFail.h"
#include "InHand.h"
using namespace std;

int main(int argc, char **argv) {
  const int SIZE=5;
  string symb, suit;
  SymbolFail symbf;
  SuitFail suitf;
  Card myCards[SIZE];
  for (int i=0; i<SIZE; i++) {
    cout<<"Enter symbol of Card "<<i+1<<":"<<endl;
    cin>>symb;
    try {
      myCards[i].ChangeSymbol(symb);   //change suit later
    }
    catch (CardError) {
      symbf.Handler(myCards[i]);
    }
    cout<<"Enter suit of Card "<<i+1<<":"<<endl;
    cin>>suit;
    try {
      myCards[i].ChangeSuit(suit);   //keep symbol from before, change suit
    }
    catch (CardError) {
      suitf.Handler(myCards[i]);
    }
  }
  cout<<"Your hand is:"<<endl;
  for (int j=0; j<SIZE; j++) {
    myCards[j].PrintCard();
    cout<<endl;
  }
  InHand duplicates;
  Hand myHand;
  bool error=false;
  srand(time(0)); //seed to generate multiple different random Cards if needed
  try {
    myHand=Hand(SIZE,myCards);
  }
  catch (CardError) {
    error=true;
    duplicates.Handler(myHand);   //generates 5 random Cards
  }
  if (error==true) {
    cout<<"Your new hand is:"<<endl;
    myHand.PrintHand();
  }
  return 0;
}
