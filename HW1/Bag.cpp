/* Hasan Abdullah: Bag.cpp - the implementation file for the template class */

#include "Bag.h"

template<class ItemType>
Bag<ItemType>::Bag() {
  size=10;   //compiler automatically assigns the elements of the array
}

template<class ItemType>
Bag<ItemType>::Bag(int n, ItemType* source) {
  size=0;
  assert(n<=10 && n>=0);
  for (int i=0; i<n; i++) {
    array[i]=source[i];
    size++;
  }
}

template<class ItemType>
ItemType* Bag<ItemType>::GetArray() {
  return array;   //returns address of the array
}

template<class ItemType>
void Bag<ItemType>::PrintBag() {
  for (int i=0; i<size; i++)
    cout<<"array["<<i<<"]="<<array[i]<<endl;
}

template<class ItemType>
int Bag<ItemType>::GetSize() {
  return size;
}

template<class ItemType>
bool Bag<ItemType>::Empty() {
  if (size==0)
    return true;
  else
    return false;
}

template<class ItemType>
void Bag<ItemType>::Add(int n, ItemType newItem) {
  assert(n<size && n>=0);
  array[n]=newItem;
}

template<class ItemType>
void Bag<ItemType>::Remove(ItemType oldItem) {
  //I assumed oldItem either appears once or doesn't appear at all
  int ctr=0; int index;
  for (int i=0; i<size; i++) {
    if (array[i]==oldItem) {
      ctr++; index=i;
    }
  }
  if (ctr==0)
    cout<<oldItem<<" not found in array."<<endl;
  else {   //ctr==1
    if (index==size-1) {   //oldItem is the last element in the array
      size-=1;   //"remove" item by reducing array size by 1
      cout<<oldItem<<" has been removed from the array."<<endl;
    }
    else {   //oldItem is NOT the last element in the array
      for (int j=index; j<size-1; j++)
        array[j]=array[j+1];
      size-=1;
      cout<<oldItem<<" has been removed from the array."<<endl;
    }
  }
}

template<class ItemType>
void Bag<ItemType>::Clear() {
  ItemType defaultValue;
  for (int i=0; i<size; i++)
    array[i]=defaultValue;
  cout<<"The bag has been cleared."<<endl;
}

template<class ItemType>
int Bag<ItemType>::Frequency(ItemType item) {
  int ctr=0;
  for (int i=0; i<size; i++)
    if (array[i]==item)
      ctr++;
  cout<<"The frequency of "<<item<<" in the array is "<<ctr<<"."<<endl;
  return ctr;
}

template<class ItemType>
bool Bag<ItemType>::Contains(ItemType item) {
  for (int i=0; i<size; i++) {
    if (array[i]==item) {
      cout<<"The array contains "<<item<<"."<<endl;
      return true;
    }
  }
  cout<<"The array does not contain "<<item<<"."<<endl;
  return false;
}
