/* Hasan Abdullah: PokerHand.cpp - implementation of PokerHand class */

#include <iostream>
#include <string>
#include <cstdlib>   //for rand() in Replace() function
#include "Card.h"
#include "PokerHand.h"
using namespace std;

PokerHand::PokerHand(Card* source) {
  for (int i=0; i<5; i++)
    hand[i]=source[i];
}

string PokerHand::GetWorth() { return worth; }

bool operator>(PokerHand h1, PokerHand h2) {
  h1.Evaluate(); h2.Evaluate();   //side effect: private member worth filled in
  int worth1, worth2;
  if      (h1.worth=="straight flush")  worth1=9;
  else if (h1.worth=="four of a kind")  worth1=8;
  else if (h1.worth=="full house")      worth1=7;
  else if (h1.worth=="flush")           worth1=6;
  else if (h1.worth=="straight")        worth1=5;
  else if (h1.worth=="three of a kind") worth1=4;
  else if (h1.worth=="two pairs")       worth1=3;
  else if (h1.worth=="one pair")        worth1=2;
  else if (h1.worth=="no pair")         worth1=1;
  
  if      (h2.worth=="straight flush")  worth2=9;
  else if (h2.worth=="four of a kind")  worth2=8;
  else if (h2.worth=="full house")      worth2=7;
  else if (h2.worth=="flush")           worth2=6;
  else if (h2.worth=="straight")        worth2=5;
  else if (h2.worth=="three of a kind") worth2=4;
  else if (h2.worth=="two pairs")       worth2=3;
  else if (h2.worth=="one pair")        worth2=2;
  else if (h2.worth=="no pair")         worth2=1;
  bool greater=false;
  if (worth1>worth2)
    greater=true;
  else if (worth1<worth2)
    greater=false;
  return greater;
}

void PokerHand::Arrange() {
  Card temp;
  for (int i=0; i<4; i++) {
    for (int j=i+1; j<5; j++) {
      if (hand[i]>hand[j]) {   //> is a friend operator from Card
        temp=hand[i];
	hand[i]=hand[j];
	hand[j]=temp;
      }
    }
  }
}

void PokerHand::Replace(int numCards) {
  if (numCards>5 || numCards<0)
    cout<<"Cannot replace "<<numCards<<" cards in a hand of 5 cards!"<<endl;
  else if (numCards==0)
    cout<<"No cards to be replaced."<<endl;
  else {
    unsigned int r, x;
    string symbol, suit;
    Card randomCard;
    for (int i=0; i<numCards; i++) {
      r=rand(); x=r;
      r=r%13+2; //+2 to go from 0-12 (inclusive) range to 2-14 (inclusive) range
      x=x%4;   //x has range of 0-3 (inclusive)
      //first, make a random symbol:
      if      (r==11) symbol="A";
      else if (r==12) symbol="J";
      else if (r==13) symbol="Q";
      else if (r==14) symbol="K";
      else   //r b/w 2-10 (rest of card symbols)
	symbol=to_string(r); //convert r to a string (of the number)
      //next, make a random suit:
      if      (x==0) suit="clubs";
      else if (x==1) suit="diamonds";
      else if (x==2) suit="spades";
      else   //x==3
	suit="hearts";
      //combine the random symbol and random suit to make a randomCard
      randomCard=Card(symbol,suit);
      //check to see if randomCard==hand[i] (card to be replaced)
      if (!(randomCard>hand[i]) && !(hand[i]>randomCard))   //i.e. they are ==
	i--;   //reset loop to try a new randomCard for this hand[i]
      else {   //randomCard!=hand[i]
	bool exists=false;
	for (int j=0; j<5; j++) {
	  if (!(randomCard>hand[j]) && !(hand[j]>randomCard)) { //check for ==
	    exists=true;
	    i--;
	  }
	}
	if (!exists)
          hand[i]=randomCard;
      }
    }   //outer for loop (with i as iterator)
  }   //outer else (if numCards b/w 1 and 5)
}

void PokerHand::Evaluate() {
  //int SymbolValue(string) and int SuitValue(string) will be useful here
  this->Arrange();   //order Cards in hand to evaluate easily
  int symb[5];
  for (int i=0; i<5; i++)
    symb[i]=SymbolValue(hand[i].GetSymbol());
  for (int j=0; j<4; j++) {
    int temp;
    for (int k=j+1; k<5; k++) {
      if (symb[j]>symb[k]) {
	temp=symb[j];
	symb[j]=symb[k];
	symb[k]=temp;
      }
    }
  }   //assert: symb[5] holds values of symbols in order (least->greatest)
  int suit[5];
  for (int x=0; x<5; x++)
    suit[x]=SuitValue(hand[x].GetSuit());
  //assert: suit[5] holds values of suits in order (least->greatest) because
  //this->Arrange() at very beginning of this function ordered suits already

  //Straight Flush: 5 cards of the same suit, in sequence
  bool straightFlush=false;
  for (int a=0; a<4; a++) {   //hand[<0-3]>, compared with hand[<1-4>]
    if (suit[a]==suit[a+1]) {
      if (symb[a]==symb[a+1]-1) {
	straightFlush=true;
      }
      else {   //all cards not in sequence
	straightFlush=false;
	break;
      }
    }
    else {   //all cards not of same suit
      straightFlush=false;
      break;
    }
  }
  if (straightFlush==true) {
    worth="straight flush";
    return;
  }
  
  //Four of a kind: 4 cards of the same symbol
  //if there are 4 same symbols, they are first 4 or last 4 in symb[]
  if ((symb[0]==symb[1]&&symb[1]==symb[2]&&symb[2]==symb[3]) ||
      (symb[1]==symb[2]&&symb[2]==symb[3]&&symb[3]==symb[4])) {
    worth="four of a kind";
    return;
  }
  
  //Full House: 3 cards of one symbol, and 2 of another
  //3 same symbols would be first, middle, or last 3 in symb[]
  if ((symb[0]==symb[1]&&symb[1]==symb[2]&&symb[2]!=symb[3]&&symb[3]==symb[4]) ||
      (symb[1]==symb[2]&&symb[2]==symb[3]&&symb[3]!=symb[0]&&symb[0]==symb[4]) ||
      (symb[2]==symb[3]&&symb[3]==symb[4]&&symb[4]!=symb[0]&&symb[0]==symb[1])) {
    worth="full house";
    return;
  }
  
  //Flush: 5 cards of the same suit, but not in sequence
  if ((suit[0]==suit[1]&&suit[1]==suit[2]&&suit[2]==suit[3]&&suit[3]==suit[4]) &&
      (symb[0]+1!=symb[1]||symb[1]+1!=symb[2]||
       symb[2]+1!=symb[3]||symb[3]+1!=symb[4])) {
    worth="flush";
    return;
  }
  
  //Straight: 5 cards in sequence, not of the same suit
  if ((symb[0]+1==symb[1]&&symb[1]+1==symb[2]&&symb[2]+1==symb[3]&&
       symb[3]+1==symb[4]) && (suit[0]!=suit[1]||suit[1]!=suit[2]||
      suit[2]!=suit[3]||suit[3]!=suit[4])) {
    worth="straight";
    return;
  }
  
  //Three of a kind: 3 cards of the same symbol, and 2 random
  //same if condition as full house, but last == in each (...) changed to !=
  if ((symb[0]==symb[1]&&symb[1]==symb[2]&&symb[2]!=symb[3]&&symb[3]!=symb[4]) ||
      (symb[1]==symb[2]&&symb[2]==symb[3]&&symb[3]!=symb[0]&&symb[0]!=symb[4]) ||
      (symb[2]==symb[3]&&symb[3]==symb[4]&&symb[4]!=symb[0]&&symb[0]!=symb[1])) {
    worth="three of a kind";
    return;
  }
  
  //Two pairs: 2 pairs of same symbol each, and 1 random
  //3 possibilities (symb[5] is ordered): XXYYZ, XXZYY, or ZXXYY
  if ((symb[0]==symb[1]&&symb[1]!=symb[2]&&symb[2]==symb[3]&&symb[3]!=symb[4]) ||
      (symb[0]==symb[1]&&symb[1]!=symb[2]&&symb[2]!=symb[3]&&symb[3]==symb[4]) ||
      (symb[0]!=symb[1]&&symb[1]==symb[2]&&symb[2]!=symb[3]&&symb[3]==symb[4])) {
    worth="two pairs";
    return;
  }
  
  //One pair: 1 pair of same symbol, and 3 random
  //4 possibilities: AABCD, BAACD, BCAAD, or BCDAA
  if ((symb[0]==symb[1]&&symb[1]!=symb[2]&&symb[2]!=symb[3]&&symb[3]!=symb[4]) ||
      (symb[0]!=symb[1]&&symb[1]==symb[2]&&symb[2]!=symb[3]&&symb[3]!=symb[4]) ||
      (symb[0]!=symb[1]&&symb[1]!=symb[2]&&symb[2]==symb[3]&&symb[3]!=symb[4]) ||
      (symb[0]!=symb[1]&&symb[1]!=symb[2]&&symb[2]!=symb[3]&&symb[3]==symb[4])) {
    worth="one pair";
    return;
  }
  
  //No pair: an absolute random hand
  //assert: if this point in the function is reached, the hand is a no pair
  worth="no pair";
}

void PokerHand::PrintHand() {
  for (int i=0; i<5; i++) {
    cout<<"Card "<<i+1<<": "; hand[i].PrintCard();   //PrintCard() from Card
    cout<<endl;
  }
}
