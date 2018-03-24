/* Hasan Abdullah: driver.cpp - the test program */

#include <iostream>
#include <cstdlib>   //for atoi (C-string to int) and exit(1)
#include <climits>   //for SHRT_MIN and SHRT_MAX
#include "MathError.h"
#include "ZeroDivide.h"
#include "IntOverflow.h"
using namespace std;

double Divide(int x, int y);
short Add(short x, short y);
int Add2(short x, short y);

int main(int argc, char **argv) {
  if (argc!=3) {
    cout<<"Usage: ./driver argv[1] argv[2]"<<endl;
    cout<<"Program will now exit."<<endl;
    exit(1);
  }
  int a=atoi(argv[1]);
  int b=atoi(argv[2]);
  ZeroDivide e1=ZeroDivide(a, b);
  IntOverflow e2=IntOverflow(a, b);
  try {
    double c=Divide(a, b);
  }
  catch (MathError) {
    e1.Handler();
  }
  try {
    short d=Add((short )a, (short )b);
  }
  catch (MathError) {
    e2.Handler();
  }
  //Add2(short,short) has try catch within it; Add(short,short) does not
  short n=Add2((short )a, (short )b);
  
  return 0;
}

double Divide(int x, int y) {
  double z;
  if (y==0)
    throw ZeroDivide(x, y);
  z=x/y;
  cout<<x<<"/"<<y<<"="<<z<<endl;
  return z;
}

short Add(short x, short y) {
  short z;
  cout<<"x="<<x<<"\t"<<"y="<<y<<"\t"<<"SHRT_MAX="<<SHRT_MAX<<endl;
  if ((x>0 && y>0 && x>SHRT_MAX-y) || (x<0 && y<0 && x<SHRT_MIN-y))
    throw IntOverflow(x, y);
  z=x+y;
  cout<<x<<"+"<<y<<"="<<z<<endl;
  return z;
}

int Add2(short x, short y) {
  short z;
  IntOverflow e2=IntOverflow();
  try {
    z=x+y;
    if ((x>0 && y>0 && x>SHRT_MAX-y) || (x<0 && y<0 && x<SHRT_MIN-y))
      throw IntOverflow(x, y);
    cout<<x<<"+"<<y<<"="<<z<<endl;
  }
  catch (MathError) {
    e2.Handler();
  }
  return z;
}
