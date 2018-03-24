/* Hasan Abdullah: Rectangle.h - .h file for a derived class of Quadrilateral */

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <string>
#include "Point.h"
#include "Shape.h"
#include "Quadrilateral.h"
using namespace std;

class Rectangle : public Quadrilateral {
private:
 string name;
 Quadrilateral rectangle;
public:
 Rectangle(string what, Quadrilateral s);
 //virtual functions from Quadrilateral:
 void Print();
 double Area();
};

#endif /* RECTANGLE_H */
