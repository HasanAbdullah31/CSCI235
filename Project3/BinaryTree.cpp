/* Hasan Abdullah: BinaryTree.cpp - implementation of class BinaryTree */

#include <iostream>
#include "BinaryTree.h"
using namespace std;

BinaryTree::BinaryTree() { root=NULL; }
BinaryTree::BinaryTree(Node* r) { root=r; }

Node* BinaryTree::getRoot() { return root; }

bool BinaryTree::isEmpty() {
  if (root==NULL)
    return true;
  else
    return false;
}

Node* BinaryTree::Min(Node* n) {
  while (n->getLeft()!=NULL)
    n=n->getLeft();
  return n;
}
Node* BinaryTree::Max(Node* n) {
  while (n->getRight()!=NULL)
    n=n->getRight();
  return n;
}
Node* BinaryTree::Successor(Node* n) {
  if (n->getRight()!=NULL)
    return Min(n->getRight());
  else {
    Node* successor=n->getParent();
    while (successor!=NULL && n==successor->getRight()) {
      n=successor;
      successor=successor->getParent();
    }
    return successor;
  }
}
Node* BinaryTree::Predecessor(Node* n) {
  if (n->getLeft()!=NULL)
    return Max(n->getLeft());
  else {
    Node* predecessor=n->getParent();
    while (predecessor!=NULL && n==predecessor->getLeft()) {
      n=predecessor;
      predecessor=predecessor->getParent();
    }
    return predecessor;
  }
}
Node* BinaryTree::Search(Node* n, string key) {
  if (n==NULL || key==n->getData().key) {
    return n;
  }
  else {
    if (key < n->getData().key)
      return Search(n->getLeft(),key);
    else
      return Search(n->getRight(),key);
  }
}

void BinaryTree::Insert(Node* z) {
  /* BINARY TREE PROPERTY: all nodes in left subtree have smaller keys, and
                           all nodes in right subtree have larger keys */
  Node* z_parent=new Node();
  Node* iterator=root;
  while (iterator!=NULL) {   //trace path to z's location, finding z_parent
    z_parent=iterator;
    if (z->getData().key < iterator->getData().key)
      iterator=iterator->getLeft();
    else   //i.e. z.key > iterator.key
      iterator=iterator->getRight();
  }
  z->setParent(z_parent);   //create a link upward from z to z_parent
  //now create a link downward from z_parent to z:
  if (z_parent==NULL) {
    root=z;
  }
  else {
    if (z->getData().key < z_parent->getData().key)
      z_parent->setLeft(z);
    else
      z_parent->setRight(z);
  }
}
Node* BinaryTree::Delete(Node* z) {   //returns z's replacement
  Node* replacement;
  if (z->getLeft()==NULL || z->getRight()==NULL)   //z has none or only 1 child
    replacement=z;
  else
    replacement=Successor(z);
  //reconstruct upward link b/w replacement's child and replacement's parent:
  Node* temp;
  if (replacement->getLeft()!=NULL)   //if replacement has a left child
    temp=replacement->getLeft();
  else
    temp=replacement->getRight();
  if (temp!=NULL)   //if z's successor (replacement) has a child, left or right
    temp->setParent( replacement->getParent() );
  //reconstruct downward link b/w replacement's parent and the children:
  if (replacement->getParent()==NULL)   //if replacement is the root
    root=temp;   //have replacement's child (temp) move up
  else if ( replacement==(replacement->getParent())->getLeft() ) //is left child
    (replacement->getParent())->setLeft(temp);
  else   //replacement is the right child
    (replacement->getParent())->setRight(temp);
  //copy replacement into z, i.e. deleting z
  if (replacement!=z)
    z->setData( replacement->getData() );
  return replacement;
}

void BinaryTree::InOrderWalk(Node* n) {
  if (n!=NULL) {
    InOrderWalk(n->getLeft());
    n->Print();
    InOrderWalk(n->getRight());
  }
}
void BinaryTree::PreOrderWalk(Node* n) {
  if (n!=NULL) {
    n->Print();
    PreOrderWalk(n->getLeft());
    PreOrderWalk(n->getRight());
  }
}
void BinaryTree::PostOrderWalk(Node* n) {
  if (n!=NULL) {
    PostOrderWalk(n->getLeft());
    PostOrderWalk(n->getRight());
    n->Print();
  }
}
