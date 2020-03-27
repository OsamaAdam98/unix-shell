#include <iostream>
#include <sstream>
#include "dispatchProcess.cpp"

using namespace std;

int main(int argc, char *argv[]) {
  // TODO: Fix args
  if (argc > 1) {
    for (int i = 0; i < argc; i++) {
      argv[i] = argv[i + 1];
    }
    dispatchProcess(argc, argv);
    wait(NULL);
  }

  bool poll = true;

  while (poll) {
    char userInput[99];
    cout << "user@shell => ";
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
      // cout << argsVector[arraySize] << endl;
      arraySize++;
    }

    for (int i = 0; i < arraySize; i++) {
      args[i] = (char *)argsVector[i].c_str();
    }
    if (!strcmp(args[0], "exit")) {
      cout << "Farewell!" << endl;
      exit(0);
    } else {
      dispatchProcess(arraySize + 1, args);
      wait(NULL);
    }
  }
}