/* Hasan Abdullah: Array.cpp - implementation file with function definitions */

#include "Array.h"   //includes necessary libraries

int Min(int* a, int n, int start) {
  int min=a[start];
  int index;
  for (int i=start; i<n; i++) {
    if (a[i]<=min) {
      min=a[i];
      index=i;
    }
  }
  return index;
}

void Swap(int* a, int index1, int index2) {
  int temp=a[index1];
  a[index1]=a[index2];
  a[index2]=temp;
}

void Sort(int* a, int n) {
  int index;
  for (int j=0; j<n; j++) {
    index=Min(a, n, j);
    Swap(a, j, index);
  }
}

void Print(int* a, int n) {
  for (int i=0; i<n; i++)
    cout<<left<<setw(5)<<setfill(' ')<<a[i];
  cout<<endl;
}
