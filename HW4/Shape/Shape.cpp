/* Hasan Abdullah: Shape.cpp - the implementation file for the base class */

#include "Point.h"
#include "Shape.h"

Shape::Shape() {}

Shape::Shape(const int n, Point* p) {
  size=n;
  for (int i=0; i<n; i++)
    points[i]=p[i];
}

//since no object Shape (abstract class) instantiated, destructor is empty
Shape::~Shape() {}
