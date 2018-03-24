/* Hasan Abdullah: LCS.cpp - Memoized Recursive LCS, and print the LCS */

#include "Color.h"   //to color the LCS in X and Y
#include <iostream>
#include <string>
using namespace std;

char X[7]={'A', 'B', 'C', 'B', 'D', 'A', 'B'};
char Y[6]={'B', 'D', 'C', 'A', 'B', 'A'};
int memo[8][7];

int LCS_Length(char X[7], char Y[6]);
int SubProblem(int i, int j);
string LCS(int memo[8][7]);   //precond: memo is filled by calling LCS_Length

int main (int argc, char **argv) {
  for (int i=0; i<=7; i++)
    for (int j=0; j<=6; j++)
      memo[i][j]=-1;
  int LCS_length=LCS_Length(X,Y);   //side effect: memo is filled appropriately
  string LCS_string=LCS(memo);
  cout<<"X=";
  int L=0;   //iterator for LCS_string
  for (int j=0; j<7; j++) {
    if (X[j]==LCS_string[L] && L<LCS_string.length()) {
      cout<<Color::F_RED<<X[j];
      L++;
    }
    else
      cout<<Color::F_DEFAULT<<X[j];
  }
  cout<<Color::RESET<<endl<<"Y=";
  L=0;
  for (int k=0; k<6; k++) {
    if (Y[k]==LCS_string[L] && L<LCS_string.length()) {
      cout<<Color::F_RED<<Y[k];
      L++;
    }
    else
      cout<<Color::F_DEFAULT<<Y[k];
  }
  cout<<Color::RESET<<endl;
  cout<<"Length(LCS(X,Y))="<<LCS_length<<endl;
  cout<<"The LCS is: "<<Color::F_RED<<LCS_string;
  cout<<Color::RESET<<endl;
  return 0;
}

int LCS_Length(char X[7], char Y[6]) {
  return SubProblem(7,6);
}

int SubProblem(int i, int j) {
  if (i==0 || j==0)
    memo[i][j]=0;
  else if (X[i-1]==Y[j-1])
    memo[i][j]=1+SubProblem(i-1, j-1);
  else
    memo[i][j]=max(SubProblem(i-1, j),
                   SubProblem(i, j-1));
  return memo[i][j];
}

string LCS(int memo[8][7]) {
  int index=memo[7][6];   //start from bottom right corner of memo matrix
  char LCS[index+1];   //value in memo's bottom right corner is size of the LCS
  LCS[index]='\0';   //terminate array of char (i.e. string) with NULL (=='\0')
  int i=7, j=6;   //i indexes X and j indexes Y
  while (i>0 && j>0) {
    if (X[i-1]==Y[j-1]) {
      LCS[index-1]=X[i-1]; //or =Y[j-1]; fill in LCS from last element to first
      index--; i--; j--;   //continue checking from last elements to first
    }
    else if (memo[i-1][j]>memo[i][j-1]) //if value above is greater, go up
      i--;
    else //if value to left (or diagonal) is greater, go left (or diagonal)
      j--;
  }
  //assert: LCS[index] is an array of characters (i.e. string) of LCS
  return LCS;   //legal b/c array of char is equivalent to string
}
