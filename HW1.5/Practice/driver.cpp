/* Hasan Abdullah: driver.cpp - declares and instantiates an object Circle and
an object Triangle, using the Print() utility from the parent class Shape */

#include <iostream>
#include "Shape.h"
#include "Point.h"
#include "Circle.h"
#include "Triangle.h"
using namespace std;

int main(int argc, char **argv) {
  //In terms of Shape, we need: a name, a size, a Point array, and a radius
  Point P=Point(1.0, 2.0, 3.0);
  const int m=1;   //needed by Shape
  Point myPoints1[m]={P};   //needed by Shape
  double r=5.0;   //needed by Circle
  Shape myShape1=Shape(m, myPoints1);
  cout<<"Print() from Shape:"<<endl;
  myShape1.Print();
  cout<<"Area() from Shape: "<<myShape1.Area()<<endl<<endl;   //2 new lines
  Circle myCircle=Circle("circle", r, myShape1);
  cout<<"Print() from Circle:"<<endl;
  myCircle.Print();
  cout<<"Area() from Circle: "<<myCircle.Area()<<endl<<endl;   //2 new lines
  
  Point A=Point(5.0, 8.0, 1.0);
  Point B=Point(2.0, 2.0, 2.0);
  Point C=Point(8.0, 3.0, 3.0);
  const int n=3;
  Point myPoints2[n]={A, B, C};
  Shape myShape2=Shape(n, myPoints2);
  cout<<"Print() from Shape:"<<endl;
  myShape2.Print();
  cout<<"Area() from Shape: "<<myShape2.Area()<<endl<<endl;   //2 new lines
  Triangle myTriangle=Triangle("triangle", myShape2);
  cout<<"Print() from Triangle:"<<endl;
  myTriangle.Print();
  cout<<"Area() from Triangle: "<<myTriangle.Area()<<endl;   //1 new line
  
  return 0;
}
