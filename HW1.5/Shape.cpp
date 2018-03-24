/* Hasan Abdullah: Shape.cpp - the implementation file for the base class */

#include <iostream>
#include "Shape.h"
#include "Point.h"
using namespace std;

Shape::Shape() {}

Shape::Shape(const int n, Point *p) {
  size=n;
  for (int i=0; i<n; i++)
    points[i]=p[i];
}

//virtual/empty functions, implemented in derived classes:
void Shape::Print() { cout<<"Virtual Print() in Shape..."<<endl; }
double Shape::Area() { cout<<"Virtual Area() in Shape..."<<endl; return 0.0; }
