/* Hasan Abdullah: List.h - header file for class List */

#ifndef LIST_H
#define LIST_H

#include "Node.h"

class List {
private:
 Node* sentinel;
 int size;
 void Swap(Node* a, Node* b);   //used in Sort(); a and b MUST be adjacent
public:
 List(int* array, int s);
 ~List();
 int Size();
 Node* Search(int k);   //if search fails, returns NULL
 void Insert(Node* x);   //inserts x b/w sentinel and old head (size++)
 int Delete(Node* x);   //deletes x from the list (size--); returns 0 on fail
 void Sort();   //bubble or insertion sort, given Swap()'s limitation
 bool Empty();
 void Print();
};

#endif /* LIST_H */
