#ifndef DISPATCHER
#define DISPATCHER
#include <string.h>
#include <unistd.h>
#include <iostream>
#include "cd.hpp"
#include "terminator.hpp"

typedef pid_t pid;
using namespace std;

void dispatcher(int argc, char* argv[]) {
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
      // cout << "Child pid: " << getpid() << endl;

      if (!strcmp(args[argc - 2], "&")) {
        exit(0);
      } else {
        if (!strcmp(args[0], "cd")) {
          exit(0);
        } else if (!strcmp(args[0], "log")) {
          const char* log[] = {"vi", "shell.log", NULL};
          execvp(log[0], (char**)log);
        } else
          execvp(args[0], args);
      }
    } else {
      // cout << "Parent pid: " << getpid() << endl;
      if (!strcmp(args[0], "cd")) {
        cd(argc, args);
      } else if (!strcmp(args[argc - 2], "&")) {
        args[argc - 2] = NULL;
        dispatcher(argc - 1, args);
        signal(SIGCHLD, terminator);
      }
    }
  }
}
#endif