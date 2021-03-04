// 4 ms, 79.48%; 6 MB, 82.42%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        vector<int> grid(n);
        return this->dfs(grid, n, n - 1);
    }

private:
    int dfs(vector<int> &grid, int n, int row) {
        if (row < 0) {
            return 1;
        }
        int count = 0;
        for (int i = 0; i < n; ++i) {
            int place = 1 << i;
            bool repeat = false;
            for (int j = row + 1; !repeat && j < n; ++j) {
                int x = place << (j - row), y = place >> (j - row);
                repeat = (place == grid[j] || x == grid[j] || y == grid[j]);
            }
            if (repeat) continue;
            grid[row] = place;
            count += this->dfs(grid, n, row - 1);
        }
        return count;
    }
};
