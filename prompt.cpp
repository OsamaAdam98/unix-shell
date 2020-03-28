#include <iostream>

using namespace std;

string prompt(char *username) {
  string userInput;
  cout << username << "@shell => ";
  getline(cin, userInput);
  return userInput;
}