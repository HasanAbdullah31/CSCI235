/* Hasan Abdullah: Triangle.h - header file for another derived class */

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <string>
#include "Point.h"
#include "Shape.h"
using namespace std;

class Triangle : public Shape {
private:
 string name;
public:
 Triangle(string what, int n, Point* p);
 //pure virtual functions from Shape, implemented here (concrete class)
 ~Triangle();
 double Area();
 void Print();
};

#endif /* TRIANGLE_H */
