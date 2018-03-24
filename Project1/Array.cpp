/* Hasan Abdullah: Array.cpp - implementation of template class Array */

#include <iostream>
#include <cassert>
#include "RecordLimits.h"   //for MAXSIZE and SortType
#include "Array.h"
using namespace std;

template<class ItemType>
Array<ItemType>::Array() { SIZE=0; }

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
void Array<ItemType>::Set(int i, ItemType newItem) {
  assert(i>=0 && i<SIZE);
  array[i]=newItem;
}

template<class ItemType>
void Array<ItemType>::Insert(ItemType newItem) { //like vector's push_back
  assert(SIZE!=MAXSIZE);
  SIZE++;
  array[SIZE-1]=newItem;
}

template<class ItemType>
void Array<ItemType>::Set_Size(int newSize) {
  assert(newSize>0 && newSize<=MAXSIZE);
  SIZE=newSize;
}

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
void Array<ItemType>::SelectionSort() {
  int index;
  for (int j=0; j<SIZE; j++) {
    index=Min(j);
    Swap(j,index);
  }
}

template<class ItemType>
void Array<ItemType>::Merge(int indLow, int indMid, int indHigh) {
  ItemType A[indHigh-indLow+1];   //holds the sorted pile
  int i=0;        //running index for A[SIZE]
  int j=indLow;   //running index for 1st half array
  int k=indMid+1; //running index for 2nd half array
  while (j<=indMid && k<=indHigh) {   //both halves are not empty
    if (array[j]<=array[k]) {   //1st half wins (j wins)
      A[i]=array[j];
      i++; j++;
    }
    else {   //2nd half wins (k wins)
      A[i]=array[k];
      i++; k++;
    }
  }
  //assert: next 2 while loops occur if either half (or both) is empty
  while (j<=indMid) {   //1st half of array is not empty
    A[i]=array[j];
    i++; j++;
  }
  while (k<=indHigh) {   //2nd half of array is not empty
    A[i]=array[k];
    i++; k++;
  }
  for (int i=indLow; i<=indHigh; i++)
    array[i]=A[i-indLow];   //original array (array) <- sorted array (A)
}

template<class ItemType>
void Array<ItemType>::MergeSort(int indLow, int indHigh) {
  assert(indLow>=0 && indHigh<SIZE);
  if (indLow<indHigh) {
    int indMid=(int)((indLow+indHigh)/2); //the floor of (indLow+indHigh)/2
    MergeSort(indLow,indMid);     //merge sort 1st half
    MergeSort(indMid+1,indHigh);  //merge sort 2nd half
    Merge(indLow,indMid,indHigh); //merge both halves
  }
}

template<class ItemType>
void Array<ItemType>::Sort(SortType t) {
  if (t==SortType::Selection)
    SelectionSort();
  else //if (t==SortType::Merge)
    MergeSort(0,SIZE-1);
}

template<class ItemType>
void Array<ItemType>::Print() {
  for (int i=0; i<SIZE; i++) {
    array[i].Print();   //Print() from <ItemType>, which would be Book
    cout<<endl;
  }
}
