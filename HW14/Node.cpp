/* Hasan Abdullah: Node.cpp - implementation of class Node */

#include <iostream>
#include <cstdlib>
#include "Node.h"
using namespace std;

Node::Node() {
  Node* prev=(Node* )malloc(sizeof(Node));
  Node* next=(Node* )malloc(sizeof(Node));
}
Node::Node(int k) {
  Node* prev=(Node* )malloc(sizeof(Node));
  key=k;
  Node* next=(Node* )malloc(sizeof(Node));
}

Node* Node::getPrev() { return prev; }
int Node::getKey()    { return key;  }
Node* Node::getNext() { return next; }

void Node::setPrev(Node* p) { prev=p; }
void Node::setKey(int k)    { key=k;  }
void Node::setNext(Node* n) { next=n; }

bool operator==(Node a, Node b) {
  if (a.key==b.key)
    return true;
  else
    return false;
}
bool operator!=(Node a, Node b) {
  return !(a==b);
}
bool operator>(Node a, Node b) {
  if (a.key>b.key)
    return true;
  else
    return false;
}
bool operator>=(Node a, Node b) {
  return (a>b || a==b);
}
bool operator<(Node a, Node b) {
  return !(a>=b);
}
bool operator<=(Node a, Node b) {
  return (a<b || a==b);
}

void Node::Print() {
  cout<<"Node.key="<<key<<endl;
}
