/* Hasan Abdullah: Dog.h - header file for derived class Dog */

#ifndef DOG_H
#define DOG_H

#include "Pet.h"

class Dog : public Pet {
private:
 int key;
 Values info;
public:
 Dog();
 Dog(int k, Values v);
 int Get_Key();
 string Get_Name();
 void Print();
 friend bool operator>(Dog d1, Dog d2);
 friend bool operator>=(Dog d1, Dog d2);
 friend bool operator==(Dog d1, Dog d2);
 friend bool operator<(Dog d1, Dog d2);
 friend bool operator<=(Dog d1, Dog d2);
};

#endif /* DOG_H */
