#include <iostream>

using namespace std;

string prompt(char *username) {
  string userInput;
  cout << username << "@shell => ";
  getline(cin, userInput);
  if (cin.eof()) return "logout";
  return userInput;
}