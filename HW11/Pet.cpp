/* Hasan Abdullah: Pet.cpp - implementation of class Pet */

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include "Color.h"   //to color the output
#include "Pet.h"
using namespace std;

Pet::Pet() {}

Pet::Pet(string filename) {
  ifstream input;
  input.open(filename.c_str());
  if (input.fail()) {
    cout<<"File not found!"<<endl;
    exit(1);
  }
  while (!input.eof()) {
    input>>*(this);   //let friend function >> do the work
  }
  input.close();
}

istream &operator>>(istream &input, Pet &pet) {
  if (input.peek()==EOF) return input;   //skip last empty line
  string type_field; string name_field; int age_field; string breed_field;
  getline(input,type_field,'\t');
  if (type_field=="Cat") {
    pet.type[pet.line_number]=Type::Cat;
  }
  else if (type_field=="Dog") {
    pet.type[pet.line_number]=Type::Dog;
  }
  else {
    cout<<"Key field must be 'Cat' or 'Dog'!"<<endl;
    exit(1);
  }
  //getline for possible spaces in the fields (e.g. name could be John Doe)
  getline(input,name_field,'\t'); pet.name[pet.line_number]=name_field;
  input>>age_field;               pet.age[pet.line_number]=age_field;
  input.ignore(99,'\t');   //ignore the tab after the age field
  getline(input,breed_field,'\n'); pet.breed[pet.line_number]=breed_field;
  if (input.fail()) {
    cout<<"Invalid data format!"<<endl;
    exit(1);
  }
  else
    pet.line_number++;
  return input;   //for multiple >> operators
}

int Pet::Size() { return SIZE; }

Values Pet::Get(int i) {
  if (i>=0 && i<SIZE) {
    Values temp={type[i],name[i],age[i],breed[i]};
    return temp;
  }
  else {
    cout<<"Out of range!"<<endl;
    exit(1);
  }
}

void Pet::PrintFormat(int width, Type t) {
  string x;
  if (t==Type::Cat)
    x="Cat";
  else //if (t==Type::Dog)
    x="Dog";
  cout<<left<<setw(width)<<setfill(' ')<<x;
}
void Pet::PrintFormat(int width, string s) {
  cout<<left<<setw(width)<<setfill(' ')<<s;
}
void Pet::PrintFormat(int width, int n) {
  cout<<left<<setw(width)<<setfill(' ')<<n;
}
void Pet::PrintLine(int i) {   //precond: i>=0 && i<SIZE
  PrintFormat(6,type[i]);   //Dog and Cat 3 letters each, so 6 gives 3 spaces
  PrintFormat(11,name[i]);  //assuming name has max 10 characters (>=1 space)
  PrintFormat(5,age[i]);    //age is max of 2 characters (>=3 spaces)
  PrintFormat(20,breed[i]); //breed is max of 20 characters
}
void Pet::Print() {
  cout<<"In virtual Print() of Pet..."<<endl;
  for (int i=0; i<SIZE; i++) {
    PrintLine(i); cout<<endl;
  }
}
void Pet::Print(Color c1, Color c2) {
  cout<<"In virtual Print(Color,Color) of Pet...\n";
  Color reset(RESET);   //to reset the output color at end of each line
  for (int i=0; i<SIZE; i++) {
    if (type[i]==Type::Cat) cout<<c1;
    else cout<<c2;
    PrintLine(i); cout<<reset<<endl;
  }
}
