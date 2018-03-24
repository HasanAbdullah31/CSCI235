/* Hasan Abdullah: BookRecords.cpp - implementation of class BookRecords */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Array.h"
#include "Array.cpp"
#include "FileError.h"
#include "NonExistent.h"
#include "NoPermissions.h"
#include "RecordLimits.h"
#include "Book.h"
#include "BookRecords.h"
using namespace std;

BookRecords::BookRecords() { SIZE=0; }
BookRecords::BookRecords(Book* source, int size) {
  for (int i=0; i<size-1; i++) {
    for (int j=i+1; j<size; j++) {
      if (source[i]==source[j]) {   //overloaded == for Book
	cout<<"In BookRecords::BookRecords(Book*,int)..."<<endl;
        cout<<"There is a repeated book in the array of Books!"<<endl;
        exit(1);
      }
    }
  }
  for (int k=0; k<size; k++)
    source[k].Set_Key(k); //the key of books[k] should be k
  books=Array<Book>(source,size);   //overloaded constructor from Array class
  SIZE=books.Size();   //Size function from Array class
}

Book BookRecords::Get(int i) {
  if (i<0 || i>=SIZE) {
    cout<<"In BookRecords::Get(int)..."<<endl;
    cout<<"Key out of range!"<<endl;
    exit(1);
  }
  return books.Get(i);   //Get function from Array class
}
int BookRecords::Size() { return SIZE; }

bool BookRecords::Exists(Book book) {
  bool exists=false;
  for (int i=0; i<SIZE; i++) {
    if (books.Get(i)==book) {   //overloaded == for Book
      exists=true;
      break;
    }
  }
  return exists;
}

void BookRecords::ErrorHandler(string file_name) {
  ifstream error_check;
  error_check.open(file_name.c_str());
  try {
    NonExistent exist_check(file_name);
    NoPermissions permissions_check(file_name);
    if (exist_check.Exists()==false)
      throw exist_check;
    else if (permissions_check.Permissions()==false)
      throw permissions_check;
  }
  catch (FileError &error) {
    error.Handler();
  }
  error_check.close();
  return;
}

void BookRecords::OutputLine(ostream &output, const Book book, streamoff pos) {
  fstream temp;
  temp.open("temp.txt", fstream::out | fstream::binary | fstream::trunc);
  if (temp.fail()) { //i.e. there exists a 'temp.txt' without write permissions
    remove("temp.txt");
    temp.open("temp.txt", fstream::out | fstream::binary | fstream::trunc);
    if (temp.fail()) { //i.e. 'temp.txt' could not be created for output
      cout<<"In BookRecords::OutputLine(ostream&,const Book,streamoff)...\n";
      cout<<"'temp.txt' could not be created!"<<endl;
      exit(1);
    }
  }
  //assert: 'temp.txt' exists and has read and write permissions
  temp<<book<<'\n';   //overloaded << for Book
  temp.close();
  temp.open("temp.txt", fstream::in | fstream::binary);
  char* buffer=(char* )malloc(RECORD_SIZE*sizeof(char));
  temp.read(buffer,RECORD_SIZE);
  if (pos>=0) output.seekp(pos,ios::beg);
  output.write(buffer,RECORD_SIZE);
  free(buffer);
  buffer=NULL;
  temp.close();
  remove("temp.txt");
}

void BookRecords::To_File() {
  ofstream output;
  //if FILENAME does not exist, To_File() creates it (hence the trunc mode)
  output.open(FILENAME.c_str(), ofstream::binary | ofstream::trunc);
  ErrorHandler(FILENAME);
  output.close();   //need to close and re-open if permissions changed
  //assert: FILENAME exists and has read and write permissions
  output.open(FILENAME.c_str(), ofstream::binary | ofstream::trunc);
  cout<<"In BookRecords::To_File()...Creating '"<<FILENAME<<"'..."<<endl;
  for (int i=0; i<SIZE; i++) {
    //assert: output.tellp()==i*RECORD_SIZE
    OutputLine(output,books.Get(i),-1);
  }
  output.close();
}

void BookRecords::Replace(int i, Book &newBook) {
  if (i<0 || i>=SIZE) {
    cout<<"In BookRecords::Replace(int,Book&)..."<<endl;
    cout<<"Key out of range!"<<endl;
    exit(1);
  }
  if (Exists(newBook)) {
    cout<<"In BookRecords::Replace(int,Book&)..."<<endl;
    cout<<"Book already exists in the array of Books!"<<endl;
    exit(1);
  }
  newBook.Set_Key(i);   //in case newBook.key != i
  books.Set(i,newBook);   //Set function from Array class
  ErrorHandler(FILENAME);
  //assert: FILENAME exists and has read and write permissions
  fstream output; //need to open both in and out modes to avoid overwriting
  output.open(FILENAME.c_str(), fstream::in | fstream::out | fstream::binary);
  streamoff pos=i*RECORD_SIZE; //random access file allows jumping to i'th line
  OutputLine(output,books.Get(i),pos);
  output.close();
}

void BookRecords::InsertRecord(Book &newBook) {
  if (Exists(newBook)) {
    cout<<"In BookRecords::InsertRecord(Book&)..."<<endl;
    cout<<"Book already exists in the array of Books!"<<endl;
    exit(1);
  }
  newBook.Set_Key(SIZE);   //max key was SIZE-1, so new record key is 1 more
  books.Insert(newBook);   //Insert function from Array class
  SIZE++;   //now newBook.key==SIZE-1 (i.e. last element of books)
  //could also do Replace(SIZE-1,newBook) here
  ErrorHandler(FILENAME);
  //assert: FILENAME exists and has read and write permissions
  ofstream output; //open in append mode to add new record to next new line
  output.open(FILENAME.c_str(), ofstream::binary | ofstream::app);
  OutputLine(output,books.Get(SIZE-1),-1);
  output.close();
}

void BookRecords::Swap(int i, int j) {
  if (i<0 || i>=SIZE || j<0 || j>=SIZE) {
    cout<<"In BookRecords::Swap(int,int)..."<<endl;
    cout<<"Key out of range!"<<endl;
    exit(1);
  }
  if (i==j) return;   //"swapping" same element is pointless
  Book temp_i=books.Get(i); temp_i.Set_Key(j);   //swap ONLY the keys
  Book temp_j=books.Get(j); temp_j.Set_Key(i);
  books.Set(i,temp_i);
  books.Set(j,temp_j);
  books.Swap(i,j);   //Swap function from Array class
  //assert: books[i] and books[j] are swapped, but need to change in file too
  ErrorHandler(FILENAME);
  //assert: FILENAME exists and has read and write permissions
  ofstream output; //need to open both in and out modes to avoid overwriting
  output.open(FILENAME.c_str(), fstream::in | fstream::out | fstream::binary);
  streamoff pos=i*RECORD_SIZE;   //move cursor to key i
  OutputLine(output,books.Get(i),pos);
  pos=j*RECORD_SIZE;   //move cursor to key j
  OutputLine(output,books.Get(j),pos);
  output.close();
}

void BookRecords::SelectionSort() {
  cout<<"In BookRecords::SelectionSort()..."<<endl;
  int index;
  for (int i=0; i<SIZE; i++) {
    index=books.Min(i);   //Min function from Array class
    Swap(i,index);   //Swap function from BookRecords (not from Array)
  }
}

void BookRecords::MergeSort() {
  cout<<"In BookRecords::MergeSort()..."<<endl;
  books.MergeSort(0,SIZE-1);   //MergeSort function from Array class
  //although the Books are in order, keys are not
  for (int i=0; i<SIZE; i++) {
    Book temp=books.Get(i);
    temp.Set_Key(i);   //the key of Book in books[i] should be i
    books.Set(i,temp);
  }
  To_File();   //To_File() overwrites data in FILENAME, so not a problem
}

void BookRecords::Sort(SortType t) {   //SortType defined in 'RecordLimits.h'
  if (t==SortType::Selection)
    SelectionSort();
  else //if (t==SortType::Merge)
    MergeSort();
}

void BookRecords::PrintRecords() {
  ErrorHandler(FILENAME);
  //assert: FILENAME exists and has read and write permissions
  ifstream input;
  input.open(FILENAME.c_str(), ifstream::binary);
  while (input.peek()!=EOF) {
    char* buffer=(char* )malloc(RECORD_SIZE*sizeof(char));
    input.read(buffer,RECORD_SIZE);
    if (input.fail()) {
      cout<<"In BookRecords::PrintRecords()..."<<endl;
      cout<<"Invalid data format for input!"<<endl;
      exit(1);
    }
    buffer[RECORD_SIZE-1]='\0';   //null termination character (end of string)
    cout<<buffer<<endl;
    free(buffer);
    buffer=NULL;
  }
  input.close();
}
