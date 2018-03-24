/* Hasan Abdullah: NoPermissions.cpp - implementation of class NoPermissions */

#include <errno.h>
#include <sys/stat.h>   //for chmod function
#include <cstring>   //for strerror function
#include <iostream>
#include "FileError.h"
#include "NoPermissions.h"
using namespace std;

NoPermissions::NoPermissions(string s) : FileError() { file_name=s; }

bool NoPermissions::Permissions() {
  if (errno==EACCES)   //permission denied
    return false;   //objectName.Permissions()==false
  else
    return true;
}

void NoPermissions::PrintPermissions() {
  /* from stackoverflow.com/questions/10323060/printing-file-permissions-
     like-ls-l-using-stat2-in-c */
  struct stat info;
  stat(file_name.c_str(),&info);
  printf( (S_ISDIR(info.st_mode)) ? "d" : "-");
  printf( (info.st_mode & S_IRUSR) ? "r" : "-");
  printf( (info.st_mode & S_IWUSR) ? "w" : "-");
  printf( (info.st_mode & S_IXUSR) ? "x" : "-");
  printf( (info.st_mode & S_IRGRP) ? "r" : "-");
  printf( (info.st_mode & S_IWGRP) ? "w" : "-");
  printf( (info.st_mode & S_IXGRP) ? "x" : "-");
  printf( (info.st_mode & S_IROTH) ? "r" : "-");
  printf( (info.st_mode & S_IWOTH) ? "w" : "-");
  printf( (info.st_mode & S_IXOTH) ? "x" : "-");
}

void NoPermissions::Handler() {
  cout<<"Permissions error! Old permissions of "<<file_name<<": ";
  PrintPermissions(); cout<<endl;
  cout<<"Attempting to change read/write permissions of '"<<file_name<<"'...\n";
  mode_t MODE=S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH; // -rw-r--r--
  int val=chmod(file_name.c_str(), MODE);   //returns 0 on success
  if (val!=0) {
    cout<<"Attempt failed! "<<strerror(errno)<<endl;
    exit(1);
  }
  cout<<"Attempt succeeded! New permissions of "<<file_name<<": ";
  PrintPermissions(); cout<<endl;
}
