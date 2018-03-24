/* Hasan Abdullah: Triangle.cpp - the implementation file for class Triangle */

#include <iostream>
#include <string>
#include <cmath>
#include "Point.h"
#include "Shape.h"
#include "Triangle.h"
using namespace std;

Triangle::Triangle(string what, Shape s) : Shape(s) {
  name=what;
  triangle=s;
}

void Triangle::Print() {
  cout<<name<<":"<<endl;
  cout<<"--------------------"<<endl;
  for (int i=0; i<size; i++)
    points[i].Print();
  cout<<"--------------------"<<endl;
}

double Triangle::Area() {
  double xA=points[0].GetX();
  double yA=points[0].GetY();
  double zA=points[0].GetZ();
  double xB=points[1].GetX();
  double yB=points[1].GetY();
  double zB=points[1].GetZ();
  double xC=points[2].GetX();
  double yC=points[2].GetY();
  double zC=points[2].GetZ();
  double a=sqrt(pow((xB-xC),2)+pow((yB-yC),2)+pow((zB-zC),2));
  double b=sqrt(pow((xA-xC),2)+pow((yA-yC),2)+pow((zA-zC),2));
  double c=sqrt(pow((xB-xA),2)+pow((yB-yA),2)+pow((zB-zA),2));
  double p=(a+b+c)/2;
  double A=sqrt(p*(p-a)*(p-b)*(p-c));
  return A;
}
