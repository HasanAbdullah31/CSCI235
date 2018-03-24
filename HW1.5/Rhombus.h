/* Hasan Abdullah: Rhombus.h - .h file for a derived class of Quadrilateral */

#ifndef RHOMBUS_H
#define RHOMBUS_H

#include <string>
#include "Point.h"
#include "Shape.h"
#include "Quadrilateral.h"
using namespace std;

class Rhombus : public Quadrilateral {
private:
 string name;
 Quadrilateral rhombus;
public:
 Rhombus(string what, Quadrilateral s);
 //virtual functions from Quadrilateral:
 void Print();
 double Area();
};

#endif /* RHOMBUS_H */
