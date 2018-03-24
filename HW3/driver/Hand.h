/* Hasan Abdullah: Hand.h - the header file for class Hand, using Card objects
   to form arrays of cards */

#ifndef HAND_H
#define HAND_H
#include "Card.h"

class Hand {
private:
 static const int SIZE=13;
 Card array[SIZE];
 int size;
public:
 Hand(const int n, Card* source);
 Card* GetArray();
 void PrintHand();
};

#endif /* HAND_H */
