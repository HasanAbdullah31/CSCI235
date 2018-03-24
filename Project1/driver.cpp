/* Hasan Abdullah: driver.cpp - main program for Book project */

#include <iostream>
#include "RecordLimits.h"   //for FILENAME and SortType
#include "Book.h"
#include "BookRecords.h"
using namespace std;

int main(int argc, char **argv) {
  const int SIZE=6;
  Book books[SIZE];
  books[0].Set_Author("J.D. Salinger");
  books[0].Set_Title("The Catcher in the Rye");
  books[0].Set_ISBN(9780316769488);
  
  books[1].Set_Author("F. Scott Fitzgerald");
  books[1].Set_Title("The Great Gatsby");
  books[1].Set_ISBN(9780743273565);
  
  books[2].Set_Author("Dan Brown");
  books[2].Set_Title("The Da Vinci Code");
  books[2].Set_ISBN(9780307474278);
  
  books[3].Set_Author("George Orwell");
  books[3].Set_Title("Nineteen Eighty-Four");
  books[3].Set_ISBN(9780141036144);
  
  books[4].Set_Author("Mark Twain");
  books[4].Set_Title("Adventures of Huckleberry Finn");
  books[4].Set_ISBN(9780486280615);
  
  books[5].Set_Author("Aldous Huxley");
  books[5].Set_Title("Brave New World");
  books[5].Set_ISBN(9780060850524);
  BookRecords myBooks;
  myBooks=BookRecords(books,SIZE);
  
  myBooks.To_File();
  cout<<"The text file '"<<FILENAME<<"' contains:"<<endl;
  myBooks.PrintRecords();
  cout<<"'"<<FILENAME<<"' sorted using merge sort:"<<endl;
  myBooks.Sort(SortType::Merge);
  myBooks.PrintRecords();
  
  Book NEW(5,"William Shakespeare","The Taming of the Shrew",9781613821589);
  myBooks.Replace(5,NEW);
  cout<<"'"<<FILENAME<<"' with key 5's record replaced:"<<endl;
  myBooks.PrintRecords();
  cout<<"'"<<FILENAME<<"' sorted using merge sort:"<<endl;
  myBooks.Sort(SortType::Merge);
  myBooks.PrintRecords();
  
  NEW.Set_Author("George Orwell");
  NEW.Set_Title("Animal Farm");
  NEW.Set_ISBN(9788129116123);
  myBooks.InsertRecord(NEW);
  cout<<"'"<<FILENAME<<"' after adding new record to end:"<<endl;
  myBooks.PrintRecords();
  cout<<"'"<<FILENAME<<"' sorted using merge sort:"<<endl;
  myBooks.Sort(SortType::Merge);
  myBooks.PrintRecords();
  return 0;
}
