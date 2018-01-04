/**
    Author: Moustafa Alzantot (malzantot@ucla.edu)
    All rights reserved.
**/
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

inline bool MatchChar(char ch1, char ch2) {
  return toupper(ch1) == toupper(ch2);
}

inline bool MatchWord(const vector<string>& grid, const string& word,
  int y, int x) {
  const int word_sz = word.size();
  const int m = grid.size();
  const int n = grid[0].size();
  int dx[] = {-1,-1,0,1,1,1,0,-1};
  int dy[] = {0,-1,-1,-1,0,1,1,1};
  for (int k = 0; k < 8; k++) {
    int pos = 0;
    for (pos = 0; pos < word_sz; pos++) {
      int cur_x = x + pos * dx[k];
      int cur_y = y + pos * dy[k];
      if (cur_x < 0 || cur_x >= n || cur_y < 0 || cur_y >= m) break;
      if (!MatchChar(grid[cur_y][cur_x],word[pos])) break;
    }
    if (pos == word_sz) { return true; }
  }
  return false;
}

int main() {
  int num_cases;
  int m, n, k;
  cin >> num_cases;

  for (int case_index = 0; case_index < num_cases; ++case_index) {
    if (case_index) cout << endl;
    cin >> m >> n;
    vector<string> grid(m);
    for (int i = 0; i < m; i++) {
      cin >> grid[i];
    }
    cin >> k;
    vector<string> words(k);
    for (int i = 0; i < k; i++) {
      cin >> words[i];
    }
    // do the sarch
    for (const string& w: words) {
      bool found = false;
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
          if (MatchWord(grid, w, i, j)) {
            cout << (i+1) << " " << (j+1) << endl;
            found = true;
            break;
          }
        }
        if (found) break;
      }
      //assert(found);
      if (!found) { cout << "0 0" << endl; }
    }
  }
  
  return 0;
}
