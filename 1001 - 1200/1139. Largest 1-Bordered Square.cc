// 32ms, 38.56%; 9.9MB, 100.00%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largest1BorderedSquare(const vector<vector<int>> &grid) {
        int row = grid.size(), col = grid[0].size();
        int res = min(row, col);
        while (res) {
            for (int i = 0, r = row - res + 1; i < r; ++i) {
                for (int j = 0, c = col - res + 1; j < c; ++j) {
                    if (check(grid, i, j, res)) return res * res;
                }
            }
            res -= 1;
        }
        return 0;
    }

private:
    bool check(const vector<vector<int>> &grid, int x, int y, int v) {
        if (v == 1) return grid[x][y] == 1;
        for (int i = 1; i < v; ++i)
            if (grid[x][y++] == 0) return false;
        for (int i = 1; i < v; ++i)
            if (grid[x++][y] == 0) return false;
        for (int i = 1; i < v; ++i)
            if (grid[x][y--] == 0) return false;
        for (int i = 1; i < v; ++i)
            if (grid[x--][y] == 0) return false;
        return true;
    }
};
