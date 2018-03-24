/* Hasan Abdullah: SuitFail.h - derived class of CardError that checks for
   a valid suit of Card */

#ifndef SUIT_FAIL
#define SUIT_FAIL

#include "CardError.h"
#include "Card.h"

class SuitFail : public CardError {
public:
 SuitFail();
 void Handler(Card &card); //implement virtual function from CardError class
};

#endif /* SUIT_FAIL */
