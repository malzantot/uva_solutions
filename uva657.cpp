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

void FillDieNumber(vector<string>& grid, int x, int y) {
    const int h = grid.size();
    const int w = grid[0].size();
    if (x < 0 || y < 0 || x >= h || y >= w) return;
    if (grid[x][y] != 'X') return;
    grid[x][y] = '*';
    int dx[] = {-1, 0, 0, 1};
    int dy[] = {0, -1, 1, 0};
    for (int k = 0; k < 4; k++) {
       FillDieNumber(grid, x+dx[k], y+dy[k]); 
    }
}

/**
 * Reads the number of a die
 **/
void ReadDie(vector<string>& grid, int x, int y, int& current_die) {
    const int h = grid.size();
    const int w = grid[0].size();
    if (x < 0 || y < 0 || x >= h || y >= w) return;
    if (grid[x][y] == '.') return;
    if (grid[x][y] == 'X') {
        current_die++;
        FillDieNumber(grid, x, y);
    }
    grid[x][y] = '.';
    int dx[] = {-1, 0, 0, 1};
    int dy[] = {0, -1, 1, 0};
    for (int k = 0; k < 4; k++) {
       ReadDie(grid, x+dx[k], y+dy[k], current_die); 
    }

}

int main() {
    int w, h;
    int throw_number = 0;
    while (cin >> w >> h && w && h) {
        cin.get();
        throw_number++;
        vector<string> grid(h);
        for (int i = 0; i < h; i++)
        {
            getline(cin, grid[i]);
        }
        vector<int> result;
        for (int i = 0; i < h; i++) {
            for (int j =0; j < w; j++)
                if (grid[i][j] != '.') {
                    int current_die = 0;
                    ReadDie(grid, i, j, current_die);
                    result.push_back(current_die);
                }
        }
        sort(result.begin(), result.end());
        cout << "Throw " << throw_number << endl;
        for (int i = 0; i < result.size(); i++) {
            if (i) cout << " ";
            cout << result[i];
        }
        cout << endl;
        cout << endl;

    }
    return 0;
}
