/* Hasan Abdullah: driver.cpp - main program for Queue project */

#include <iostream>
#include "Color.h"
#include "Queue.h"
using namespace std;

const Color c1(F_RED), c2(F_BLUE), reset(RESET);

int main(int argc, char **argv) {
  int size=5, head=7, tail;
  int array[size]={15,6,9,8,4};
  Queue Q=Queue(array,head,size);
  
  cout<<c1<<"The original queue:"<<reset<<endl;
  size=Q.Size(); head=Q.Head(); tail=Q.Tail();
  cout<<c2<<"size="<<size<<"; head="<<head<<"; tail="<<tail<<";"<<endl;
  Q.Print(); cout<<reset<<endl;
  
  char e_d;   //e for enqueue, d for dequeue
  int element;   //user chooses element to enqueue
  while (true) {   //user can quit by using terminal command (e.g. C-c C-c)
    cout<<"Enter e to enqueue or d to dequeue:"<<endl;
    cin>>e_d;
    while (e_d!='e' && e_d!='d' || cin.fail()) {
      cout<<"Invalid input! Enter e to enqueue or d to dequeue:"<<endl;
      cin.clear();
      cin.ignore(99,'\n');
      cin>>e_d;
    }
    //assert: e_d is either 'e' or 'd'
    switch (e_d) {
      case 'e':
        cout<<c1<<"Enter the element you want to enqueue:"<<reset<<endl;
        cin>>element;   //assume user inputs an int
        Q.Enqueue(element); size=Q.Size(); head=Q.Head(); tail=Q.Tail();
        cout<<c2<<"size="<<size<<"; head="<<head<<"; tail="<<tail<<";"<<endl;
        Q.Print(); cout<<reset<<endl;
        break;
      case 'd':
        cout<<c1<<"The queue will be dequeued."<<reset<<endl;
        Q.Dequeue(); size=Q.Size(); head=Q.Head(); tail=Q.Tail();
        cout<<c2<<"size="<<size<<"; head="<<head<<"; tail="<<tail<<";"<<endl;
        Q.Print(); cout<<reset<<endl;
        break;
    }
  }
  return 0;
}
