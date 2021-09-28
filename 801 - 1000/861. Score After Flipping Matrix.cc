// 4 ms, 60.29%; 8.2 MB, 17.22%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int matrixScore(const vector<vector<int>> &grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        int row = grid.size(), col = grid[0].size(), length = row + col;
        bool *rotated = new bool[length]{};

        while (true) {
            bool flag = true;
            for (int i = 0; i < length; ++i) {
                if (rotated[i]) continue;
                if (!this->check(grid, rotated, i)) continue;
                flag = false;
                rotated[i] = true;
            }
            if (flag) break;
        }

        int res = 0;
        for (int i = 0; i < row; ++i) {
            int r = 0;
            for (int j = 0; j < col; ++j) {
                r = (r << 1) | (grid[i][j] ^ rotated[i] ^ rotated[row + j]);
            }
            res += r;
        }

        delete[] rotated;
        return res;
    }

private:
    bool check(const vector<vector<int>> &grid, bool *rotated, int i) {
        int row = grid.size();
        if (i < row) return 0 == (grid[i][0] ^ rotated[i] ^ rotated[row]);

        int col = grid[0].size();
        int x = -1, y = i - row, count = 0;
        while (++x < row) {
            count += (grid[x][y] ^ rotated[x] ^ rotated[i]);
        }
        return count * 2 < row;
    }
};
