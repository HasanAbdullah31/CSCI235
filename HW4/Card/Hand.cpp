/* Hasan Abdullah: Hand.cpp - the implementation file for class Hand */

#include <iostream>
#include <string>
#include <cstdlib>   //for rand() in Replace() function
#include "InHand.h"   //exception handler
#include "Card.h"
#include "Hand.h"
using namespace std;

Hand::Hand() { size=5; }

Hand::Hand(const int n, Card* source) {
  size=0;
  for (int i=0; i<n; i++) {
    array[i]=source[i];
    size++;
  }
  //now check for duplicates
  for (int j=0; j<size; j++) {
    for (int k=0; k<size; k++) {
      if (k!=j)   //don't compare array[j] with itself b/c == obviously
	if (!(array[j]>array[k]) && !(array[j]<array[k])) //i.e. they are ==
	  throw InHand();
    }
  }
}

Card* Hand::GetArray() { return array; }

int Hand::Size() { return size; }

void Hand::Replace(int numCards) {
  if (numCards>size)
    cout<<"Can't replace "<<numCards<<" cards in a "<<size<<" card hand!"<<endl;
  else if (numCards==0)
    cout<<"No cards to be replaced."<<endl;
  else {
    unsigned int r, x;
    string symbol, suit;
    Card randomCard;
    for (int i=0; i<numCards; i++) {
      r=rand(); x=r;
      r=r%13+2; //+2 to go from 0-12 (inclusive) range to 2-14 (inclusive) range
      x=x%4;   //x has range of 0-3 (inclusive)
      //first, make a random symbol:
      if      (r==11) symbol="A";
      else if (r==12) symbol="J";
      else if (r==13) symbol="Q";
      else if (r==14) symbol="K";
      else   //r b/w 2-10 (rest of card symbols)
	symbol=to_string(r); //convert r to a string (of the number)
      //next, make a random suit:
      if      (x==0) suit="clubs";
      else if (x==1) suit="diamonds";
      else if (x==2) suit="spades";
      else   //x==3
	suit="hearts";
      //combine the random symbol and random suit to make a randomCard
      randomCard=Card(symbol,suit);
      //check to see if randomCard==hand[i] (card to be replaced)
      if (!(randomCard>array[i]) && !(randomCard<array[i]))   //i.e. they are ==
	i--;   //reset loop to try a new randomCard for this hand[i]
      else {   //randomCard!=hand[i]
	bool exists=false;
	for (int j=0; j<size; j++) {
	  if (!(randomCard>array[j]) && !(randomCard<array[j])) { //check for ==
	    exists=true;
	    i--;
	    break;
	  }
	}
	if (!exists)
          array[i]=randomCard;
      }
    }   //outer for loop (with i as iterator)
  }   //outer else (if numCards b/w 1 and size [inclusive])
}

void Hand::PrintHand() {
  cout<<"In PrintHand()..."<<endl;
  cout<<"size="<<size<<endl;
  for (int i=0; i<size; i++) {
    this->GetArray()[i].PrintCard();
    cout<<endl;
  }
}
