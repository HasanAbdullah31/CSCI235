/* Hasan Abdullah: driver.cpp - uses classes Square, Rectangle, Rhombus, and
Parallelogram (derived classes of Quadrilateral, a derived class of Shape) */

#include <iostream>
#include "Shape.h"
#include "Point.h"
#include "Quadrilateral.h"
#include "Square.h"
#include "Rectangle.h"
#include "Rhombus.h"
#include "Parallelogram.h"
using namespace std;

int main(int argc, char **argv) {
  const int n=4;   //needed by Shape (all quadrilaterals have 4 points)
  
  //Points for a square:
  Point A=Point(3.0, 10.0, 1.0);
  Point B=Point(8.0, 10.0, 1.0);
  Point C=Point(8.0, 5.0, 1.0);
  Point D=Point(3.0, 5.0, 1.0);
  Point myPoints1[n]={A, B, C, D};   //needed by Shape
  Shape myShape=Shape(n, myPoints1);
  myShape.Print();
  cout<<myShape.Area()<<endl;
  Quadrilateral myQuad=Quadrilateral("Quadrilateral", myShape);
  myQuad.Print();
  cout<<myQuad.Area()<<endl;
  Square mySquare=Square("Square", myQuad);
  mySquare.Print();
  mySquare.Area();
  cout<<endl;

  //Points for a rectangle:
  A=Point(3.0, 10.0, 2.0);
  B=Point(12.0, 10.0, 2.0);
  C=Point(12.0, 5.0, 2.0);
  D=Point(3.0, 5.0, 2.0);
  Point myPoints2[n]={A, B, C, D};
  myShape=Shape(n, myPoints2);
  myShape.Print();
  cout<<myShape.Area()<<endl;
  myQuad=Quadrilateral("Quadrilateral", myShape);
  myQuad.Print();
  cout<<myQuad.Area()<<endl;
  Rectangle myRect=Rectangle("Rectangle", myQuad);
  myRect.Print();
  myRect.Area();
  cout<<endl;

  //Points for a rhombus:
  A=Point(3.0, 7.0, 3.0);
  B=Point(5.0, 10.0, 3.0);
  C=Point(7.0, 7.0, 3.0);
  D=Point(5.0, 4.0, 3.0);
  Point myPoints3[n]={A, B, C, D};
  myShape=Shape(n, myPoints3);
  myShape.Print();
  cout<<myShape.Area()<<endl;
  myQuad=Quadrilateral("Quadrilateral", myShape);
  myQuad.Print();
  cout<<myQuad.Area()<<endl;
  Rhombus myRhombus=Rhombus("Rhombus", myQuad);
  myRhombus.Print();
  myRhombus.Area();
  cout<<endl;

  //Points for a parallelogram:
  A=Point(4.0, 6.0, 4.0);
  B=Point(9.0, 6.0, 4.0);
  C=Point(7.0, 3.0, 4.0);
  D=Point(2.0, 3.0, 4.0);
  Point myPoints4[n]={A, B, C, D};
  myShape=Shape(n, myPoints4);
  myShape.Print();
  cout<<myShape.Area()<<endl;
  myQuad=Quadrilateral("Quadrilateral", myShape);
  myQuad.Print();
  cout<<myQuad.Area()<<endl;
  Parallelogram myPar=Parallelogram("Parallelogram", myQuad);
  myPar.Print();
  myPar.Area();
  cout<<endl;
  
  return 0;
}
