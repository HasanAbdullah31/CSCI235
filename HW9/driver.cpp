/* Hasan Abdullah: driver.cpp - recursive selection sort and shell sort */

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

static int GAP;   //used in ShellSort function

void RecursiveSelectionSort(int arr[], int size);
void ShellSort(int arr[], int size);
void Print(int arr[], int size);

int main(int argc, char **argv) {
  if (argc!=2) {
    cout<<"Need 2 arguments!"<<endl;
    exit(1);
  }
  GAP=atoi(argv[1]);
  const int SIZE=10;
  int arr[SIZE];
  srand(time(0));
  
  for (int i=0; i<SIZE; i++)
    arr[i]=rand()%20;
  cout<<"Array A:"<<endl;
  Print(arr,SIZE);
  cout<<"Sorted A using recursive selection sort:"<<endl;
  RecursiveSelectionSort(arr,SIZE);
  Print(arr,SIZE);
  
  cout<<endl;
  
  for (int j=0; j<SIZE; j++)
    arr[j]=SIZE-1-j;
  cout<<"Array B:"<<endl;
  Print(arr,SIZE);
  cout<<"Sorted B using shell sort:"<<endl;
  ShellSort(arr,SIZE);
  Print(arr,SIZE);
  
  return 0;
}

void RecursiveSelectionSort(int arr[], int size) {
  int maxIndex=0;
  for (int index=0; index<size; index++) {
    if (arr[index]>arr[maxIndex]) {
      maxIndex=index;
    }
  }
  //assert: maxIndex holds index of max (largest) element in current subarray
  int temp;
  temp=arr[size-1];   //size-1 refers to last element of current subarray
  arr[size-1]=arr[maxIndex];
  arr[maxIndex]=temp;
  //assert: last element of current subarray is the max element
  if (size>1) {   //stop recursion when subarray is of size 1 (smallest element)
    //repeat procedure for the subarray with 1 less element
    RecursiveSelectionSort(arr,size-1);
  }
  /* e.g.: [3 2 1 0] -> [0 2 1] 3 -> [0 1] 2 3 -> [0] 1 2 3 (size==1->STOP) */
}

void ShellSort(int arr[], int size) {
  int num_loops=0, j;
  //start with the largest gap and work down to a gap of 1
  for (int gap=size/GAP; gap>0; gap/=GAP) {
    //the first gap elements arr[0...gap-1] are already in gapped order
    //keep adding one more element until the entire array is gap sorted
    for (int i=gap; i<size; i++) {
      //add arr[i] to the elements that have been gap sorted
      int temp=arr[i];
      //shift earlier gap-sorted elements up until correct location for arr[i]
      for (j=i; j>=gap && temp<arr[j-gap]; j-=gap) {
        //do a gapped insertion sort for this gap size
        arr[j]=arr[j-gap];
      }
      //put temp (the original arr[i]) in its correct location
      arr[j]=temp;
      num_loops++;
      if (num_loops<10) cout<<" "; //1->9 (inclusive) align with 10,11,12,...
      cout<<num_loops<<") In ShellSort(int,int):"; Print(arr,size);
    }
  }
}

void Print(int arr[], int size) {
  for (int i=0; i<size; i++)
    cout<<right<<setw(4)<<setfill(' ')<<arr[i];
  cout<<endl;
}
