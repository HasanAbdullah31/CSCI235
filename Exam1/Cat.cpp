/* Hasan Abdullah: Cat.cpp - implementation of class Cat */

#include <string>
#include <iostream>
#include "Pet.h"
#include "Cat.h"
using namespace std;

Cat::Cat() {}

Cat::Cat(Values v) : Pet() {
  if (v.type==Type::Cat) {
    info.type=Type::Cat;
    info.name=v.name;
    info.age=v.age;
    info.breed=v.breed;
  }
  else {
    cout<<"Warning! Dog values are in Cat values!"<<endl;
  }
}

void Cat::Print() {
  //PrintFormat is a protected member function of Pet
  PrintFormat(6,info.type);
  PrintFormat(11,info.name);
  PrintFormat(5,info.age);
  PrintFormat(20,info.breed);
  cout<<endl;
}

bool operator>(Cat c1, Cat c2) {
  if (c1.info.name>c2.info.name)   //strings have > already
    return true;
  else if (c1.info.name==c2.info.name) {   //cats with same name
    if (c1.info.age>c2.info.age)
      return true;
    else if (c1.info.age==c2.info.age) {   //cats with same name and age
      if (c1.info.breed>c2.info.breed)
	return true;
      //assume cats with same name,age, & breed not possible
      else //if (c1.info.breed<c2.info.breed)
	return false;
    }
    else //if (c1.info.age<c2.info.age)
      return false;
  }
  else //if (c1.info.name<c2.info.name)
    return false;
}
