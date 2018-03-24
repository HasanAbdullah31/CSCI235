/* Hasan Abdullah: Parallelogram.h - .h for derived class of Quadrilateral */

#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H

#include <string>
#include "Point.h"
#include "Shape.h"
#include "Quadrilateral.h"
using namespace std;

class Parallelogram : public Quadrilateral {
private:
 string name;
 Quadrilateral parallelogram;
public:
 Parallelogram(string what, Quadrilateral s);
 //virtual functions from Quadrilateral:
 void Print();
 double Area();
};

#endif /* PARALLELOGRAM_H */
