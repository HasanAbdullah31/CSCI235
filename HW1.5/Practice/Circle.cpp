/* Hasan Abdullah: Circle.cpp - the implementation file for class Circle */

#include <iostream>
#include <string>
#include <cmath>
#include "Point.h"
#include "Shape.h"
#include "Circle.h"
using namespace std;

Circle::Circle(string what, double r, Shape s) : Shape(s) {
  name=what;
  radius=r;
  circle=s;
}

void Circle::Print() {
  cout<<name<<":"<<endl;
  cout<<"--------------------"<<endl;
  for (int i=0; i<size; i++)   //size is protected member of Shape
    points[i].Print();   //points[size] also protected member of Shape
    //but Print() is Circle's own implementation (not Shape's)
  cout<<"radius="<<radius<<endl;
  cout<<"--------------------"<<endl;
}

double Circle::Area() {
  double M_PI=3.14159265358979323846;
  return M_PI*pow(radius,2);   //Area_circle=pi*r^2
}
