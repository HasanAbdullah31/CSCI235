/* Hasan Abdullah: Shape.h - the header file for the base class */

#ifndef SHAPE_H
#define SHAPE_H

#include <stdlib.h>   //for malloc
#include "Point.h"
using namespace std;

class Shape {
protected:
 int size=20;
 Point* points=(Point* )malloc(size*sizeof(Point));
public:
 Shape();
 Shape(const int n, Point* P);
 //pure virtual functions, so Shape is an abstract class:
 virtual ~Shape() =0;
 virtual void Print() =0;
 virtual double Area() =0;
};

#endif /* SHAPE_H */
