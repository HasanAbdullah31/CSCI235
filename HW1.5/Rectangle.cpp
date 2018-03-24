/* Hasan Abdullah: Rectangle.cpp - implementation of Rectangle class */

#include <iostream>
#include <string>
#include <cmath>
#include "Point.h"
#include "Shape.h"
#include "Quadrilateral.h"
#include "Rectangle.h"
using namespace std;

Rectangle::Rectangle(string what, Quadrilateral s) : Quadrilateral(s) {
  name=what;
  rectangle=s;
}

void Rectangle::Print() {
  cout<<"Print() in Rectangle..."<<endl;
  cout<<name<<":"<<endl;
  cout<<"--------------------"<<endl;
  for (int i=0; i<size; i++)
    points[i].Print();
  cout<<"--------------------"<<endl;
}

double Rectangle::Area() {
  double xA=points[0].GetX();   // A--------------B
  double yA=points[0].GetY();   // |              |
  double zA=points[0].GetZ();   // |              |
  double xB=points[1].GetX();   // |              |   <- Rectangle
  double yB=points[1].GetY();   // |              |
  double zB=points[1].GetZ();   // D--------------C
  double xC=points[2].GetX();   // Area of ABCD is AB*BC
  double yC=points[2].GetY();
  double zC=points[2].GetZ();
  double base=sqrt( pow((xA-xB),2)+pow((yA-yB),2)+pow((zA-zB),2) ); //side AB
  double height=sqrt( pow((xB-xC),2)+pow((yB-yC),2)+pow((zB-zC),2) ); //side BC
  double A=base*height;   //Area_rectangle = base*height
  cout<<"Area() of Rectangle is: "<<A<<endl;
  return A;
}
