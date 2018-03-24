/* Hasan Abdullah: Point.h - the header file for class Point */

#ifndef POINT_H
#define POINT_H

class Point {
private:
 double x;
 double y;
 double z;
public:
 Point();
 Point(double X, double Y, double Z);
 double GetX();
 double GetY();
 double GetZ();
 void Print();
};

#endif /* POINT_H */
