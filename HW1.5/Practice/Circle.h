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
 Shape circle;   //derived classes declare data members Point *, size, and name
public:
 Circle(string what, double r, Shape s);
 //virtual functions from Shape:
 void Print();
 double Area();
};

#endif /* CIRCLE_H */
