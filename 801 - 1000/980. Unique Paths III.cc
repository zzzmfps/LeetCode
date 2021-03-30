// 4 ms, 79.82%; 8.6 MB, 29.18%
#include <bits/stdc++.h>
using namespace std;

using Matrix = vector<vector<int>>;
using Point = pair<size_t, size_t>;

class Solution {
public:
    int uniquePathsIII(const Matrix &grid) {
        auto [length, start, end] = this->analyzeMatrix(grid);

        bool **visited = new bool *[grid.size()];
        for (size_t i = 0; i < grid.size(); ++i) visited[i] = new bool[grid[0].size()]{};
        visited[start.first][start.second] = true;
        int res = this->dfs(grid, visited, start, end, length);

        for (size_t i = 0; i < grid.size(); ++i) delete[] visited[i];
        delete[] visited;
        return res;
    }

private:
    tuple<size_t, Point, Point> analyzeMatrix(const Matrix &grid) {
        int left = 2;
        tuple<size_t, Point, Point> res;
        for (size_t i = 0; i < grid.size(); ++i) {
            for (size_t j = 0; j < grid[0].size(); ++j) {
                switch (grid[i][j]) {
                case 0: ++get<0>(res); break;
                case 1: get<1>(res) = make_pair(i, j); break;
                case 2: get<2>(res) = make_pair(i, j); break;
                }
            }
        }
        return res;
    }

    vector<Point> getNext(const Matrix &grid, bool **visited, const Point &p) {
        vector<Point> ret;
        auto [x, y] = p;
        if (x && !visited[x - 1][y] && -1 != grid[x - 1][y]) ret.emplace_back(x - 1, y);
        if (y && !visited[x][y - 1] && -1 != grid[x][y - 1]) ret.emplace_back(x, y - 1);
        if (x + 1 < grid.size() && !visited[x + 1][y] && -1 != grid[x + 1][y]) ret.emplace_back(x + 1, y);
        if (y + 1 < grid[0].size() && !visited[x][y + 1] && -1 != grid[x][y + 1]) ret.emplace_back(x, y + 1);
        return ret;
    };

    int dfs(const Matrix &grid, bool **visited, const Point &p, const Point &target, int leftLength) {
        if (p == target) return -1 == leftLength;
        int count = 0;
        for (auto &&_next : getNext(grid, visited, p)) {
            visited[_next.first][_next.second] = true;
            count += this->dfs(grid, visited, _next, target, leftLength - 1);
            visited[_next.first][_next.second] = false;
        }
        return count;
    };
};
