/* Hasan Abdullah: driver.cpp - main program for Hash Table project */

#include <iostream>
#include "Hash.h"
using namespace std;

const string filename="names.txt";

int main(int argc, char **argv) {
  Hash hashTable=Hash(filename);
  cout<<"Hash Table T:"<<endl<<"size="<<hashTable.Size()<<endl;
  hashTable.Print(); cout<<endl;
  string last_name[3]={"Doe","John","Smith"};
  string first_name[3]={"Alexander","Chris","Jane"};
  Node* temp; Node* sentinel; List* list; bool inList;
  //The following checks all combinations of last_name, first_name in the table:
  for (int i=0; i<3; i++) {   //for each last_name
    temp=hashTable.Search(last_name[i]);
    if (temp==NULL)
      cout<<"The surname "<<last_name[i]<<" is not in the table."<<endl;
    else { //assert: there is at least 1 Node with key=last_name[i] in the table
      list=hashTable.getList( hashTable.indexOf(last_name[i]) );
      sentinel=(list->Head())->getPrev();
      for (int j=0; j<3; j++) {   //for each first_name
        inList=false;
        temp=list->Head();   //start at head, traverse with next pointers
        while (temp!=sentinel) {
	  if ( (temp->getData()).name==first_name[j] ) {
	    inList=true; break;
	  }
	  temp=temp->getNext();
	}
	if (inList)
	  cout<<last_name[i]<<", "<<first_name[j]<<" is in the list."<<endl;
	else
	  cout<<last_name[i]<<", "<<first_name[j]<<" isn't in the list."<<endl;
      }
    }
  }
  cout<<endl;
  return 0;
}
