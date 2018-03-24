/* Hasan Abdullah: RecordLimits.h - header file for max limits and filename */

#ifndef RECORD_LIMITS
#define RECORD_LIMITS

#include <string>
using namespace std;

enum class SortType {Selection,Merge};

const string FILENAME="books.txt";   /* do NOT change this to "temp.txt"! */
const int MAXSIZE=30; //max. # of Books in the array (i.e. max records in file)
/* KEY_SIZE should equal the number of digits in MAXSIZE */
const int KEY_SIZE=2;       // \t after key field (+1 RECORD_SIZE)
const int AUTHOR_SIZE=20;   // \t after author field (+1 RECORD_SIZE)
const int TITLE_SIZE=30;    // \t after title field (+1 RECORD_SIZE)
const int ISBN_SIZE=13;     // \n after ISBN field (+1 RECORD_SIZE)
const int RECORD_SIZE=KEY_SIZE+AUTHOR_SIZE+TITLE_SIZE+ISBN_SIZE+4;

#endif /* RECORD_LIMITS */
