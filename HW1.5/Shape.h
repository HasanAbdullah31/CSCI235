/* Hasan Abdullah: Shape.h - the header file for the base class */

#ifndef SHAPE_H
#define SHAPE_H

#include "Point.h"

class Shape {
protected:
//pass values onto them through instantiating a Shape object, which
//would then be one of the data members of the derived classes
 static const int MAX_POINTS=20;
 Point points[MAX_POINTS];
 int size;
public:
 Shape();
 Shape(const int n, Point *P);
 //empty functions implemented by derived classes:
 virtual void Print();
 virtual double Area();
};

#endif /* SHAPE_H */
