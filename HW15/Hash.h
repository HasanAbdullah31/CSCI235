/* Hasan Abdullah: Hash.h - header file for class Hash */

#ifndef HASH_H
#define HASH_H

#include "Node.h"
#include "List.h"

class Hash {
private:
  int hash(string k);
 /* Our hash function, h(k), will use the division method (i.e. h(k)=k%SIZE).
    Bad values of SIZE are: powers of 2, powers of 10, and any <power of 2>-1
    (last applies for string keys interpreted in radix <some power of 2>). */
 static const int SIZE=5;   //good b/c it does not match the above criteria
 List array[SIZE];   //an array of Lists (i.e. Hash with chaining)
 int size=0;   //total number of Nodes (i.e. size+=<# of Nodes from each List>)
public:
 Hash();
 Hash(string filename);
 Hash(Node* input[], int s);
 int indexOf(string k);   //returns hash(k)
 List* getList(int i);
 int Size();
 Node* Search(string k);   //if search fails, returns NULL
 void Insert(Node* x);   //inserts x into the appropriate list in array (size++)
 void Print();   //does endl after printing
};

#endif /* HASH_H */
