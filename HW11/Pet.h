/* Hasan Abdullah: Pet.h - header file for base class Pet */

#ifndef PET_H
#define PET_H

#include <string>
#include "Color.h"   //to color the output
using namespace std;

enum class Type {Cat,Dog};
struct Values {Type type; string name; int age; string breed;};

class Pet {
private:
 int line_number=0;   //increments each time a new line is found in pets.txt
protected:
 static const int SIZE=12;   //number of lines in pets.txt
 Type type[SIZE];
 string name[SIZE];
 int age[SIZE];
 string breed[SIZE];
 friend istream &operator>>(istream &input, Pet &pet);
 void PrintFormat(int width, Type t);
 void PrintFormat(int width, string s);
 void PrintFormat(int width, int n);
 void PrintLine(int i);
public:
 Pet();
 Pet(string filename);
 int Size();
 Values Get(int i);
 virtual void Print();
 void Print(Color c1, Color c2);   //c1 for cats, c2 for dogs
};

#endif /* PET_H */
