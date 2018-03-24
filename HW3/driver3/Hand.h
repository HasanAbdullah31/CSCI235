/* Hasan Abdullah: Hand.h - the header file for class Hand, using Array1 object
   that will be a 5 element array of Card */

#ifndef HAND_H
#define HAND_H

#include "Array1.h"
#include "Card.h"

class Hand {
protected:
 int SIZE;
 Array1<Card> array;
public:
 Hand();
 Hand(Array1<Card> source);
 Card Get(int i);
 int Min(int start);
 void Swap(int index1, int index2);
 void Arrange();
 void Print();
};

#endif /* HAND_H */
