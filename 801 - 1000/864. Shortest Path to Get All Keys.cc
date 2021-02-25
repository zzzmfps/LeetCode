// 128 ms, 44.96%; 22.6 MB, 40.31%
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int row, col;
    bool hasKey[6];
    int res;

public:
    int shortestPathAllKeys(const vector<string> &grid) {
        this->row = grid.size(), this->col = grid[0].size();
        fill_n(this->hasKey, 6, false);
        this->res = INT_MAX;

        int count = 0, x, y;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (64 == grid[i][j]) {
                    x = i, y = j;
                } else {
                    count += (grid[i][j] > 96);
                }
            }
        }

        this->dfs(grid, x, y, count, 0);
        return INT_MAX == this->res ? -1 : this->res;
    }

private:
    void dfs(const vector<string> &grid, int x, int y, int left, int dist) {
        if (dist >= this->res) return;
        if (0 == left) {
            res = min(res, dist);
            return;
        }
        auto options = this->bfs(grid, x, y, left);
        for (auto &&opt : options) {
            auto [d, c1, c2] = opt;
            this->hasKey[grid[c1][c2] - 97] = true;
            this->dfs(grid, c1, c2, left - 1, dist + d);
            this->hasKey[grid[c1][c2] - 97] = false;
        }
    }

    vector<tuple<int, int, int>> bfs(const vector<string> &grid, int x, int y, int left) {
        vector<vector<bool>> visited(this->row, vector<bool>(this->col));
        visited[x][y] = true;
        queue<pair<int, int>> q;
        q.emplace(x, y);

        auto check = [&](int c1, int c2) -> bool {
            if (c1 < 0 || c2 < 0 || c1 == this->row || c2 == this->col) return false;
            if (visited[c1][c2]) return false;
            int c = grid[c1][c2];
            if (35 == c || c > 64 && c < 71 && !hasKey[c - 65]) return false;
            return true;
        };
        auto push = [&](int c1, int c2) -> void {
            q.emplace(c1, c2);
            visited[c1][c2] = true;
        };

        vector<tuple<int, int, int>> ret;
        for (int i = 0; ret.size() < left && !q.empty(); ++i) {
            for (int j = q.size(); j > 0; --j) {
                int c1 = q.front().first, c2 = q.front().second, c3 = grid[c1][c2];
                q.pop();
                if (check(c1 - 1, c2)) push(c1 - 1, c2);
                if (check(c1 + 1, c2)) push(c1 + 1, c2);
                if (check(c1, c2 - 1)) push(c1, c2 - 1);
                if (check(c1, c2 + 1)) push(c1, c2 + 1);
                if (c3 > 96 && !this->hasKey[c3 - 97]) ret.emplace_back(i, c1, c2);
            }
        }
        return ret;
    }
};
