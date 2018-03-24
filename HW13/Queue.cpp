/* Hasan Abdullah: Queue.cpp - implementation of Queue class */

#include <iostream>
#include "Queue.h"
using namespace std;

Queue::Queue() { size=0; }

Queue::Queue(int* source, int h, int n) {   //assume proper inputs
  size=0;   //increment in for loop
  head=h;
  tail=head;   //start with empty queue at position head
  for (int i=0; i<n; i++)
    Enqueue(source[i]); //takes care of wrap arounds in the array (also size++)
}

void Queue::Enqueue(int x) {
  if (Full()) {
    cout<<"In void Queue::Enqueue(int)..."<<endl
	<<"Error: Overflow! The queue is full."<<endl;
    return;
  }
  array[tail]=x;   //tail points to the element after last element
  if (tail==MAXSIZE-1)
    tail=0;   //wrap around
  else
    tail++;
  size++;
}

int Queue::Dequeue() {
  if (Empty()) {
    cout<<"In int Queue::Dequeue()..."<<endl
	<<"Error: Underflow! The queue is empty."<<endl;
    return -1;
  }
  int removed=array[head];
  //since current head will be removed, adjust head accordingly
  if (head==MAXSIZE-1)
    head=0;   //wrap around
  else
    head++;
  size--;   //"removes" first element in array
  return removed;
}

int Queue::Size() { return size; }

int Queue::Head() { return head; }

int Queue::Tail() { return tail; }

bool Queue::Empty() {
  if (size==0)
    return true;
  else
    return false;
}

bool Queue::Full() {
  if (size==MAXSIZE)
    return true;
  else
    return false;
}

void Queue::Print() {
  int width_full=0;
  for (int i=head; i<head+size; i++) {
    if (width_full==4) cout<<endl;
    if (i<MAXSIZE)
      cout<<"array["<<i<<"]="<<array[i]<<"; ";
    else
      cout<<"array["<<i%MAXSIZE<<"]="<<array[i%MAXSIZE]<<"; ";   //wrap around
    width_full++;
  }
  cout<<endl;
}
