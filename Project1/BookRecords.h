/* Hasan Abdullah: BookRecords.h - header file for class BookRecords */

#ifndef BOOK_RECORDS
#define BOOK_RECORDS

#include "RecordLimits.h"   //for SortType
#include "Array.h"
#include "Book.h"

class BookRecords {
private:
 Array<Book> books;
 int SIZE;   //size of Book Array
 void OutputLine(ostream &output, const Book book, streamoff pos);
 void ErrorHandler(string file_name);
public:
 BookRecords();
 BookRecords(Book* source, int size);
 Book Get(int i);
 int Size();
 bool Exists(Book book);
 void To_File();
 void Replace(int i, Book &newBook);
 void InsertRecord(Book &newBook);
 void Swap(int i, int j);
 void SelectionSort();
 void MergeSort();
 void Sort(SortType t);
 void PrintRecords();
};

#endif /* BOOK_RECORDS */
