/* Hasan Abdullah: BinaryTree.h - header file for class BinaryTree */

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "Node.h"

class BinaryTree {
private:
 Node* root;
public:
 BinaryTree();
 BinaryTree(Node* r);
 Node* getRoot();
 bool isEmpty();
 Node* Min(Node* n);
 Node* Max(Node* n);
 Node* Successor(Node* n);
 Node* Predecessor(Node* n);
 Node* Search(Node* n, string key);
 void Insert(Node* z);
 Node* Delete(Node* z);   //returns z's replacement
 void InOrderWalk(Node* n);   //prints the Nodes between left and right childs
 void PreOrderWalk(Node* n);  //prints the Nodes before descendants
 void PostOrderWalk(Node* n); //prints the Nodes after descendants
};

#endif /* BINARY_TREE_H */
