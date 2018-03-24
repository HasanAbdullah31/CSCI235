/* Hasan Abdullah: PokerHand.cpp - implementation of PokerHand class */

#include "Hand.h"
#include "PokerHand.h"

PokerHand::PokerHand(Hand source) : Hand(source) {
  hand=source;
}

void PokerHand::Arrange() {
  hand.Arrange();
}

void PokerHand::Print() {
  hand.Print();
}
