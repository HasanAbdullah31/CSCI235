/* Hasan Abdullah: Quadrilateral.h - header file for a derived class of Shape */

#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H

#include <string>
#include "Point.h"
#include "Shape.h"
using namespace std;

class Quadrilateral : public Shape {
protected:
 string name;
 Shape quadrilateral;
public:
 Quadrilateral();
 Quadrilateral(string what, Shape s);
 //virtual functions from Shape will be virtual functions for Quadrilateral:
 virtual void Print();
 virtual double Area();
};

#endif /* QUADRILATERAL_H */
