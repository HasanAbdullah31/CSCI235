/* Hasan Abdullah: SymbolFail.h - derived class of CardError that checks for
   a valid symbol of Card */

#ifndef SYMBOL_FAIL
#define SYMBOL_FAIL

#include "CardError.h"
#include "Card.h"

class SymbolFail : public CardError {
public:
 SymbolFail();
 void Handler(Card &card); //implement virtual function from CardError class
};

#endif /* SYMBOL_FAIL */
