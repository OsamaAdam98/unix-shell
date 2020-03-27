#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <iostream>

typedef pid_t pid;
using namespace std;

void dispatchProcess(int argc, char* argv[]) {
  // cout << argc << endl;

  // for (int i = 0; i < argc - 1; i++) {
  //   cout << argv[i] << endl;
  // }

  pid processID = fork();
  if (processID < 0) {
    perror("Fork failed!\n");
    exit(1);
  } else if (processID == 0 && argc > 1) {
    char* args[argc];
    for (int i = 0; i <= argc; i++) {
      if (i == argc)
        args[i] = NULL;
      else
        args[i] = (char*)argv[i];
    }
    if (!strcmp(args[0], "cd"))
      if (!args[1] || !strcmp(args[1], "~"))
        chdir(getenv("HOME"));
      else
        chdir(args[1]);
    else
      execvp(args[0], args);
  }
}