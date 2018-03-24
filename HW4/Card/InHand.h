/* Hasan Abdullah: InHand.h - derived class of CardError that checks if a
   Card is already in Hand */

#ifndef IN_HAND
#define IN_HAND

#include "CardError.h"
#include "Hand.h"

class InHand : public CardError {
public:
 InHand();
 void Handler(Hand &hand); //implement virtual function from CardError class
};

#endif /* IN_HAND */
