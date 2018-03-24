/* Hasan Abdullah: Node.h - header file for class Node */

#ifndef NODE_H
#define NODE_H

#include <string>
using namespace std;

struct Data {string key; string name; string ID;};

class Node {
private:
 bool defaultConstructorCalled=false;
 Node* prev;
 Data data;
 Node* next;
public:
 Node();
 Node(Data d);
 Node* getPrev();
 Data getData();
 Node* getNext();
 void setPrev(Node* p);
 void setData(Data d);
 void setNext(Node* n);
 void Print();   //does endl after printing
 friend bool operator==(Node a, Node b);
 friend bool operator!=(Node a, Node b);
 friend bool operator>(Node a, Node b);
 friend bool operator>=(Node a, Node b);
 friend bool operator<(Node a, Node b);
 friend bool operator<=(Node a, Node b);
};

#endif /* NODE_H */
