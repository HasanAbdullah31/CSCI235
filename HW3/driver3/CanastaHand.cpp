/* Hasan Abdullah: CanastaHand.cpp - implementation of CanastaHand class */

#include "Array1.h"
#include "Card.h"   //has int SymbolValue(string symbol);
#include "Hand.h"
#include "CanastaHand.h"

CanastaHand::CanastaHand(Hand source) : Hand(source) {
  hand=source;
  int symb[SIZE];   //will hold symbol values of the Cards
  for (int i=0; i<SIZE; i++)
    symb[i]=SymbolValue( array.Get(i).GetSymbol() ); //array protected in Hand
  symbols=Array1<int>(symb);
}

void CanastaHand::Arrange() {
  //we want to sort the Hand hand corresponding to the Array1<int> ints
  int index;
  for (int j=0; j<SIZE; j++) {
    index=symbols.Min(j);
    symbols.Swap(j, index);
    hand.Swap(j, index);
  }
}

void CanastaHand::Print() {
  hand.Print();
}
