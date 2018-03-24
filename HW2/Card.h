/* Hasan Abdullah: Card.h - class Card header file, contains class definition */

#ifndef CARD_H
#define CARD_H

#include <string>
using namespace std;

class Card {
private:
 string symbol;   //not char because 10 (a card symbol) has two digits
 string suit;
 friend bool operator>(Card card1, Card card2);
public:
 Card();
 Card(string inputSymbol, string inputSuit);
 string GetSymbol();
 string GetSuit();
 void PrintCard();
};

int SymbolValue(string symbol);
int SuitValue(string suit);

#endif /* CARD_H */
