/* Hasan Abdullah: PokerHand.h - PokerHand class derived from Hand class */

#ifndef POKERHAND_H
#define POKERHAND_H

#include "Hand.h"

class PokerHand : public Hand {
private:
 Hand hand;
public:
 PokerHand(Hand source);
 void Arrange();
 void Print();
};

#endif /* POKERHAND_H */
