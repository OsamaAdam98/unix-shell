#include <string.h>
#include <iostream>
#include <sstream>
#include <vector>
#include "dispatchProcess.cpp"

using namespace std;

int main(int argc, char *argv[]) {
  // TODO: Fix args
  // if (argc > 1) {
  //   cout << argc << endl;
  //   dispatchProcess(argc, argv, 1);
  // }

  bool poll = true;

  while (poll) {
    char userInput[99];
    cin.getline(userInput, 99, '\n');
    stringstream stream(userInput);
    string token;
    string argsVector[20];
    char *args[20] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL,
                      NULL, NULL, NULL, NULL, NULL, NULL, NULL,
                      NULL, NULL, NULL, NULL, NULL, NULL};
    int arraySize = 0;
    while (stream >> token) {
      argsVector[arraySize] = token;
      cout << argsVector[arraySize] << endl;
      arraySize++;
    }

    for (int i = 0; i < arraySize; i++) {
      args[i] = (char *)argsVector[i].c_str();
    }

    dispatchProcess(arraySize + 1, args);
    wait(NULL);
  }
}