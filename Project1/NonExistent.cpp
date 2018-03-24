/* Hasan Abdullah: NonExistent.cpp - implementation of class NonExistent */

#include <errno.h>
#include <iostream>
#include <cstdlib>
#include "FileError.h"
#include "NonExistent.h"
using namespace std;

NonExistent::NonExistent(string s) : FileError() { file_name=s; }

bool NonExistent::Exists() {
  if (errno==ENOENT)   //no such file or directory
    return false;   //objectName.Exists()==false
  else
    return true;
}

void NonExistent::Handler() {
  cout<<"File error! '"<<file_name<<"' does not exist in current directory!\n";
  exit(1);
}
