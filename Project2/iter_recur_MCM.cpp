void MatrixChainOrder(int* p) { //iteration version
  int i, j, k, L, q;
  int n=CHAIN_LENGTH-1;
  for (i=1; i<=n; i++) {
    m[i][i]=0;
  }
  for (L=2; L<=n; L++) {
    for (i=1; i<=n-L+1; i++) {
      j=i+L-1;
      m[i][j]=INT_MAX;
      for (k=i; k<=j-1; k++) {
        q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
        if (q<m[i][j]) {
	  m[i][j]=q;
          s[i][j]=k;
	}
      }
    }
  }
}

int RecursiveMatrixChainOrder(int* p, int i, int j) { //dumb recursion version
  /* RecursiveMatrixChainOrder(p,1,CHAIN_LENGTH-1) == MatrixChainOrder(p) */
  if (i==j)
    return 0;
  m[i][j]=INT_MAX;
  for (int k=i; k<=j-1; k++) {
    int q=RecursiveMatrixChainOrder(p,i,k)+
          RecursiveMatrixChainOrder(p,k+1,j)+p[i-1]*p[k]*p[j];
    if (q<m[i][j]) {
      m[i][j]=q;
      s[i][j]=k;
    }
  }
  return m[i][j];
}

void PrintMatrix(int arr[CHAIN_LENGTH-1][CHAIN_LENGTH-1]) {
  int i, j;
  for (i=1; i<=CHAIN_LENGTH-1; i++) {
    for (j=1; j<=CHAIN_LENGTH-1; j++) {
      cout<<arr[i][j]<<"\t";
    }
    cout<<endl;
  }
}

template<typename T, int rows, int cols>
void FillMatrix(T(&M)[rows][cols]) {
  int filler=1;
  for (int r=0; r<rows; r++) {
    for (int c=0; c<cols; c++) {
      M[r][c]=filler;
      filler++;
    }
  }
}

template<typename T, int rows1, int cols1, int rows2, int cols2>
vector< vector<T> > MultiplyMatrix(T(&M1)[rows1][cols1], T(&M2)[rows2][cols2]) {
  if (cols1!=rows2) {
    cout<<"Invalid matrix multiplication!"<<endl;
    exit(1);
  }
  vector< vector<T> > M3(rows1, vector<T>(cols2,0));
  for(int i=0; i<rows1; i++)
    for(int j=0; j<cols2; j++)
      for(int k=0; k<cols1; k++)
        M3[i][j]+=M1[i][k]*M2[k][j];
  return M3;
}

template<typename T, int rows, int cols>
void PrintMatrix(T(&M)[rows][cols]) {
  for (int r=0; r<rows; r++) {
    for (int c=0; c<cols; c++) {
      cout<<M[r][c]<<" ";
    }
    cout<<endl;
  }
}
