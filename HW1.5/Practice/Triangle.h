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
 Shape triangle;
public:
 Triangle(string what, Shape s);
 //virtual functions from Shape:
 void Print();
 double Area();
};

#endif /* TRIANGLE_H */
