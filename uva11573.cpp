/**
    Author: Moustafa Alzantot (malzantot@ucla.edu)
    All rights reserved.
**/
#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using std::cin;
using std::cout;
using std::endl;
using std::greater;
using std::priority_queue;
using std::vector;

inline bool IsValid(int x, int y, int n, int m) {
  return (x >= 0 & x < n && y >= 0 && y <m);
}

class Location {
  public:
  int x, y;
  int cost;
  Location(int xx, int yy) : x(xx), y(yy), cost(0) {
  }
  Location(int xx, int yy, int c) : x(xx), y(yy), cost(c) {
  }
  friend bool operator>(const Location& lhs, const Location& rhs);
  friend bool operator==(const Location& lhs, const Location& rhs);
};

bool operator>(const Location& lhs, const Location& rhs) {
  return lhs.cost > rhs.cost;
}

bool operator==(const Location& lhs, const Location& rhs) {
  return lhs.x == rhs.x && lhs.y == rhs.y;
}

int solve(const vector<vector<int>>& grid, int s_x, int s_y,
    int d_x, int d_y) {
  const int r = grid.size();
  const int c = grid[0].size();
  priority_queue<Location, vector<Location>, greater<Location>> q;
  q.push(Location(s_x, s_y));
  Location target(d_x, d_y);
  int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
  int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
  vector<vector<int>> dist(r, vector<int>(c, 100000));
  dist[s_x][s_y] = 0.0;
  while (!q.empty()) {
    Location top = q.top();
    dist[top.x][top.y] = top.cost;
    q.pop();
    if (top == target) {
      return top.cost;
    }
    for (int k = 0; k < 8; k++) {
      int n_x = top.x + dx[k];
      int n_y = top.y + dy[k];
      int new_cost;
      if (IsValid(n_x, n_y, r, c)) {
        if (dist[n_x][n_y] != 100000) continue;
        if (k == grid[top.x][top.y]) {
          new_cost = top.cost;
        } else {
          new_cost = top.cost + 1;
        }
        Location newLocation(n_x, n_y, new_cost);
        q.push(newLocation);
      }
    }
  }
  return 0;
}

int main() {
  int r, c;
  cin >> r >> c;
  vector<vector<int>> grid(r, vector<int>(c));
  cin.get();
  char ch;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      ch = cin.get();
      grid[i][j] = static_cast<int>(ch-'0');
    }
    cin.get();
  }
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int s_x, s_y, d_x, d_y;
    cin >> s_x >> s_y >> d_x >> d_y;
    s_x--; s_y--; d_x--; d_y--;
    cout << solve(grid, s_x, s_y, d_x, d_y) << endl;
  }

  return 0;
}
