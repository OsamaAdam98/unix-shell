#ifndef CD
#define CD
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

void cd(int argc, char *args[]) {
  if (argc == 2) {
    chdir(getenv("HOME"));
  } else {
    chdir(args[1]);
  }
}
#endif