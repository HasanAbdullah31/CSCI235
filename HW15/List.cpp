/* Hasan Abdullah: List.cpp - implementation of class List */

#include <iostream>
#include <cstdlib>
#include "List.h"
using namespace std;

List::List() {
  defaultConstructorCalled=true;
  size=0;
  sentinel=new Node();    //will be deleted in ~List(), to avoid memory leak
  if (sentinel==NULL) {   //new allocation failed
    cout<<"In List::List()...Out of heap memory!"<<endl;
    exit(1);
  }
  sentinel->setPrev(sentinel);
  sentinel->setNext(sentinel);
}
List::List(Data* array, int s) {
  if (!defaultConstructorCalled)
    List();
  Node* x;
  for (int i=0; i<s; i++) {   //size will be incremented by Insert()
    x=new Node(array[i]);   //will be deleted in ~List(), to avoid memory leak
    if (x==NULL) {   //new allocation failed
      cout<<"In List::List(Data*,int)...Out of heap memory!"<<endl;
      exit(1);
    }
    //the very first Node will become the tail of the list (look at e.g. below)
    Insert(x);   //will be in reverse; e.g. array={1,2,3,4}, list={4,3,2,1}
  } //assert: size==s
}

List::~List() {   //destructor to delete all new'd Nodes
  cout<<"In List::~List()...";
  Node* iterator=Head();   //start at head of list
  Node* temp;
  //traverse the list using the next of each Node
  while (iterator!=sentinel) {
    temp=iterator->getNext();   //hold next Node since iterator will be deleted
    delete iterator;
    iterator=temp;
  }
  delete sentinel; sentinel=NULL;   //free the sentinel
  cout<<"Heap memory freed."<<endl;
}

int List::Size() { return size; }
Node* List::Head() { return sentinel->getNext(); }

Node* List::Search(string k) {
  Node* iterator=Head();   //start at head of list
  //traverse the list using the next of each Node
  for ( ; iterator!=sentinel; iterator=iterator->getNext()) {
    if ( (iterator->getData()).key==k )
      return iterator;
  }
  //assert: there is no Node with key k in the list
  return NULL;   //returning NULL signals the not found error
}

void List::Insert(Node* x) {
  //if called when list is empty, x will be new head (circular link w/ sentinel)
  //if not, x will be inserted b/w sentinel and old head
  x->setNext(Head());     //x.next will be the old head
  (Head())->setPrev(x);   //old head's prev will be x
  sentinel->setNext(x);   //sentinel.next is now the new head (x)
  x->setPrev(sentinel);   //x is now the new head, b/c it's prev is sentinel
  size++;
}

bool List::Empty() {
  if (size==0)
    return true;
  else
    return false;
}

void List::Print() {
  if (Empty()) {
    cout<<"In List::Print()...The list is empty."<<endl;
    return;
  }
  Node* iterator=Head();   //start at head of list
  //traverse the list using the next of each Node
  for ( ; iterator!=sentinel; iterator=iterator->getNext()) {
    iterator->Print();   //Node's Print() does endl
  }
}
