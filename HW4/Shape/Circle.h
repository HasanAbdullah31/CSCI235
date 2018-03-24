/* Hasan Abdullah: Circle.h - the header file for one of the derived classes */

#ifndef CIRCLE_H
#define CIRCLE_H

#include <string>
#include "Point.h"
#include "Shape.h"
using namespace std;

class Circle : public Shape {
private:
 string name;
 double radius;
public:
 Circle(string what, double r, int n, Point* p);
 //pure virtual functions from Shape, implemented here (concrete class)
 ~Circle();
 double Area();
 void Print();
};

#endif /* CIRCLE_H */
