// 364 ms, 59.88%; 209.2 MB, 6.07%
#include <bits/stdc++.h>
using namespace std;

using Point = pair<size_t, size_t>;

class Solution {
public:
    bool containsCycle(const vector<vector<char>> &grid) {
        size_t row = grid.size(), col = grid[0].size();
        vector<vector<int>> dists(row, vector<int>(col, 0));

        auto check = [&](int x, int y, char c) -> bool {
            if (x < 0 || y < 0 || x == row || y == col) return false;
            return !dists[x][y] && c == grid[x][y];
        };

        for (size_t i = 0; i < row; ++i) {
            for (size_t j = 0, d = 1; j < col; ++j) {
                if (dists[i][j]) continue;
                queue<Point> q;
                q.emplace(i, j);
                while (!q.empty()) {
                    for (size_t k = q.size(); k > 0; --k) {
                        auto [x, y] = q.front();
                        if (d == dists[x][y]) return true; // reached by another way
                        dists[x][y] = d;
                        // emplacing duplicates means there's a loop
                        if (check(x - 1, y, grid[x][y])) q.emplace(x - 1, y);
                        if (check(x, y - 1, grid[x][y])) q.emplace(x, y - 1);
                        if (check(x + 1, y, grid[x][y])) q.emplace(x + 1, y);
                        if (check(x, y + 1, grid[x][y])) q.emplace(x, y + 1);
                        q.pop();
                    }
                    ++d;
                }
            }
        }
        return false;
    }
};
