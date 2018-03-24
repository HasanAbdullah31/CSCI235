/* Hasan Abdullah: Quadrilateral.cpp-implementation file for Quadrilateral.h */

#include <iostream>
#include <string>
#include "Point.h"
#include "Shape.h"
#include "Quadrilateral.h"
using namespace std;

Quadrilateral::Quadrilateral() {}

Quadrilateral::Quadrilateral(string what, Shape s) : Shape(s) {
  name=what;
  quadrilateral=s;
}

//virtual/empty functions, implemented in derived classes of Quadrilateral:
void Quadrilateral::Print() {
  cout<<"Virtual Print() in Quadrilateral..."<<endl;
}
double Quadrilateral::Area() {
  cout<<"Virtual Area() in Quadrilateral..."<<endl;
  return 0.0;
}
