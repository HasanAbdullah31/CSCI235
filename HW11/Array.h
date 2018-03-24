/* Hasan Abdullah: Array.h - header+implement file for template class Array */

#ifndef ARRAY_H
#define ARRAY_H

#include <cassert>
using namespace std;

template<typename ItemType>
class Array {
private:
 static const int MAXSIZE=20;
 ItemType array[MAXSIZE];
 int SIZE;
 void Heapify(int i);
 void Swap(ItemType &a, ItemType &b);
 int Parent(int i);   //returns index of the parent of index i
public:
 Array();
 Array(ItemType* source, int size);
 ItemType Get(int i);
 int Size();
 void HeapSort();
 void Print();
 /* Priority Queue Operations: */
 void Insert(ItemType x);   //inserts x into the array
 void IncreaseKey(int i, ItemType k);   //increases array[i] to k; k>=array[i]
 ItemType Maximum();   //returns largest keyed element in array
 ItemType ExtractMax(); /* returns largest keyed element in array and removes
                           it from array, heapifying the remainder of array */
};

template<typename ItemType>
Array<ItemType>::Array() {}

template<typename ItemType>
Array<ItemType>::Array(ItemType* source, int size) {
  assert(size>0 && size<=MAXSIZE);
  SIZE=size;
  for (int i=0; i<SIZE; i++)
    array[i]=source[i];
}

template<typename ItemType>
ItemType Array<ItemType>::Get(int i) {
  assert(i>=0 && i<SIZE);
  return array[i];
}

template<typename ItemType>
int Array<ItemType>::Size() { return SIZE; }

template<typename ItemType>
void Array<ItemType>::Print() {
  for (int i=0; i<SIZE; i++) {
    array[i].Print();   //Print() from <ItemType>, which would be Cat or Dog
  }
}

template<typename ItemType>
void Array<ItemType>::Swap(ItemType &a, ItemType &b) {
  ItemType temp=a; a=b; b=temp;
}

template<typename ItemType>
void Array<ItemType>::Heapify(int i) {
  int leftIndex=2*i+1;   //left child
  int rightIndex=2*i+2;   //right child
  int maxIndex; //index of highest value (nodes:parent,left child,right child)
  if (leftIndex<SIZE && array[leftIndex]>array[i])
    maxIndex=leftIndex;
  else
    maxIndex=i;
  if (rightIndex<SIZE && array[rightIndex]>array[maxIndex])
    maxIndex=rightIndex;
  //assert: maxIndex contains index of highest value of the 3 nodes
  if (maxIndex!=i) {
    Swap(array[i],array[maxIndex]);
    Heapify(maxIndex);
  }
}

template<typename ItemType>
void Array<ItemType>::HeapSort() {
  for (int i=SIZE/2; i>=0; i--) //build the heap; SIZE/2=parent of last element
    Heapify(i);
  int original_size=SIZE; //the following loop will SIZE-- to create subarrays
  ItemType max;   //max will hold the j'th largest element in the array
  for (int j=SIZE-1; j>=1; j--) {
    max=ExtractMax();   //side effect: SIZE--
    array[j]=max;   //sort the array from last element (max) to first (min)
  }
  SIZE=original_size;   //now that array is sorted, restore original size
}

template<typename ItemType>
int Array<ItemType>::Parent(int i) {
  return (i-1)/2;   //since the heap is a binary tree; i-1 because root is 0
}

template<typename ItemType>
void Array<ItemType>::IncreaseKey(int i, ItemType k) {
  //k=new data; increases array[i] to k; propagate heap property upwards
  assert(k>=array[i] && "ERROR: New data is smaller");   //k can't be < array[i]
  array[i]=k;
  while (i>1 && array[Parent(i)]<array[i]) {
    Swap(array[i],array[Parent(i)]);
    i=Parent(i);
  }
}

template<typename ItemType>
void Array<ItemType>::Insert(ItemType x) {
  assert(SIZE<MAXSIZE);
  /* increase size of heap by 1; in enlarged heap, insert new key in last
     position, calling IncreaseKey() to propagate heap property */
  SIZE++;
  array[SIZE-1]=x;   //array[SIZE-1] is now the last element since we did SIZE++
  IncreaseKey(SIZE-1,x);
}

template<typename ItemType>
ItemType Array<ItemType>::Maximum() {
  return array[0];   //the maximum is the root of the heap
}

template<typename ItemType>
ItemType Array<ItemType>::ExtractMax() {
  assert(SIZE>=1 && "ERROR: UNDERFLOW");   //if SIZE<1, ERROR "UNDERFLOW"
  ItemType max=Maximum();   //save root of the heap (array[0]) in max
  array[0]=array[SIZE-1];   //replace root with last element
  SIZE--;   //since root "removed," decrease size of heap by 1
  Heapify(0);   //restore heap property (i.e. all parents greater than childs)
  return max;
}

#endif /* ARRAY_H */
