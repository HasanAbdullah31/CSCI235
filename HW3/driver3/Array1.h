/* Hasan Abdullah: Array1.h - header+implement file for template class Array1 */

#ifndef ARRAY1_H
#define ARRAY1_H

#include <iostream>
#include <cassert>
using namespace std;

template<class ItemType>
class Array1 {
private:
 static const int SIZE=5;
 ItemType array[SIZE];
public:
 Array1();
 Array1(ItemType* source);
 ItemType Get(int i);
 int Size();
 int Min(int start);
 void Swap(int index1, int index2);
 void Sort();
 void Print();
};

template<class ItemType>
Array1<ItemType>::Array1() {}

template<class ItemType>
Array1<ItemType>::Array1(ItemType* source) {
  for (int i=0; i<SIZE; i++)
    array[i]=source[i];
}

template<class ItemType>
ItemType Array1<ItemType>::Get(int i) {
  assert(i>=0 && i<SIZE);
  return array[i];
}

template<class ItemType>
int Array1<ItemType>::Size() { return SIZE; }

template<class ItemType>
int Array1<ItemType>::Min(int start) {
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
void Array1<ItemType>::Swap(int index1, int index2) {
  ItemType temp=array[index1];
  array[index1]=array[index2];
  array[index2]=temp;
}

template<class ItemType>
void Array1<ItemType>::Sort() {
  int index;
  for (int j=0; j<SIZE; j++) {
    index=Min(j);
    Swap(j, index);
  }
}

template<class ItemType>
void Array1<ItemType>::Print() {
  for (int i=0; i<SIZE; i++) {
    array[i].Print();   //Print() from <ItemType>, which would be Card
    if (i<SIZE-1) cout<<", ";
    else cout<<".";
  }
  cout<<endl;
}

#endif /* ARRAY1_H */
