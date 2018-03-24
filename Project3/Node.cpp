/* Hasan Abdullah: Node.cpp - implementation of class Node */

#include <iostream>
#include <cstdlib>
#include "Node.h"
using namespace std;

Node::Node() {
  defaultConstructorCalled=true;
  Node* parent=(Node* )malloc(sizeof(Node)); parent=NULL;
  Node* left=(Node* )malloc(sizeof(Node)); left=NULL;
  Node* right=(Node* )malloc(sizeof(Node)); right=NULL;
}
Node::Node(Data d) {
  if (!defaultConstructorCalled)
    Node();
  data=d;
}
Node::Node(Node* source) {
  if (!defaultConstructorCalled)
    Node();
  parent=source->getParent();
  left=source->getLeft();
  right=source->getRight();
  data=source->getData();
}

Node* Node::getParent() { return parent; }
Data  Node::getData()   { return data;   }
Node* Node::getLeft()   { return left;   }
Node* Node::getRight()  { return right;  }

void Node::setParent(Node* p) { parent=p; }
void Node::setData(Data d)    { data=d;   }
void Node::setLeft(Node* l)   { left=l;   }
void Node::setRight(Node* r)  { right=r;  }

Node* Node::operator=(Node* source) {
  Node* copy=new Node(source);
  return copy;
}

void Node::Print() {
  cout<<"Due Date: "<<data.key<<"  ";
  cout<<"Name: "<<data.name;
  for (int i=data.name.size(); i<15; i++)
    cout<<" ";   //i.e. setw(15) and setfill(' ')
  cout<<"  Book: "<<data.book<<endl;
}
