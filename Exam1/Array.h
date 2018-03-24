/* Hasan Abdullah: Array.h - header+implement file for template class Array */

#ifndef ARRAY_H
#define ARRAY_H

#include <cassert>
using namespace std;

template<class ItemType>
class Array {
private:
 static const int MAXSIZE=15;
 ItemType array[MAXSIZE];
 int SIZE;
public:
 Array();
 Array(ItemType* source, int size);
 ItemType Get(int i);
 int Size();
 int Min(int start);
 void Swap(int index1, int index2);
 void Sort();
 void Print();
};

template<class ItemType>
Array<ItemType>::Array() {}

template<class ItemType>
Array<ItemType>::Array(ItemType* source, int size) {
  assert(size>0 && size<=MAXSIZE);
  SIZE=size;
  for (int i=0; i<SIZE; i++)
    array[i]=source[i];
}

template<class ItemType>
ItemType Array<ItemType>::Get(int i) {
  assert(i>=0 && i<SIZE);
  return array[i];
}

template<class ItemType>
int Array<ItemType>::Size() { return SIZE; }

template<class ItemType>
int Array<ItemType>::Min(int start) {
  ItemType min=array[start];
  int index;
  for (int i=start; i<SIZE; i++) {
    if (!(array[i]>min)) {   //same as: if (array[i]<=min)
      min=array[i];
      index=i;
    }
  }
  return index;
}

template<class ItemType>
void Array<ItemType>::Swap(int index1, int index2) {
  ItemType temp=array[index1];
  array[index1]=array[index2];
  array[index2]=temp;
}

template<class ItemType>
void Array<ItemType>::Sort() {
  int index;
  for (int j=0; j<SIZE; j++) {
    index=Min(j);
    Swap(j, index);
  }
}

template<class ItemType>
void Array<ItemType>::Print() {
  for (int i=0; i<SIZE; i++) {
    array[i].Print();   //Print() from <ItemType>, which would be Cat or Dog
  }
}

#endif /* ARRAY_H */
