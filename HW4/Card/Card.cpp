/* Hasan Abdullah: Card.cpp - the implementation file for class Card */

#include <iostream>
#include <string>
#include <cstdlib> //for atoi (C-string to int) and c_str() (string to C-string)
#include "SymbolFail.h"
#include "SuitFail.h"   //<Symbol,Suit>Fail exception handlers
#include "Card.h"
using namespace std;

Card::Card() {}

Card::Card(string inputSymbol, string inputSuit) {
  ChangeSymbol(inputSymbol);
  ChangeSuit(inputSuit);
}

string Card::GetSymbol() { return symbol; }

string Card::GetSuit() { return suit; }

void Card::ChangeSymbol(string s) {
  int val=SymbolValue(s);
  if (val>=2 && val<=14) {
    if      (val==11) symbol="J";
    else if (val==12) symbol="Q";
    else if (val==13) symbol="K";
    else if (val==14) symbol="A";
    else symbol=s;
  }
  else
    throw SymbolFail();
}

void Card::ChangeSuit(string s) {
  if (s=="clubs" || s=="diamonds" || s=="spades" || s=="hearts")
    suit=s;
  else
    throw SuitFail();
}

bool operator>(Card card1, Card card2) {
  bool greater=false;
  if ( SuitValue(card1.suit)<SuitValue(card2.suit) )
    greater=false;
  else if ( SuitValue(card1.suit)==SuitValue(card2.suit) ) {
    if ( SymbolValue(card1.symbol)>SymbolValue(card2.symbol) )
      greater=true;
    else
      greater=false;
  }
  else
    greater=true;
  return greater;
}

bool operator>=(Card card1, Card card2) {   //same code as >, with minor change
  bool greater=false;
  if ( SuitValue(card1.suit)<SuitValue(card2.suit) )
    greater=false;
  else if ( SuitValue(card1.suit)==SuitValue(card2.suit) ) {
    if ( SymbolValue(card1.symbol)>SymbolValue(card2.symbol) )
      greater=true;
    else if ( SymbolValue(card1.symbol)==SymbolValue(card2.symbol) )
      greater=true;   //this else if using == is the minor change
    else
      greater=false;
  }
  else
    greater=true;
  return greater;
}

bool operator<(Card card1, Card card2) {
  return !(card1>=card2); //this only leaves one option: card1<card2
}

bool operator<=(Card card1, Card card2) {
  return !(card1>card2); //this leaves two options: card1<card2 or card1==card2
}

void Card::PrintCard() {
  cout<<this->symbol<<" of "<<this->suit;
}

//SymbolValue() works for card symbols (returns int):
int SymbolValue(string symbol) {
  //symbol: string representing one of 2…10 or J, Q , K, A
  int n;
  if (symbol=="A")
    n=14;
  else if (symbol=="J")
    n=11;
  else if (symbol=="Q")
    n=12;
  else if (symbol=="K")
    n=13;
  else
    n=atoi(symbol.c_str());   //c_str() converts string to char*
  return n;
}

//SuitValue() works for card suits (also returns int):
int SuitValue(string suit) {
  //suit: string representing one of clubs, diamonds, spades, or hearts
  int n;
  if (suit=="clubs")
    n=0;
  else if (suit=="diamonds")
    n=1;
  else if (suit=="spades")
    n=2;
  else   //suit=="hearts"
    n=3;
  return n;
}
