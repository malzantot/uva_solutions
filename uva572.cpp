#include <iostream>
#include <string>
#include <vector>


using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::vector;

void FloodFill(vector<string>& grid, int x, int y) {
    const int m = grid.size();
    const int n = grid[0].size();
    grid[x][y] = '*';
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int k = 0; k < 8; k++) {
        int n_x = x+dx[k];
        int n_y = y+dy[k];
        if (n_x >= 0 && n_y >= 0 && n_x < m && n_y < n)
            if (grid[n_x][n_y] == '@')
                FloodFill(grid, x+dx[k], y+dy[k]);
    }
}

int main() {
    int m, n;
    while (cin>>m>>n && m) {
        cin.get();
        vector<string> grid(m);
        for (int i = 0; i < m; i++) {
            getline(cin, grid[i]);
        }
        int num_deposits = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '@') {
                    num_deposits++;
                    FloodFill(grid, i, j);
                }
            }
        }
        cout << num_deposits << endl;
    }
    return 0;
}

