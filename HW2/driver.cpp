/* Hasan Abdullah: driver.cpp - objects are instantiated and used */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Card.h"
#include "PokerHand.h"
using namespace std;

int main(int argc, char **argv) {
  if (argc!=2) {
    cout<<"Need 2 arguments! (example: ./driver 1)"<<endl;
    return 1;
  }
  if (atoi(argv[1])<0 || atoi(argv[1])>5) {
    cout<<"2nd argument must be an integer between 0 and 5 (inclusive)."<<endl;
    return 1;
  }
  srand(time(0));   //seed to generate multiple random numbers in Replace()
  Card myCard; Card hand[5];
  
  myCard=Card("Q", "hearts");  hand[0]=myCard;
  myCard=Card("9", "hearts");  hand[1]=myCard;
  myCard=Card("10", "hearts"); hand[2]=myCard;
  myCard=Card("K", "hearts");  hand[3]=myCard;
  myCard=Card("J", "hearts");  hand[4]=myCard;
  //myCard=Card("A", "hearts");   hand[0]=myCard;
  //myCard=Card("A", "clubs");    hand[1]=myCard;
  //myCard=Card("A", "spades");   hand[2]=myCard;
  //myCard=Card("A", "diamonds"); hand[3]=myCard;
  //myCard=Card("2", "hearts");   hand[4]=myCard;
  
  PokerHand myHand=PokerHand(hand);
  cout<<"Print myHand as is:"<<endl;
  myHand.PrintHand();
  cout<<"Print myHand in ascending order:"<<endl;
  myHand.Arrange(); myHand.PrintHand();
  cout<<"Rank of myHand is: "; myHand.Evaluate(); cout<<myHand.GetWorth()<<endl;
  cout<<"Print myHand with "<<argv[1]<<" card(s) replaced:"<<endl;
  PokerHand newHand=myHand;   //keep myHand original cards to compare w/ newHand
  newHand.Replace(atoi(argv[1])); newHand.PrintHand();
  cout<<"Print newHand in ascending order:"<<endl;
  newHand.Arrange(); newHand.PrintHand();
  cout<<"Rank of newHand is: "; newHand.Evaluate(); cout<<newHand.GetWorth()<<endl;
  cout<<"The more valuable hand is: ";
  if (myHand>newHand)
    cout<<"myHand."<<endl;
  else if (newHand>myHand)
    cout<<"newHand."<<endl;
  else //if (!(myHand>newHand)&&!(newHand>myHand))
    cout<<"neither; it's a tie."<<endl;
  
  return 0;
}
