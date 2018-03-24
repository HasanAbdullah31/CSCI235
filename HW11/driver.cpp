/* Hasan Abdullah: driver.cpp - It's PriorityQueue/Heapsorting Cats and Dogs */

#include <iostream>
#include "Color.h"   //to color the output
#include "Array.h"
#include "Pet.h"
#include "Cat.h"
#include "Dog.h"
using namespace std;

const Color color1=Color(F_RED), color2=Color(F_BLUE), reset=Color(RESET);
/* e.g.: cout<<color1<<"cat"<<color2<<"dog"<<reset<<endl;
   "cat" output in color1, "dog" in color2, and default color on next lines */

int main(int argc, char **argv) {
  Pet myPets("pets.txt");
  cout<<"Original file 'pets.txt' ordered as such:"<<endl;
  myPets.Print(color1,color2);   //cats printed in color1, dogs in color2
  cout<<endl;   //extra new line
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
      cats[cats_i]=Cat(cats_i,myPets.Get(j));
      cats_i++;
    }
    else {
      dogs[dogs_i]=Dog(dogs_i,myPets.Get(j));
      dogs_i++;
    }
  }
  Array<Cat> myCats=Array<Cat>(cats,cat_SIZE);
  Array<Dog> myDogs=Array<Dog>(dogs,dog_SIZE);
  cout<<"List of cats in alphabetical order:"<<endl; myCats.HeapSort();
  cout<<color1; myCats.Print(); cout<<reset<<endl;   //extra new line
  cout<<"List of dogs in alphabetical order:"<<endl; myDogs.HeapSort();
  cout<<color2; myDogs.Print(); cout<<reset<<endl;   //extra new line
  /* Priority Queue Insert: */
  Values c; c.type=Type::Cat; c.name="Garfield"; c.age=12;
  c.breed="Exotic Shorthair"; Cat newCat(cats_i,c); myCats.Insert(newCat);
  cout<<color1<<c.name<<reset<<" has entered the show!"<<endl;
  Values d; d.type=Type::Dog; d.name="Odie"; d.age=11;
  d.breed="Dachshund"; Dog newDog(dogs_i,d); myDogs.Insert(newDog);
  cout<<color2<<d.name<<reset<<" has entered the show!"<<endl;
  cout<<endl;   //extra new line
  cout<<"Updated list of cats in alphabetical order:"<<endl; myCats.HeapSort();
  cout<<color1; myCats.Print(); cout<<reset<<endl;   //extra new line
  cout<<"Updated list of dogs in alphabetical order:"<<endl; myDogs.HeapSort();
  cout<<color2; myDogs.Print(); cout<<reset<<endl;   //extra new line
  
  return 0;
}
