#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;
typedef pid_t pid;

int main(int argc, char *argv[]) {
  pid processID = fork();

  if(processID < 0) {
    perror("Fork failed!\n");
    exit(1);
  } else if(processID == 0) {
    char *args[argc + 1];
    for(int i = 0; i < argc; i++) {
      if(i == argc) args[i] = NULL;
      args[i] = argv[i + 1];
    }
    execvp(argv[1], args);
  }
  wait(NULL);
}