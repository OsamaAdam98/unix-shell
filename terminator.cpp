#include <sys/wait.h>
#include <time.h>
#include <unistd.h>
#include <iostream>

using namespace std;
typedef pid_t pid;

void terminator(pid sigPid) {
  if (sigPid == SIGCHLD) {
    int status;
    pid processPid;
    time_t localTime = time(NULL);
    FILE *logFile = fopen("./shell.log", "a+");

    while ((processPid = waitpid(-1, &status, WNOHANG)) > 0) {
      fprintf(logFile, "%s\tProcess %d exited with status %d\n",
              asctime(localtime(&localTime)), processPid, status);
    }
    fclose(logFile);
  }
}