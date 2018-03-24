/* Hasan Abdullah: Node.cpp - implementation of class Node */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "Node.h"
using namespace std;

Node::Node() {
  defaultConstructorCalled=true;
  Node* prev=(Node* )malloc(sizeof(Node));
  Node* next=(Node* )malloc(sizeof(Node));
}
Node::Node(Data d) {
  if (!defaultConstructorCalled)
    Node();
  data=d;
}

Node* Node::getPrev() { return prev; }
Data Node::getData()  { return data; }
Node* Node::getNext() { return next; }

void Node::setPrev(Node* p) { prev=p; }
void Node::setData(Data d)  { data=d; }
void Node::setNext(Node* n) { next=n; }

bool operator==(Node a, Node b) {
  if (a.data.key==b.data.key)
    return true;
  else
    return false;
}
bool operator!=(Node a, Node b) {
  return !(a==b);
}
bool operator>(Node a, Node b) {
  if (a.data.key>b.data.key)
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
  cout<<"Node.key=" <<left<<setw(10)<<setfill(' ')<<data.key
      <<"Node.name="<<left<<setw(10)<<setfill(' ')<<data.name
      <<"Node.ID="<<data.ID<<endl;
}
