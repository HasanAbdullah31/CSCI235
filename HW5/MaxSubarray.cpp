/* Hasan Abdullah: MaxSubarray.cpp - divide and conquer recursive algorithm to
   find maximum subarray */

#include <iostream>
#include <iomanip>
#include <climits>
using namespace std;

struct Values {
  int low;
  int high;
  int sum;
};

Values FindMaxCrossingSubarray(int arr[], int low, int mid, int high);
Values FindMaxSubarray(int arr[], int low, int high);

int main(int argc, char **argv) {
  const int SIZE=16;
  int arr[SIZE]={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
  cout<<"The array is:"<<endl;
  for (int i=0; i<SIZE; i++)
    cout<<setw(4)<<setfill(' ')<<arr[i];
  cout<<endl;
  Values result=FindMaxSubarray(arr,0,SIZE-1);
  cout<<"The max subarray is:"<<endl;
  for (int j=result.low; j<=result.high; j++)
    cout<<setw(4)<<setfill(' ')<<arr[j];
  cout<<endl;
  cout<<"The sum of the elements in the max subarray is: "<<result.sum<<endl;
  return 0;
}

Values FindMaxCrossingSubarray(int arr[], int low, int mid, int high) {
  int max_leftIndex;
  int left_sum=INT_MIN;
  int sum=0;
  for (int i=mid; i>=low; i--) {
    sum+=arr[i];
    if (sum>left_sum) {
      left_sum=sum;
      max_leftIndex=i;
    }
  }
  int max_rightIndex;
  int right_sum=INT_MIN;
  sum=0;
  for (int j=mid+1; j<=high; j++) {
    sum+=arr[j];
    if (sum>right_sum) {
      right_sum=sum;
      max_rightIndex=j;
    }
  }
  Values cross_info={max_leftIndex, max_rightIndex, left_sum+right_sum};
  return cross_info;   //return multiple values through the struct
}

Values FindMaxSubarray(int arr[], int low, int high) {
  if (high==low) {
    Values base_case={low, high, arr[low]};
    return base_case;
  }
  else {
    int mid=(low+high)/2;   //the floor of (low+high)/2
    Values left=FindMaxSubarray(arr,low,mid);
    Values right=FindMaxSubarray(arr,mid+1,high);
    Values cross=FindMaxCrossingSubarray(arr,low,mid,high);
    if (left.sum>=right.sum && left.sum>=cross.sum)
      return left;
    else if (right.sum>=left.sum && right.sum>=cross.sum)
      return right;
    else
      return cross;
  }
}
