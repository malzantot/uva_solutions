/**
    Author: Moustafa Alzantot (malzantot@ucla.edu)
    All rights reserved.
**/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::string;
using std::vector;

const string& kDoomedMsg = "Loowater is doomed!";

int main() {
  int n, m;
  while ((cin >> n >> m) && (n || m)) {
    vector<int> heads(n);
    for (int i = 0; i < n; i++)
      cin >> heads[i];
    vector<int> heights(m);
    for (int i = 0; i < m; i++) {
      cin >> heights[i];
    }
    int sum = 0;

    std::sort(heads.begin(), heads.end());
    std::sort(heights.begin(), heights.end());
    int height_idx = 0;
    int head_idx = 0;
    for (; head_idx < n; head_idx++) {
      while (height_idx < m && heights[height_idx] < heads[head_idx]) {
        height_idx++;
      }
      if (height_idx == m) { break; }
      else {
        sum += heights[height_idx];
        height_idx++;
      }
    }
    if (head_idx < n) {
      cout << kDoomedMsg << endl;
    } else {
      cout << sum << endl;
    }

  }
  return 0;
}
