#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <iostream>
#include "cd.cpp"

typedef pid_t pid;
using namespace std;

void dispatchProcess(int argc, char* argv[]) {
  // cout << argc << endl;

  // for (int i = 0; i < argc - 1; i++) {
  //   cout << argv[i] << endl;
  // }

  char* args[argc];
  for (int i = 0; i <= argc; i++) {
    if (i == argc)
      args[i] = NULL;
    else
      args[i] = (char*)argv[i];
  }
  if (argc > 1) {
    pid processID = fork();

    if (processID < 0) {
      perror("Fork failed!\n");
      exit(1);
    } else if (processID == 0) {
      if (!strcmp(args[argc - 2], "&")) {
        args[argc - 2] = NULL;
        dispatchProcess(argc - 1, args);
        exit(0);
      } else {
        if (!strcmp(args[0], "cd")) {
          exit(0);
        } else
          execvp(args[0], args);
        exit(0);
      }
    } else {
      if (!strcmp(args[0], "cd")) {
        cd(argc, args);
      } else if (!strcmp(args[argc - 2], "&")) {
        // TODO: Fix zombie processes
        args[argc - 2] = NULL;
        dispatchProcess(argc - 1, args);
      }
    }
  }
}