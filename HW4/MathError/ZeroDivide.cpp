/* Hasan Abdullah: ZeroDivide.cpp - implementation file for class ZeroDivide */

#include <iostream>
#include "MathError.h"
#include "ZeroDivide.h"
using namespace std;

ZeroDivide::ZeroDivide(int x, int y) : MathError() {
  a=x;
  b=y;
}

void ZeroDivide::Handler() {
  cout<<"Your divisor is: b="<<b<<endl;
  cout<<"Illegal denominator. Division by zero."<<endl;
}
