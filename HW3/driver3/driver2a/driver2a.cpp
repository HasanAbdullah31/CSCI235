/* Hasan Abdullah: driver2a.cpp - a simple user program */

#include "Array.h"   //includes necessary libraries and function prototypes
#include "Array.cpp"   //defines the functions

int main(int argc, char **argv) {
  const int SIZE=11;
  int array[SIZE]={10,4,8,2,10,15,3,8,15,8,2};
  Print(array, SIZE);
  Sort(array, SIZE);
  Print(array, SIZE);
  return 0;
}
