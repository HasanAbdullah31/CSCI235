/* Hasan Abdullah: Parallelogram.cpp - implementation of Parallelogram class */

#include <iostream>
#include <string>
#include <cmath>
#include "Point.h"
#include "Shape.h"
#include "Quadrilateral.h"
#include "Parallelogram.h"
using namespace std;

Parallelogram::Parallelogram(string what, Quadrilateral s) : Quadrilateral(s) {
  name=what;
  parallelogram=s;
}

void Parallelogram::Print() {
  cout<<"Print() in Parallelogram..."<<endl;
  cout<<name<<":"<<endl;
  cout<<"--------------------"<<endl;
  for (int i=0; i<size; i++)
    points[i].Print();
  cout<<"--------------------"<<endl;
}

double Parallelogram::Area() {
  double xA=points[0].GetX();   //      A---------B
  double yA=points[0].GetY();   //     / \       /
  double zA=points[0].GetZ();   //    /   \     /
  double xB=points[1].GetX();   //   /     \   /   <- Parallelogram
  double yB=points[1].GetY();   //  /       \ /
  double zB=points[1].GetZ();   // D---------C
  double xC=points[2].GetX();   // The area of ABCD is 2*(Area_triangle ABC)
  double yC=points[2].GetY();   // because triangle ABC=triangle CDA.
  double zC=points[2].GetZ();
  double a=sqrt( pow((xB-xC),2)+pow((yB-yC),2)+pow((zB-zC),2) );   //side BC
  double b=sqrt( pow((xA-xC),2)+pow((yA-yC),2)+pow((zA-zC),2) );   //side AC
  double c=sqrt( pow((xB-xA),2)+pow((yB-yA),2)+pow((zB-zA),2) );   //side BA
  double p=(a+b+c)/2;   //half perimeter of triangle ABC
  double A=sqrt( p*(p-a)*(p-b)*(p-c) );   //Area_triangle ABC
  A*=2;   //Area_rectangle ABCD = 2*(Area_triangle ABC)
  cout<<"Area() of Parallelogram is: "<<A<<endl;
  return A;
}
