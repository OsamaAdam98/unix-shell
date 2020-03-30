#ifndef PROMPT
#define PROMPT
#include <iostream>
using namespace std;

string prompt(char *username, char *cwd) {
  string userInput;
  string cwdString = string(cwd);

  if (cwdString.find("home") < cwdString.length())
    cwdString.replace(0, 6 + strlen(username), "~");

  cout << username << "@shell " << cwdString << " => ";
  getline(cin, userInput);
  if (cin.eof()) return "logout";
  return userInput;
}
#endif