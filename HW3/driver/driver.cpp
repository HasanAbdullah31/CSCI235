/* Hasan Abdullah: driver.cpp - the main program */

#include <iostream>
#include "Card.h"
#include "Hand.h"
using namespace std;

int main(int argc, char **argv) {
  Card myCard1=Card("A", "clubs");
  Card myCard2=Card("J", "hearts");
  Card myCard3=Card("2", "spades");
  Card myCard4=Card("A", "diamonds");
  Card myCard5=Card("A", "hearts");
  const int mySize=5;
  Card myCards[mySize]={myCard1, myCard2, myCard3, myCard4, myCard5};
  Hand myHand=Hand(mySize, myCards);
  myHand.PrintHand();
  return 0;
}
