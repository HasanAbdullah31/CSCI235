/* Hasan Abdullah: Point.cpp - the implementation file for class Point */

#include <iostream>
#include "Point.h"
using namespace std;

Point::Point() {}

Point::Point(double X, double Y, double Z) {
  x=X;
  y=Y;
  z=Z;
}

double Point::GetX() { return x; }
double Point::GetY() { return y; }
double Point::GetZ() { return z; }

void Point::Print() {
  cout<<"Point(x="<<x<<",y="<<y<<",z="<<z<<")"<<endl;
}
