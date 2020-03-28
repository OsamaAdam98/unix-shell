#include <sys/wait.h>
#include <unistd.h>
#include <iostream>

using namespace std;
typedef pid_t pid;

void terminator(pid sigPid) {
  int status;
  while (waitpid(-1, &status, WNOHANG) > 0) {
    // cout << status << endl;
  }
}