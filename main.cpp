#include <iostream>
#include <sstream>
#include "dispatchProcess.cpp"
#include "prompt.cpp"

#define bufferLength 99

using namespace std;

int main(int argc, char *argv[]) {
  if (argc > 1) {
    for (int i = 0; i < argc; i++) {
      argv[i] = argv[i + 1];
    }
    dispatchProcess(argc, argv);
    wait(NULL);
  }

  char username[bufferLength];
  FILE *configFile;

  if ((configFile = fopen(".shellrc", "r"))) {
    fgets(username, bufferLength, configFile);
    fclose(configFile);
  } else {
    cout << "Enter username: ";
    cin >> username;
    configFile = fopen(".shellrc", "w+");
    fprintf(configFile, "%s", username);
    fclose(configFile);
  }

  while (1) {
    string userInput;
    do {
      userInput = prompt(username);
    } while (userInput.empty() || isspace(userInput.at(0)));
    stringstream stream(userInput);
    string token;
    string argsVector[bufferLength];
    char *args[bufferLength];
    for (int i = 0; i < bufferLength; i++) args[i] = NULL;
    int arraySize = 0;
    while (stream >> token) {
      argsVector[arraySize] = token;
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