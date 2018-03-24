/* Hasan Abdullah: CardError.h - header file for base class CardError */

#ifndef CARD_ERROR
#define CARD_ERROR

#include "Card.h"
#include "Hand.h"

class CardError {
public:
  //inline functions:
  CardError() {};
  virtual void Handler(Card &card){}; //implemented in <Symbol,Suit>Fail classes
  virtual void Handler(Hand &hand){}; //implemented in InHand class
};

#endif /* CARD_ERROR */
