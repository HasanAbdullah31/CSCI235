/* Hasan Abdullah: Cat.h - header file for derived class Cat */

#ifndef CAT_H
#define CAT_H

#include "Pet.h"

enum Hair {SH, LH, SH_LH};

class Cat : public Pet {
private:
 int key;
 Hair hair;
 Values info;
public:
 Cat();
 Cat(int k, Values v);
 int Get_Key();
 string Get_Name();
 void Print();
 friend bool operator>(Cat c1, Cat c2);
 friend bool operator>=(Cat c1, Cat c2);
 friend bool operator==(Cat c1, Cat c2);
 friend bool operator<(Cat c1, Cat c2);
 friend bool operator<=(Cat c1, Cat c2);
};

#endif /* CAT_H */
