// 140ms, 18.87%; 39.1MB, 100.00%
class Solution
{
private:
    const int delta[16] = { -1, -1, -1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1 };

public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        if (grid[0][0] || grid.back().back()) return -1;
        int row = grid.size(), col = grid[0].size();
        grid.back().back() = -1;

        int count = 1;
        set<pair<int, int>> s;
        s.emplace(0, 0);
        while (!s.empty()) {
            for (auto &p : s) grid[p.first][p.second] = count;
            count += 1;
            set<pair<int, int>> tmp;
            for (auto &p : s) {
                for (int i = 0; i < 16; i += 2) {
                    int x = p.first + delta[i], y = p.second + delta[i + 1];
                    if (x < 0 || y < 0 || x == row || y == row || grid[x][y] > 0) continue;
                    tmp.emplace(x, y);
                }
            }
            s = move(tmp);
        }
        return grid.back().back();
    }
};
