/* Hasan Abdullah: driver.cpp - main program for Linked List project */

#include <iostream>
#include "Color.h"
#include "List.h"
using namespace std;

const Color C1(F_PURPLE), C2(F_CYAN), RES(RESET);

int main(int argc, char **argv) {
  int size=5;
  int source[size]={13,4,6,9,13};
  List list=List(source,size);
  cout<<C1<<"Original list:"<<RES<<endl;
  size=list.Size(); cout<<C2<<"size="<<size<<RES<<endl;
  list.Print();
  cout<<C1<<"Sorted list:"<<RES<<endl;
  size=list.Size(); cout<<C2<<"size="<<size<<RES<<endl;
  list.Sort();
  list.Print();
  Node* temp;
  for (int i=0; i<15; i++) {
    temp=list.Search(i);
    while (temp!=NULL) {   //while to delete all Nodes with key i
      cout<<C1<<"List with Node.key="<<i<<" removed from the list:"<<RES<<endl;
      list.Delete(temp); size=list.Size(); cout<<C2<<"size="<<size<<RES<<endl;
      list.Print();
      temp=list.Search(i);   //check if there's another Node with key i
    }
  }
  return 0;
}
