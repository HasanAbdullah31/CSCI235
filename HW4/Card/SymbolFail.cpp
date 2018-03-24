/* Hasan Abdullah: SymbolFail.cpp - implementation of SymbolFail class */

#include <iostream>
#include "Card.h"
#include "CardError.h"
#include "SymbolFail.h"
using namespace std;

SymbolFail::SymbolFail() : CardError() {}

void SymbolFail::Handler(Card &card) { //pass-by-ref b/c Handler changes card
  cout<<"Invalid symbol! Valid symbols: 2,3,4,5,6,7,8,9,10,J,Q,K,A\n"
      <<"11,12,13,14 also valid, but will be converted to J,Q,K,A\n"
      <<"Enter a new symbol for the card:"<<endl;
  string s;
  cin>>s;
  while (SymbolValue(s)<2 || SymbolValue(s)>14 || cin.fail()) {
    cout<<"Invalid symbol! Try again:"<<endl;
    cin.clear();
    cin.ignore(999,'\n');
    cin>>s;
  }
  if      (SymbolValue(s)==11) s="J";
  else if (SymbolValue(s)==12) s="Q";
  else if (SymbolValue(s)==13) s="K";
  else if (SymbolValue(s)==14) s="A";
  card.ChangeSymbol(s);
}
