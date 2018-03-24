/* Hasan Abdullah: NoPermissions.h - .h file for derived class NoPermissions */

#ifndef NO_PERMISSIONS
#define NO_PERMISSIONS

#include <string>
#include "FileError.h"
using namespace std;

class NoPermissions : public FileError {
private:
 string file_name;
public:
 NoPermissions(string s);
 bool Permissions();
 void PrintPermissions();
 void Handler();
};

#endif /* NO_PERMISSIONS */
