/* Hasan Abdullah: driver.cpp - declares and instantiates an object Circle and
an object Triangle, using the Print() utility from the parent class Shape */

#include <iostream>
#include <new>
#include "Point.h"
#include "Shape.h"
#include "Circle.h"
#include "Triangle.h"
using namespace std;

int main(int argc, char **argv) {
  Point P=Point(1.0, 2.0, 3.0);
  const int m=1;   //needed by Shape
  Point myPoints1[m]={P};   //needed by Shape
  double r=5.0;   //needed by Circle
  Circle* myCircle=new Circle("circle", r, m, myPoints1);
  myCircle->Print();
  cout<<"Address of myCircle is: "<<myCircle<<endl;
  myCircle->~Circle();
  
  Point A=Point(5.0, 8.0, 1.0);
  Point B=Point(2.0, 2.0, 2.0);
  Point C=Point(8.0, 3.0, 3.0);
  const int n=3;
  Point myPoints2[n]={A, B, C};
  Triangle* myTriangle=new Triangle("triangle", n, myPoints2);
  myTriangle->Print();
  cout<<"Address of myTriangle is: "<<myTriangle<<endl;
  myTriangle->~Triangle();   //delete myTriangle; would do the same thing
  
  return 0;
}
