#include <iostream>
#include <sstream>
#include "dispatcher.hpp"
#include "prompt.hpp"

#define bufferLength 99

using namespace std;

int main(int argc, char *argv[]) {
  if (argc > 1) {
    for (int i = 0; i < argc; i++) {
      argv[i] = argv[i + 1];
    }
    dispatcher(argc, argv);
    wait(NULL);
  }

  char username[bufferLength];
  FILE *configFile;

  if ((configFile = fopen(".shellrc", "r"))) {
    fgets(username, bufferLength, configFile);
    fclose(configFile);
  } else {
    cout << "enter username: ";
    cin >> username;
    configFile = fopen(".shellrc", "w+");
    fprintf(configFile, "%s", username);
    fclose(configFile);
  }

  string userInput;
  string token;
  string argsVector[bufferLength];
  char *args[bufferLength];
  int arraySize;

  while (1) {
    // clearing
    userInput.clear();
    token.clear();
    arraySize = 0;
    for (int i = 0; i < bufferLength; i++) {
      argsVector[i].clear();
      args[i] = NULL;
    }
    // prompting
    do {
      userInput = prompt(username);
    } while (userInput.empty() || isspace(userInput.at(0)));
    if (userInput == "logout") {
      cout << endl << "logging out.." << endl;
      break;
    }
    // string splitting
    stringstream stream(userInput);
    while (stream >> token) {
      argsVector[arraySize] = token;
      args[arraySize] = (char *)argsVector[arraySize].c_str();
      arraySize++;
    }
    // actual processing
    if (!strcmp(args[0], "exit")) {
      terminator(SIGQUIT);
    } else {
      dispatcher(arraySize + 1, args);
      wait(NULL);
    }
  }
}