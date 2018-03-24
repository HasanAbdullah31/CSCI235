/* Hasan Abdullah: driver.cpp - main program for Binary Tree project */

#include <iostream>
#include <fstream>
#include "Color.h"
#include "Date.h"
#include "Node.h"
#include "BinaryTree.h"
using namespace std;

const string file="books.txt";
const Color COL(F_RED), UND(UNDERLINE), RES(RESET);

BinaryTree readFile(string filename);   //also prints the Nodes for each line

int main(int argc, char **argv) {
  cout<<COL<<"Binary Tree T created from '"<<file<<"':"<<RES<<endl;
  BinaryTree T=readFile(file);   //side effect: prints the Nodes for each line
  Node* root=T.getRoot();
  cout<<COL<<"T printed with InOrderWalk(Root(T)):"<<RES<<endl;
  T.InOrderWalk(root);
  Date date=Date(T.Min(root)->getData().key);   //initialize to earliest date
  Node* temp; bool another=false; date-=3;   //go back 3 days
  for (int i=0; i<100; i++) {   //check due dates for the next 100 days
    temp=T.Search(root,(date+2).getDate());
    while (temp!=NULL) {   //i.e. a book(s) [hence the while] is due in 2 days
      if (!another) cout<<COL<<"Current date: "<<date<<RES<<endl;
      cout<<temp->getData().name<<", your book "<<UND<<temp->getData().book
	  <<RES<<" is due in 2 days ("<<temp->getData().key<<")!"<<endl;
      T.Delete(temp); root=T.getRoot(); //update root after deleting temp from T
      //there may be more books due on the same day (i.e. Nodes with same key)
      temp=T.Search(root,(date+2).getDate());   //check if there are any more
      if (temp!=NULL) another=true;
      else another=false;
    }
    date++;   //go to next day
  }
  //assert: T is empty
  if (T.isEmpty())
    cout<<COL<<"T is now empty."<<RES<<endl;
  return 0;
}

BinaryTree readFile(string filename) {
  BinaryTree myTree=BinaryTree();
  ifstream myFile;
  myFile.open(filename, ifstream::binary);
  if (myFile.fail()) {
    cout<<"Unable to open '"<<filename<<"'!"<<endl;
    exit(1);
  }
  Data data; Node* node;
  while (myFile.peek()!=EOF) {
    getline(myFile,data.key,'\t');
    getline(myFile,data.name,'\t');
    getline(myFile,data.book,'\n');
    node=new Node(data);
    node->Print();
    if (myTree.isEmpty()) {
      myTree=BinaryTree(node);
    }
    else {
      myTree.Insert(node);
    }
  }
  myFile.close();
  return myTree;
}
