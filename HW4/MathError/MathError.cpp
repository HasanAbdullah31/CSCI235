/* Hasan Abdullah: MathError.cpp - implementation file for the base class */

#include <iostream>
#include "MathError.h"
using namespace std;

MathError::MathError() {}

void MathError::Handler() {
  cout<<"This should have been overwritten."<<endl;
}
