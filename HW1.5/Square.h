/* Hasan Abdullah: Square.h - .h file for a derived class of Quadrilateral */

#ifndef SQUARE_H
#define SQUARE_H

#include <string>
#include "Point.h"
#include "Shape.h"
#include "Quadrilateral.h"
using namespace std;

class Square : public Quadrilateral {
private:
 string name;
 Quadrilateral square;
public:
 Square(string what, Quadrilateral s);
 //virtual functions from Quadrilateral:
 void Print();
 double Area();
};

#endif /* SQUARE_H */
