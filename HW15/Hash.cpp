/* Hasan Abdullah: Hash.cpp - implementation of class Hash */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Hash.h"
using namespace std;

Hash::Hash() { size=0; }
Hash::Hash(string filename) {
  ifstream myFile;
  myFile.open(filename.c_str(), ifstream::binary);
  if (myFile.fail()) {
    cout<<"Unable to open text file '"<<filename<<"'!"<<endl;
    exit(1);
  }
  //assume the file has the correct format
  Data data; Node* node;
  while (myFile.peek()!=EOF) {
    getline(myFile,data.key,',');
    myFile.seekg(1,ios::cur);   //skip the space after the comma
    getline(myFile,data.name,'\t');
    getline(myFile,data.ID,'\n');
    node=new Node(data);
    Insert(node);   //Hash's Input() method
  }
  myFile.close();
}
Hash::Hash(Node* input[], int s) {
  for (int i=0; i<s; i++) {
    Insert(input[i]);   //Hash's Input() method
  }
}

int Hash::hash(string k) {
  int ascii_value=0;
  for (int i=0; i<k.length(); i++) {
    ascii_value+=(int)k[i];
  }
  return ascii_value%SIZE;
}

int Hash::indexOf(string k) { return hash(k); }
List* Hash::getList(int i) {
  if (i<0 || i>=SIZE) {
    cout<<"In Hash::getList(int)...Out of bounds!"<<endl;
    exit(1);
  }
  return &array[i];
}
int Hash::Size() { return size; }

Node* Hash::Search(string k) {
  int index=hash(k);
  return (array[index].Search(k)); //List's Search() method, return NULL on fail
}

void Hash::Insert(Node* x) {
  int index=hash( (x->getData()).key );
  array[index].Insert(x); //List's Insert() method, inserts x at head of list
  size++;
}

void Hash::Print() {
  for (int i=0; i<SIZE; i++) {
    if (array[i].Empty()) //List's Empty() method
      cout<<"T["<<i<<"] is empty."<<endl;
    else {
      cout<<"T["<<i<<"]:"<<endl;
      array[i].Print(); //List's Print() method does endl's
    }
  }
}
