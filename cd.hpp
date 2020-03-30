#ifndef CD
#define CD
#include <string.h>
#include <unistd.h>
#include <iostream>
#ifndef bufferLength
#define bufferLength 99
#endif

using namespace std;

void cd(int argc, char *args[], char *cwd) {
  if (argc == 2) {
    chdir(getenv("HOME"));
  } else {
    if (string(args[1]) == "~")
      chdir(getenv("HOME"));
    else
      chdir(args[1]);
  }
  getcwd(cwd, bufferLength);
}
#endif