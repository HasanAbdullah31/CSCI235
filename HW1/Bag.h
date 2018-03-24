/* Hasan Abdullah: Bag.h - the header file for the template class declaration */

#ifndef BAG_H
#define BAG_H

#include <iostream>
#include <cassert>
using namespace std;

template<class ItemType>
class Bag {
private:
 ItemType array[10];
 int size;
public:
 Bag();
 Bag(int n, ItemType* source);
 ItemType* GetArray();
 void PrintBag();
 int GetSize();
 bool Empty();
 void Add(int n, ItemType newItem);
 void Remove(ItemType oldItem);
 void Clear();
 int Frequency(ItemType item);
 bool Contains(ItemType item);
};

#endif /* BAG_H */
