/* Hasan Abdullah: Book.h - header file for class Book */

#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book {
private:
 int key;   //sequential unique key
 string author;
 string title;
 unsigned long int ISBN;
public:
 Book();
 Book(int k, string a, string t, unsigned long int i);
 int Get_Key();
 string Get_Author();
 string Get_Title();
 unsigned long int Get_ISBN();
 void Set_Key(int k);
 void Set_Author(string a);
 void Set_Title(string t);
 void Set_ISBN(unsigned long int i);
 void Print();
 friend bool operator>(Book b1, Book b2);
 friend bool operator<(Book b1, Book b2);
 friend bool operator>=(Book b1, Book b2);
 friend bool operator<=(Book b1, Book b2);
 friend bool operator==(Book b1, Book b2);
 friend bool operator!=(Book b1, Book b2);
 friend istream &operator>>(istream &input, Book &book);
 friend ostream &operator<<(ostream &output, const Book &book);
};

#endif /* BOOK_H */
