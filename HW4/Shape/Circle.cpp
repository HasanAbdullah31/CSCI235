/* Hasan Abdullah: Circle.cpp - the implementation file for class Circle */

#include <iostream>
#include <string>
#include <cmath>
#include <stdlib.h>   //for free(this) used in destructor
#include "Point.h"
#include "Shape.h"
#include "Circle.h"
using namespace std;

Circle::Circle(string what, double r, int n, Point* p) : Shape(n, p) {
  name=what;
  radius=r;
  size=n;   //size inherited from Shape (protected member)
  for (int i=0; i<size; i++)
    points[i]=p[i];   //points[i] also inherited from Shape
}

Circle::~Circle() {
  cout<<"Executing ~Circle() destructor..."<<endl;
  free(this);
}

double Circle::Area() {
  double M_PI=3.14159265358979323846;
  return M_PI*pow(radius,2);   //Area_circle=pi*r^2
}

void Circle::Print() {
  cout<<"--------------------"<<endl;
  cout<<name<<":"<<endl;
  cout<<"--------------------"<<endl;
  for (int i=0; i<size; i++)
    points[i].Print();
  cout<<"radius="<<radius<<endl;
  cout<<"area="<<Area()<<endl;
  cout<<"--------------------"<<endl;
}
