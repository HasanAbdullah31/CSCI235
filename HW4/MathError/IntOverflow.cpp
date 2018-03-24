/* Hasan Abdullah: IntOverflow.cpp - implementation of class IntOverflow */

#include <iostream>
#include "MathError.h"
#include "IntOverflow.h"
using namespace std;

IntOverflow::IntOverflow() {}

IntOverflow::IntOverflow(short x, short y) : MathError() {
  a=x;
  b=y;
}

void IntOverflow::Handler() {
  cout<<"Result too large for type short."<<endl;
  cout<<"Overflow."<<endl;
}
