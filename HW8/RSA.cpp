/* Hasan Abdullah: RSA.cpp - Cryptography (RSA) implementation */

#include <iostream>
using namespace std;

//Modular Exponentiation - compute: x^n(mod p)
int ModExp(int x, int n, int p);
//Greatest Common Divisor - compute: GCD(a,b)
int GCD(int a, int b);
//Multiplicative Inverse - solve for x: a*x=1(mod n)
int MultInv(int a, int n);
//Primality Testing - determine whether n is prime
bool isPrime(int n);

int main(int argc, char **argv) {
  
  cout<<"Step 1: Choose 2 large primes p,q and compute N=p*q"<<endl;
  srand(time(0));
  int p=0;
  int q=0;
  while (!isPrime(p) || !isPrime(q) || p==q) {
    p=rand()%100;
    q=rand()%100;
  }
  //assert: p!=q && p and q are primes between 0 and 99
  cout<<"  p="<<p<<endl;
  cout<<"  q="<<q<<endl;
  //assert: N will not overflow for any p*q
  int N=p*q;
  cout<<"  N="<<N<<endl;
  
  cout<<"Step 2: Compute N'=(p-1)*(q-1)"<<endl;
  int N_prime=(p-1)*(q-1);
  cout<<"  N'="<<N_prime<<endl;
  
  cout<<"Step 3: Choose a large e in [2...N'-1] such that gcd(e,N')=1"<<endl;
  int e=0;
  int d=0;   //d from step 4
  while (e<2 || e>(N_prime-1) || GCD(e,N_prime)!=1 ||
	 d<2 || d>(N_prime-1) || GCD(d,N_prime)!=1) {
    //compute d (step 4) also, in order to find a pair of e,d that works
    e=rand()%N_prime/2;   //make e not too large to avoid overflow
    d=MultInv(e,N_prime);
  }
  cout<<"  e="<<e<<endl;
  
  cout<<"Step 4: Compute d in [2...N'-1] such that e*d=1(mod N') & gcd(d,N')=1"
      <<endl;   //was already computed in step 3, so just output
  cout<<"  d="<<d<<endl;
  
  cout<<"Step 5: The public key is <e,N>"<<endl;
  cout<<"  e="<<e<<endl;
  cout<<"  N="<<N<<endl;
  
  cout<<"Step 6: The private key is <d,N>"<<endl;
  cout<<"  d="<<d<<endl;
  cout<<"  N="<<N<<endl;
  
  cout<<"Step 7: Test for a message using encryption and decryption"<<endl;
  char msg[12]={'H','e','l','l','o',' ','w','o','r','l','d','!'};
  cout<<"  Original message: ";
  for (int i=0; i<12; i++)
    cout<<msg[i];
  cout<<endl;
  int bits[12];
  cout<<"  Message as ASCII sequence: ";
  for (int i=0; i<12; i++) {
    bits[i]=(int)msg[i];   //converts char to int (ASCII)
    cout<<bits[i];
  }
  cout<<endl;
  cout<<"  Encrypted message R=M^e(mod N): ";
  int R[12];
  for (int j=0; j<12; j++) {
    R[j]=ModExp(bits[j], e, N);   //M (original message) is stored in bits
    cout<<(char)R[j];   //int(ASCII)->char; new sequence is random message R
  }
  cout<<endl;
  cout<<"  Decrypted message M=R^d(mod N): ";
  int M[12];
  for (int k=0; k<12; k++) {
    M[k]=ModExp(R[k], d, N);
    cout<<(char)M[k];   //should be original bits (i.e. original message M)
  }
  cout<<endl;
  
  return 0;
}

int ModExp(int x, int n, int p) {   //running time: θ(lg n)
  int result;
  if (n==0) {   //base case: x^0 = 1
    result=1;
    return result;
  }
  //case if n is even (do recursive call):
  result=ModExp((x*x)%p, n/2, p);   //((x*x)mod p)^[floor of (n/2)]
  //case if n is odd (on same recursive call, compute the odd values of n):
  if (n%2!=0)
    result=(result*x)%p;   //multiply by x and mod p the result
  return result;
}

int GCD(int a, int b) {   //running time: 2*θ(lg a)
  //gcd(a,b)=gcd(a-b,b); keep - the larger of a and b from the other until the
  //difference is smaller than the 2nd # (i.e. a%b); the #s will switch, so
  //the 1st#>2nd#; eventually, difference will be 0; last non-zero value is gcd
  int result;
  if (b==0)
    result=a;
  else
    result=GCD(b, a%b);
  return result;   //last dividend not equal to 0
}

void FindXY(int a, int b, int &x, int &y) { //helper function for MultInv(...)
  //if a*x=1(mod n)->a*x+n*y=1(mod n) and a*x+n*y=1; solution only if a has MI
  int x1, y1;
  if (b==0) { //a*x=1->a=x=1 and n*y=0->y=0 (n!=0 b/c can't do %0)
    x=1;
    y=0;
  }
  else { //b!=0; gcd(a,b)=gcd(b,a%b); r=a%b; a=b*q+r->gcd(a,b)=gcd(b,r)
    //b*x1+r*y1=1; r=a-b*q->b*x1+(a-b*q)*y1=1->a*y1+b*(x1-q*y1)=1
    //x1 and y1 satisfy b*x1+r*y1=1 and r=a%b; so we found solution a*x+b*y=1
    FindXY(b, a%b, x1, y1);
    x=y1;
    y=x1-(a/b)*(y1); //[floor of] a/b is q
  }
}

int MultInv(int a, int n) {
  int x, y;
  FindXY(a, n, x, y);   //find r=a%b and solve b*x1+r*y1=1 recursively
  if (x>0)
    return x;
  else
    return x+n;
}

bool isPrime(int n) {
  if (n<2)   //1,0, and - integers are not prime
    return false;
  else if (n==2)   //2 is first prime number
    return true;
  else if (n%2==0)   //even numbers greater than 2 are not prime
    return false;
  for (int i=3; (i*i)<=n; i+=2) {   //occurs when n is odd and >=9
    //only need to test until n/2; assert: sqrt(n)<=n/2; (i*i)<=n == i<=sqrt(n)
    //i+=2 to check for / by odd #s only (even #s checked in above else if)
    if (n%i==0)
      return false;
  }
  return true;   //assert: n is prime (e.g. 3,5,7,11,13,17,19,23)
}
