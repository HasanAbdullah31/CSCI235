/* Hasan Abdullah: driver.cpp - declare and initialize an Array1 object of Card
objects, then sort using different Arrange() methods from two derived Hands */

#include <iostream>
#include "Array1.h"
#include "Card.h"
#include "Hand.h"
#include "PokerHand.h"
#include "CanastaHand.h"
using namespace std;

int main(int argc, char **argv) {
  Card card0=Card("2", "clubs");
  Card card1=Card("A", "hearts");
  Card card2=Card("J", "hearts");
  Card card3=Card("9", "diamonds");
  Card card4=Card("2", "spades");
  Card a[5]={card0, card1, card2, card3, card4};
  Array1<Card> myArray=Array1<Card>(a);
  Hand myHand=Hand(myArray);
  PokerHand myPoker=PokerHand(myHand);
  CanastaHand myCanasta=CanastaHand(myHand);
  cout<<"Print myPoker as is:"<<endl;
  myPoker.Print();
  cout<<"Print myPoker sorted (ascending order):"<<endl;
  myPoker.Arrange();
  myPoker.Print();
  cout<<endl;
  cout<<"Print myCanasta as is:"<<endl;
  myCanasta.Print();
  cout<<"Print myCanasta sorted (ascending order):"<<endl;
  myCanasta.Arrange();
  myCanasta.Print();
  return 0;
}
