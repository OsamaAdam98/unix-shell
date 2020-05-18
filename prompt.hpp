#ifndef PROMPT
#define PROMPT
#include <iostream>
using namespace std;

string prompt(char *username, char *hostname, char *cwd) {
  string userInput;
  string cwdString = string(cwd);
  string replaceString = "/home/" + string(username);

  if (cwdString.find(replaceString) < cwdString.length())
    cwdString.replace(0, replaceString.length(), "~");

  cout << username << "@" << hostname << " " << cwdString << " => ";
  getline(cin, userInput);
  if (cin.eof())
    return "logout";
  return userInput;
}
#endif