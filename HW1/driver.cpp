/* Hasan Abdullah: driver.cpp - the user program */

#include "Bag.h"
#include "Bag.cpp"
using namespace std;

int main(int argc, char **argv) {
  /* Other ways to declare Bag:
     Bag<int> *myBag=new Bag<int>(10, myArray); myBag->PrintBag();
     Bag<int> myBag(10, myArray); myBag.PrintBag(); */

  int myArray1[10];
  Bag<int> myBag1=Bag<int>(10, myArray1);
  for (int i=0; i<10; i++)
    myBag1.Add(i,i);
  cout<<"In Bag of ints:"<<endl; myBag1.PrintBag();
  myBag1.Contains(3); myBag1.Remove(3); myBag1.PrintBag(); myBag1.Contains(3);
  
  float myArray2[10];
  Bag<float> myBag2=Bag<float>(10, myArray2);
  int ctr=0;
  for (float j=0.0; j<1.0; j+=0.1) {
    myBag2.Add(ctr,j); ctr++;
  }
  cout<<"In Bag of floats:"<<endl; myBag2.PrintBag();
  float* p2=myBag2.GetArray();
  for (int i=0; i<myBag2.GetSize(); i++)
    cout<<"*(p2+"<<i<<")="<<*(p2+i)<<endl;
  
  string myArray3[10];
  Bag<string> myBag3=Bag<string>(10, myArray3);
  myBag3.Add(0,"Abe"); myBag3.Add(1,"Bob"); myBag3.Add(2,"Cal");
  myBag3.Add(3,"Dan"); myBag3.Add(4,"Edd"); myBag3.Add(5,"Fay");
  myBag3.Add(6,"Gia"); myBag3.Add(7,"Hal"); myBag3.Add(8,"Ira");
  myBag3.Add(9,"Jan");
  cout<<"In Bag of strings:"<<endl; myBag3.PrintBag();
  myBag3.Clear(); myBag3.PrintBag(); myBag3.Frequency("");
  
  return 0;
}
