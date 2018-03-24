/* Hasan Abdullah: driver.cpp - instantiates Cat and Dog arrays, then sorts */

#include <iostream>
#include "Array.h"
#include "Pet.h"
#include "Cat.h"
#include "Dog.h"
using namespace std;

int main(int argc, char **argv) {
  Pet myPets("pets.txt");
  cout<<"Original file 'pets.txt' ordered as such:"<<endl;
  myPets.Print();
  cout<<endl;
  int cat_SIZE=0, dog_SIZE=0;
  for (int i=0; i<myPets.Size(); i++) {
    if (myPets.Get(i).type==Type::Cat)
      cat_SIZE++;
    else
      dog_SIZE++;
  }
  Cat cats[cat_SIZE]; int cats_i=0;
  Dog dogs[dog_SIZE]; int dogs_i=0;
  for (int j=0; j<myPets.Size(); j++) {
    if (myPets.Get(j).type==Type::Cat) {
      cats[cats_i]=Cat(myPets.Get(j));
      cats_i++;
    }
    else {
      dogs[dogs_i]=Dog(myPets.Get(j));
      dogs_i++;
    }
  }
  Array<Cat> myCats=Array<Cat>(cats,cat_SIZE);
  Array<Dog> myDogs=Array<Dog>(dogs,dog_SIZE);
  cout<<"Cats in alphabetical order:"<<endl;
  myCats.Sort(); myCats.Print();
  cout<<endl;
  cout<<"Dogs in alphabetical order:"<<endl;
  myDogs.Sort(); myDogs.Print();

  return 0;
}
