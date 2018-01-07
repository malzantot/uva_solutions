/**
    Author: Moustafa Alzantot (malzantot@ucla.edu)
    All rights reserved.
**/
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
  int n;
  cin >> n;
  cin.get();
  for (int i = 0; i < n; i++) {
    string input;
    getline(cin, input);
    string result = input;
    for (int i = 1; i < input.size(); i++) {
      string rotated = input.substr(i) + input.substr(0, i);
      if (rotated < result) {
        result = rotated;
      }
    }
    cout << result << endl;
  }
}
