/* Hasan Abdullah: Node.h - header file for class Node */

#ifndef NODE_H
#define NODE_H

#include <string>
using namespace std;

struct Data {string key; string name; string book;};

class Node {
private:
 bool defaultConstructorCalled=false;
 Node* parent;
 Data data;
 Node* left;
 Node* right;
public:
 Node();
 Node(Data d);
 Node(Node* source);
 Node* getParent();
 Data getData();
 Node* getLeft();
 Node* getRight();
 void setParent(Node* p);
 void setData(Data d);
 void setLeft(Node* l);
 void setRight(Node* r);
 void Print();   //does endl after printing
 Node* operator=(Node* source);   //overload assignment operator
};

#endif /* NODE_H */
