/* Hasan Abdullah: Dog.cpp - implementation of class Dog */

#include <iostream>
#include "Pet.h"
#include "Dog.h"
using namespace std;

Dog::Dog() {}

Dog::Dog(int k, Values v) : Pet() {
  if (v.type==Type::Dog) {
    key=k;
    info.type=Type::Dog;
    info.name=v.name;
    info.age=v.age;
    info.breed=v.breed;
  }
  else {
    cout<<"Warning! Cat values are in Dog values!"<<endl;
  }
}

int Dog::Get_Key() { return key; }

string Dog::Get_Name() { return info.name; }

void Dog::Print() {
  //PrintFormat is a protected member function of Pet
  PrintFormat(6,info.type);
  PrintFormat(11,info.name);
  PrintFormat(5,info.age);
  PrintFormat(20,info.breed);
  cout<<endl;
}

bool operator>(Dog d1, Dog d2) {
  if (d1.info.name>d2.info.name)   //strings have > already
    return true;
  else if (d1.info.name==d2.info.name) {   //dogs with same name
    if (d1.info.age>d2.info.age)
      return true;
    else if (d1.info.age==d2.info.age) {   //dogs with same name and age
      if (d1.info.breed>d2.info.breed)
	return true;
      else //if (d1.info.breed<=d2.info.breed)
	return false;
    }
    else //if (d1.info.age<d2.info.age)
      return false;
  }
  else //if (d1.info.name<d2.info.name)
    return false;
}

bool operator==(Dog d1, Dog d2) {
  if (d1.info.name==d2.info.name && d1.info.age==d2.info.age &&
      d1.info.breed==d2.info.breed)
    return true;
  else
    return false;
}

bool operator>=(Dog d1, Dog d2) { return (d1>d2 || d1==d2); }

bool operator<(Dog d1, Dog d2) { return !(d1>=d2); }

bool operator<=(Dog d1, Dog d2) { return !(d1>d2); }
