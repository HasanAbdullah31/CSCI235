/* Hasan Abdullah: Queue.h - header file for Queue class */

#ifndef QUEUE_H
#define QUEUE_H

class Queue {
private:
 static const int MAXSIZE=8;
 int array[MAXSIZE];
 int size;
 int head;
 int tail;
public:
 Queue();
 Queue(int* source, int h, int n);   //h is the head and n is the size
 void Enqueue(int x);   //add element to tail
 int Dequeue();   //remove element from head
 int Size();
 int Head();
 int Tail();
 bool Empty();
 bool Full();
 void Print();
};

#endif /* QUEUE_H */
