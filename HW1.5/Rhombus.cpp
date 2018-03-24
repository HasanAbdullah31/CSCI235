/* Hasan Abdullah: Rhombus.cpp - implementation of Rhombus class */

#include <iostream>
#include <string>
#include <cmath>
#include "Point.h"
#include "Shape.h"
#include "Quadrilateral.h"
#include "Rhombus.h"
using namespace std;

Rhombus::Rhombus(string what, Quadrilateral s) : Quadrilateral(s) {
  name=what;
  rhombus=s;
}

void Rhombus::Print() {
  cout<<"Print() in Rhombus..."<<endl;
  cout<<name<<":"<<endl;
  cout<<"--------------------"<<endl;
  for (int i=0; i<size; i++)
    points[i].Print();
  cout<<"--------------------"<<endl;
}

double Rhombus::Area() {
  double xA=points[0].GetX();   /*    B                 */
  double yA=points[0].GetY();   /*   /|\                */
  double zA=points[0].GetZ();   /*  / | \               */
  double xB=points[1].GetX();   /* A-----C   <- Rhombus */
  double yB=points[1].GetY();   /*  \ | /               */
  double zB=points[1].GetZ();   /*   \|/                */
  double xC=points[2].GetX();   /*    D                 */
  double yC=points[2].GetY();
  double zC=points[2].GetZ();   // Area of ABCD is (AC*BD)/2
  double xD=points[3].GetX();
  double yD=points[3].GetY();
  double zD=points[3].GetZ();
  double AC=sqrt( pow((xA-xC),2)+pow((yA-yC),2)+pow((zA-zC),2) );   //side AC
  double BD=sqrt( pow((xB-xD),2)+pow((yB-yD),2)+pow((zB-zD),2) );   //side BD
  double A=(AC*BD)/2;
  cout<<"Area() of Rhombus is: "<<A<<endl;
  return A;
}
