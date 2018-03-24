/* Hasan Abdullah: NonExistent.h - header file for derived class NonExistent */

#ifndef NON_EXISTENT
#define NON_EXISTENT

#include <string>
#include "FileError.h"
using namespace std;

class NonExistent : public FileError {
private:
 string file_name;
public:
 NonExistent(string s);
 bool Exists();
 void Handler();
};

#endif /* NON_EXISTENT */
