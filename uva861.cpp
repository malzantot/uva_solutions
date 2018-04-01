/**
    Author: Moustafa Alzantot (malzantot@ucla.edu)
    All rights reserved.
**/
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;



int CountBishopsRec(vector<int> sol, int cur_diag,
  int n, int k) {
  if (sol.size() == k) return 1;
  if (cur_diag >= 2 * n -1) return 0;
  
  int count = 0;
  count += CountBishopsRec(sol, cur_diag+2, n, k);
  for (int x = 0; x < n; x++) {
    int y = cur_diag - x;
    if (y >= n || y < 0) continue;
    // Check a conflict.
    int d2 = n - 1 + x - y;
    bool valid = true;
    for (int j = 0; j < sol.size(); j++)
      if (sol[j] == d2) { valid = false; break; }
    if (valid) {
      sol.push_back(d2);
      count += CountBishopsRec(sol, cur_diag+2, n, k);
      sol.pop_back();
    }
  }
  return count;
}


int CountBishops(int n, int k, vector<vector<int>>& black,
        vector<vector<int>>& white) {
  int count = 0;
  for (int i = 0; i <= k; i++) {
    count += black[n][i] * white[n][k-i];
  }
  return count;
}
int main() {

  int n, k;
  vector<vector<int> > black_sol(9);
  vector<vector<int> > white_sol(9);


  for (int i = 1; i < 9; i++) {
    //black_sol[i].push_back(vector<int>(i*i+1));
    //white_sol[i].push_back(vector<int>(i*i+1));
    black_sol[i].resize(i*i+1);
    white_sol[i].resize(i*i+1);
      vector<int> sol;
    for (int j = 0; j <= i * i; j++) {
        black_sol[i][j] = CountBishopsRec(sol, 0, i, j);
        white_sol[i][j] = CountBishopsRec(sol, 1, i, j);
    }
  }

  while (cin >> n >> k && n) {
    int sol = CountBishops(n, k, black_sol, white_sol);
    cout << sol << endl;
  }
  return 0;
}
