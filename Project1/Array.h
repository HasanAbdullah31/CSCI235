/* Hasan Abdullah: Array.h - header file for template class Array */

#ifndef ARRAY_H
#define ARRAY_H

#include "RecordLimits.h"   //for MAXSIZE and SortType

template<class ItemType>
class Array {
private:
 ItemType array[MAXSIZE];
 int SIZE;
 void Merge(int indLow, int indMid, int indHigh);   //helper for MergeSort
public:
 Array();
 Array(ItemType* source, int size);
 ItemType Get(int i);
 int Size();
 void Set(int i, ItemType newItem);
 void Insert(ItemType newItem);
 void Set_Size(int newSize);
 int Min(int start);
 void Swap(int index1, int index2);
 void SelectionSort();
 void MergeSort(int indLow, int indHigh);
 void Sort(SortType t);
 void Print();
};

#endif /* ARRAY_H */
