/* Hasan Abdullah: Square.cpp - implementation of Square class */

#include <iostream>
#include <string>
#include <cmath>
#include "Point.h"
#include "Shape.h"
#include "Quadrilateral.h"
#include "Square.h"
using namespace std;

Square::Square(string what, Quadrilateral s) : Quadrilateral(s) {
  name=what;
  square=s;
}

void Square::Print() {
  cout<<"Print() in Square..."<<endl;
  cout<<name<<":"<<endl;
  cout<<"--------------------"<<endl;
  for (int i=0; i<size; i++)
    points[i].Print();
  cout<<"--------------------"<<endl;
}

double Square::Area() {
  double xA=points[0].GetX();   // A---------B
  double yA=points[0].GetY();   // |         |
  double zA=points[0].GetZ();   // |         |
  double xB=points[1].GetX();   // |         |   <- Square
  double yB=points[1].GetY();   // |         |
  double zB=points[1].GetZ();   // D---------C
  double side=sqrt( pow((xA-xB),2)+pow((yA-yB),2)+pow((zA-zB),2) ); //side AB
  double A=pow(side,2);   //Area_square = side^2
  cout<<"Area() of Square is: "<<A<<endl;
  return A;
}
