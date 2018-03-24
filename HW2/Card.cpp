/* Hasan Abdullah: Card.cpp - implement class Card member functions and two
   non-member functions SymbolValue and SuitValue */

#include <iostream>
#include <string>
#include <cstdlib> //for atoi (C-string to int) and c_str() (string to C-string)
#include "Card.h"
using namespace std;

Card::Card() {}

Card::Card(string inputSymbol, string inputSuit) {
  symbol=inputSymbol;
  suit=inputSuit;
}

string Card::GetSymbol() { return symbol; }

string Card::GetSuit() { return suit; }

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
