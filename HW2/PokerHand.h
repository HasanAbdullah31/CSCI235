/* Hasan Abdullah: PokerHand.h - PokerHand class based on Card class */

#ifndef POKERHAND_H
#define POKERHAND_H

#include <string>
#include "Card.h"
using namespace std;

class PokerHand {
private:
 Card hand[5];
 string worth;
public:
 //constructor assumes source is an array of 5 Card elements
 PokerHand(Card* source);
 string GetWorth();
 void Arrange();
 void Replace(int numCards);
 void Evaluate();
 void PrintHand();
 friend bool operator>(PokerHand h1, PokerHand h2);
};

#endif /* POKERHAND_H */
