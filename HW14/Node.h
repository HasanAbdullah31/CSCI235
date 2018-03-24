/* Hasan Abdullah: Node.h - header file for class Node */

#ifndef NODE_H
#define NODE_H

class Node {
private:
 Node* prev;
 int key;
 Node* next;
public:
 Node();
 Node(int k);
 Node* getPrev();
 int getKey();
 Node* getNext();
 void setPrev(Node* p);
 void setKey(int k);
 void setNext(Node* n);
 void Print();   //prints 'Node.key=<key goes here>', then does endl
 friend bool operator==(Node a, Node b);
 friend bool operator!=(Node a, Node b);
 friend bool operator>(Node a, Node b);
 friend bool operator>=(Node a, Node b);
 friend bool operator<(Node a, Node b);
 friend bool operator<=(Node a, Node b);
};

#endif /* NODE_H */
