/* Hasan Abdullah: CanastaHand.h - CanastaHand class derived from Hand class */

#ifndef CANASTAHAND_H
#define CANASTAHAND_H

#include "Array1.h"
#include "Hand.h"

class CanastaHand : public Hand {
private:
 Hand hand;
 Array1<int> symbols;   //for converted values, to apply Sort() for Arrange()
public:
 CanastaHand(Hand source);
 void Arrange();
 void Print();
};

#endif /* CANASTAHAND_H */
