/* Hasan Abdullah: List.h - header file for class List */

#ifndef LIST_H
#define LIST_H

#include "Node.h"

class List {
private:
 bool defaultConstructorCalled=false;
 Node* sentinel;
 int size;
public:
 List();
 List(Data* array, int s);
 ~List();
 int Size();
 Node* Head();
 Node* Search(string k);   //if search fails, returns NULL
 void Insert(Node* x);   //inserts x b/w sentinel and old head (size++)
 bool Empty();
 void Print();   //does endl after printing
};

#endif /* LIST_H */
