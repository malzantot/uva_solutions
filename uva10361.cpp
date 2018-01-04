/**
    Author: Moustafa Alzantot (malzantot@ucla.edu)
    All rights reserved.
**/

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::getline;
using std::endl;
using std::string;
using std::vector;

vector<string> TokenizeLine1(const string& line) {
  vector<string> tokens(5, "");
  int s1_end = line.find('<');
  int s2_end = line.find('>', s1_end+1);
  int s3_end = line.find('<', s2_end);
  int s4_end = line.find('>', s3_end);
  tokens[0] = line.substr(0, s1_end);
  tokens[1] = line.substr(s1_end+1, s2_end - s1_end - 1);
  tokens[2] = line.substr(s2_end+1, s3_end - s2_end - 1);
  tokens[3] = line.substr(s3_end+1, s4_end - s3_end - 1);
  tokens[4] = line.substr(s4_end + 1);
  return tokens;
}
int main() {
  int n;
  cin >> n;
  cin.get();
  for (int i = 0; i < n; ++i) {
    string line1, line2;
    getline(cin, line1);
    getline(cin, line2);
    vector<string> line1_tokens = TokenizeLine1(line1);
    cout << line1_tokens[0] << line1_tokens[1] << line1_tokens[2] <<
      line1_tokens[3] << line1_tokens[4] << endl;
    
    cout << line2.substr(0, line2.size()-3) <<
    line1_tokens[3] << line1_tokens[2] << line1_tokens[1]
      << line1_tokens[4] << endl;
  }
  return 0;
}
