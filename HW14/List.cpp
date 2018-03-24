/* Hasan Abdullah: List.cpp - implementation of class List */

#include <iostream>
#include <cstdlib>
#include "List.h"
using namespace std;

List::List(int* array, int s) {
  sentinel=new Node();    //will be deleted in ~List(), to avoid memory leak
  if (sentinel==NULL) {   //new allocation failed
    cout<<"In List::List(int*,int)... Out of heap memory!"<<endl;
    exit(1);
  }
  sentinel->setPrev(sentinel);
  sentinel->setNext(sentinel);
  Node* x;
  size=0;   //will be incremented by Insert()
  for (int i=0; i<s; i++) {
    x=new Node(array[i]);   //will be deleted in ~List(), to avoid memory leak
    if (x==NULL) {   //new allocation failed
      cout<<"In List::List(int*,int)... Out of heap memory!"<<endl;
      exit(1);
    }
    //the very first Node will become the tail of the list (look at e.g. below)
    Insert(x);   //will be in reverse; e.g. array={1,2,3,4}, list={4,3,2,1}
  } //assert: size==s
}

List::~List() {   //destructor to delete all new'd Nodes
  cout<<"In List::~List()... Attempting to free heap memory..."<<endl;
  Node* iterator=sentinel->getNext();   //start at head of list
  Node* temp;
  //traverse the list using the next of each Node
  while (iterator!=sentinel) {
    temp=iterator->getNext();   //hold next Node since iterator will be deleted
    delete iterator;
    iterator=temp;
  }
  delete sentinel; sentinel=NULL;   //free the sentinel
  cout<<"Heap memory freed successfully!"<<endl;
}

int List::Size() { return size; }

Node* List::Search(int k) {
  Node* iterator=sentinel->getNext();   //start at head of list
  //traverse the list using the next of each Node
  for ( ; iterator!=sentinel; iterator=iterator->getNext()) {
    if (iterator->getKey()==k)
      return iterator;
  }
  //assert: there is no Node with key k in the list
  return NULL;   //returning NULL signals the not found error
}

void List::Insert(Node* x) {
  //if called when list is empty, x will be new head (circular link w/ sentinel)
  //if not, x will be inserted b/w sentinel and old head
  x->setNext(sentinel->getNext());     //x.next will be the old head
  (sentinel->getNext())->setPrev(x);   //old head's prev will be x
  sentinel->setNext(x);   //sentinel.next is now the new head (x)
  x->setPrev(sentinel);   //x is now the new head, b/c it's prev is sentinel
  size++;
}

int List::Delete(Node* x) {     //return 0 on fail, 1 on success
  if (x==sentinel || x==NULL)   //not allowed to delete sentinel or NULL
    return 0;   //fail
  if (Empty()) {
    cout<<"In List::Delete(Node*)..."<<endl;
    cout<<"Error: Underflow! Can't delete a Node when the list is empty!"<<endl;
    return 0;   //fail
  }
  //assert: list has 1 or more non-sentinel Nodes (i.e. size>=1)
  if (size==1) {   //i.e. x is the one and only non-sentinel Node
    sentinel->setPrev(sentinel);
    sentinel->setNext(sentinel);
  }
  //assert: size>=2 (i.e. list has 2 or more non-sentinel Nodes)
  else if (x->getPrev()==sentinel) {     //if x is the head Node
    sentinel->setNext(x->getNext());     //sentinel.next will be x.next
    (x->getNext())->setPrev(sentinel);   //(x.next).prev will be sentinel
  }
  else if (x->getNext()==sentinel) {     //if x is the tail Node
    sentinel->setPrev(x->getPrev());     //sentinel.prev will be x.prev
    (x->getPrev())->setNext(sentinel);   //(x.prev).next will be sentinel
  }
  //assert: size>=3 (i.e. list has 3 or more non-sentinel Nodes)
  else {   //x is neither the head nor the tail
    (x->getPrev())->setNext(x->getNext());   //x.next will be x.prev's next
    (x->getNext())->setPrev(x->getPrev());   //x.prev will be x.next's prev
  }
  size--;
  return 1;   //success
}

void List::Swap(Node* a, Node* b) {   //a and b are adjacent; a comes before b
  if (a==b || a==sentinel || b==sentinel || a==NULL || b==NULL)
    return;
  (a->getPrev())->setNext(b);   //a.prev's next will be b
  b->setPrev(a->getPrev());     //b.prev will be a.prev
  (b->getNext())->setPrev(a);   //b.next's prev will be a
  a->setNext(b->getNext());     //a.next will be b.next
  b->setNext(a);   //b.next will be a
  a->setPrev(b);   //a.prev will be b
}

void List::Sort() {   //bubble sort
  Node* iterator;
  for (int i=1; i<=size-1; i++) {     //# of sublists to sweep = size-1
    iterator=sentinel->getNext();     //start at head of list for each sublist
    for (int j=1; j<=size-i; j++) {   //sublist sizes: size-1,size-2,...,1
      //dereference the pointers to compare the Nodes they're pointing to
      if ( *(iterator) >= *(iterator->getNext()) )
        Swap(iterator,iterator->getNext());
      //the swap makes iterator next Node, so don't do iterator=iterator.next
      else   //no swap, so do iterator=iterator.next
	iterator=iterator->getNext();
    }
  }
}

bool List::Empty() {
  if (size==0)
    return true;
  else
    return false;
}

void List::Print() {
  if (Empty()) {
    cout<<"In List::Print()... The list is empty."<<endl;
    return;
  }
  Node* iterator=sentinel->getNext();   //start at head of list
  //traverse the list using the next of each Node
  for ( ; iterator!=sentinel; iterator=iterator->getNext()) {
    iterator->Print();   //Node's Print() does endl
  }
}
