/* Hasan Abdullah: p2.cpp - Recursive Memoized Matrix Sequence Multiplication */

#include <iostream>
#include <cstdlib>
#include <vector>
#define INT_MAX 2147483647
using namespace std;

const int CHAIN_LENGTH=7;
int m[CHAIN_LENGTH-1][CHAIN_LENGTH-1];
int s[CHAIN_LENGTH-1][CHAIN_LENGTH-1];
int MemoizedMatrixChain(int* p);   //postcond: fills in m and s

typedef vector< vector<int> > TD;
void FillMatrix(TD &M);
void PrintMatrix(TD M);
TD MatrixChainMultiply(TD* A, int i, int j);

int main(int argc, char **argv) {
  int p[CHAIN_LENGTH]={30, 35, 15, 5, 10, 20, 25};
  MemoizedMatrixChain(p);
  //assert: m and s are filled in appropriately
  TD A1(30, vector<int>(35,0)); FillMatrix(A1);
  TD A2(35, vector<int>(15,0)); FillMatrix(A2);
  TD A3(15, vector<int>( 5,0)); FillMatrix(A3);
  TD A4( 5, vector<int>(10,0)); FillMatrix(A4);
  TD A5(10, vector<int>(20,0)); FillMatrix(A5);
  TD A6(20, vector<int>(25,0)); FillMatrix(A6);
  //assert A<1-6> are filled in with sequential values (from 1 to last element)
  TD A[6]={A1, A2, A3, A4, A5, A6};
  TD result=MatrixChainMultiply(A,1,6);
  int rows=result.size(), columns=result[0].size();
  cout<<"Result Matrix ("<<rows<<"*"<<columns<<"):"<<endl;
  PrintMatrix(result);
  return 0;
}

int LookupChain(int* p, int i, int j) { //needed for MemoizedMatrixChain(int* p)
  if (m[i][j]<INT_MAX)
    return m[i][j];
  if (i==j)
    m[i][j]=0;
  else {
    for (int k=i; k<=j-1; k++) {
      int q=LookupChain(p,i,k)+LookupChain(p,k+1,j)+p[i-1]*p[k]*p[j];
      if (q<m[i][j]) {
	m[i][j]=q;
	s[i][j]=k;
      }
    }
  }
  return m[i][j];
}

int MemoizedMatrixChain(int* p) {
  int n=CHAIN_LENGTH-1;
  for (int i=1; i<=n; i++)
    for (int j=i; j<=n; j++)
      m[i][j]=INT_MAX;
  return LookupChain(p,1,n);
}

void FillMatrix(TD &M) {
  int rows=M.size(); int cols=M[0].size();
  int filler=1;
  for (int r=0; r<rows; r++) {
    for (int c=0; c<cols; c++) {
      M[r][c]=filler;
      filler++;
    }
  }
}

TD MultiplyMatrix(TD M1, TD M2) { //needed for MatrixChainMultiply function
  int rows1=M1.size(); int cols1=M1[0].size();
  int rows2=M2.size(); int cols2=M2[0].size();
  if (cols1!=rows2) { //1st matrix's # columns must == 2nd matrix's # rows
    cout<<"Invalid matrix multiplication!"<<endl;
    exit(1);
  }
  //M1[r1][c1]*M2[r2==c1][c2]=M3[r1][c2]; initialize all entries to 0
  TD M3(rows1, vector<int>(cols2,0));
  for(int i=0; i<rows1; i++)
    for(int j=0; j<cols2; j++)
      for(int k=0; k<cols1; k++)
        M3[i][j]+=M1[i][k]*M2[k][j];
  return M3;
}

TD MatrixChainMultiply(TD* A, int i, int j) {
  TD X;
  TD Y;
  if (j>i) {
    X=MatrixChainMultiply(A,i,s[i][j]);
    Y=MatrixChainMultiply(A,s[i][j]+1,j);
    return MultiplyMatrix(X,Y);
  }
  else
    return A[i-1];   //i will start at 1; A[0] is C++ 1st element
}

void PrintMatrix(TD M) {
  int rows=M.size();
  int cols=M[0].size();
  for (int i=0; i<rows; i++) {
    for (int j=0; j<cols; j++) {
      cout<<M[i][j]<<" ";
    }
    cout<<endl;
  }
}
