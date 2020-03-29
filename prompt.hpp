#ifndef PROMPT
#define PROMPT
#include <iostream>

using namespace std;

string prompt(char *username, char *cwd) {
  string userInput;
  cout << username << "@shell " << cwd << "=> ";
  getline(cin, userInput);
  if (cin.eof()) return "logout";
  return userInput;
}
#endif