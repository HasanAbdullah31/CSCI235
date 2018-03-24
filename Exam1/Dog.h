/* Hasan Abdullah: Dog.h - header file for derived class Dog */

#ifndef DOG_H
#define DOG_H

#include "Pet.h"

class Dog : public Pet {
private:
 Values info;
public:
 Dog();
 Dog(Values v);
 void Print();
 friend bool operator>(Dog d1, Dog d2);
};

#endif /* DOG_H */
