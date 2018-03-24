/* Hasan Abdullah: SuitFail.cpp - implementation of SuitFail class */

#include <iostream>
#include "Card.h"
#include "CardError.h"
#include "SuitFail.h"
using namespace std;

SuitFail::SuitFail() : CardError() {}

void SuitFail::Handler(Card &card) { //pass-by-ref b/c Handler changes card
  cout<<"Invalid suit! Valid suits: clubs, diamonds, spades, hearts\n"
      <<"Enter a new suit for the card:"<<endl;
  string s;
  cin>>s;
  while ((s!="clubs"&&s!="diamonds"&&s!="spades"&&s!="hearts") || cin.fail()) {
    cout<<"Invalid suit! Try again:"<<endl;
    cin.clear();
    cin.ignore(999,'\n');
    cin>>s;
  }
  card.ChangeSuit(s);
}
