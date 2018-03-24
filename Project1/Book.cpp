/* Hasan Abdullah: Books.cpp - implementation of class Book */

#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "RecordLimits.h"
#include "Book.h"
using namespace std;

Book::Book() {}
Book::Book(int k, string a, string t, unsigned long int i) {
  Set_Key(k); Set_Author(a); Set_Title(t); Set_ISBN(i);
}

int Book::Get_Key() { return key; }
string Book::Get_Author() { return author; }
string Book::Get_Title() { return title; }
unsigned long int Book::Get_ISBN() { return ISBN; }

void Book::Set_Key(int k) {
  string s=to_string(k);
  if (s.length()>KEY_SIZE) {
    cout<<"In Book::Set_Key(int)..."<<endl;
    cout<<"Key must be an int with at most "<<KEY_SIZE<<" digits!"<<endl;
    exit(1);
  }
  key=k;
}
void Book::Set_Author(string a) {
  if (a.length()>AUTHOR_SIZE) {
    cout<<"In Book::Set_Author(string)..."<<endl;
    cout<<"Author can have at most "<<AUTHOR_SIZE<<" characters!"<<endl;
    exit(1);
  }
  author=a;
}
void Book::Set_Title(string t) {
  if (t.length()>TITLE_SIZE) {
    cout<<"In Book::Set_Title(string)..."<<endl;
    cout<<"Title can have at most "<<TITLE_SIZE<<" characters!"<<endl;
    exit(1);
  }
  title=t;
}
void Book::Set_ISBN(unsigned long int i) {
  string s=to_string(i);
  if (s.length()!=ISBN_SIZE && s.length()!=10) {
    cout<<"In Book::Set_ISBN(unsigned long int)..."<<endl;
    cout<<"ISBN must be either "<<ISBN_SIZE<<" or 10 digits long!"<<endl;
    exit(1);
  }
  ISBN=i;
}

bool operator>(Book b1, Book b2) {
  if (b1.author>b2.author)
    return true;
  else if (b1.author==b2.author) {
    if (b1.title>b2.title)
      return true;
    //there cannot be 2 books with the same author AND title in my file
    else
      return false;
  }
  else //if (b1.author<b2.author)
    return false;
}
bool operator<(Book b1, Book b2) {
  return !(b1>b2 || b1==b2);
  //by DeMorgan's Law, same as !(b1>b2) && !(b1==b2), i.e. b1<b2
}

bool operator>=(Book b1, Book b2) {
  return (b1>b2 || b1==b2);
}
bool operator<=(Book b1, Book b2) {
  return (b1<b2 || b1==b2);
}

bool operator==(Book b1, Book b2) {
  if (b1.author==b2.author && b1.title==b2.title)
    return true;
  else
    return false;
}
bool operator!=(Book b1, Book b2) {
  return !(b1==b2);
}

istream &operator>>(istream &input, Book &book) {
  if (input.peek()==EOF) return input;   //skip last empty line
  int key_f; string author_f; string title_f; unsigned long int ISBN_f;
  
  input>>key_f;
  book.key=key_f;
  input.ignore(99,'\t');   //ignore the tab after the key field
  
  getline(input,author_f,'\t');
  //trim trailing whitespaces from author_f (there are no leading whitespaces)
  size_t endpos=author_f.find_last_not_of(' ');
  book.author=author_f.substr(0,endpos+1); //length of substring is endpos+1
  
  getline(input,title_f,'\t');
  endpos=title_f.find_last_not_of(' ');
  book.title=title_f.substr(0,endpos+1);   //same trimming for title_f
  
  while (input.peek()==' ')   //ignore leading whitespaces by moving cursor
    input.seekg(1,ios::cur);  //in case ISBN is 10 characters instead of max 13
  input>>ISBN_f;
  book.ISBN=ISBN_f;
  input.ignore(99,'\n');
  
  if (input.fail()) {
    cout<<"In istream &operator>>(istream&,Book&)..."<<endl;
    cout<<"Invalid data format for input!"<<endl;
    exit(1);
  }
  return input;   //for multiple >> operators
}
ostream &operator<<(ostream &output, const Book &book) {
  output<<left<<setw(KEY_SIZE)<<setfill(' ')<<book.key<<'\t';
  output<<left<<setw(AUTHOR_SIZE)<<setfill(' ')<<book.author<<'\t';
  output<<left<<setw(TITLE_SIZE)<<setfill(' ')<<book.title<<'\t';
  output<<right<<setw(ISBN_SIZE)<<setfill(' ')<<book.ISBN;
  //did not output '\n'; user controls when (e.g. cout<<b; or cout<<b<<endl;)
  if (output.fail()) {
    cout<<"In ostream &operator<<(ostream&,const Book&)..."<<endl;
    cout<<"Invalid data format for output!"<<endl;
    exit(1);
  }
  return output;
}
void Book::Print() {
  cout<<*(this)<<endl;   //use overloaded << for Book
}
