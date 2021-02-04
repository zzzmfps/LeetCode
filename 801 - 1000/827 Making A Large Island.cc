// 20ms, 84.15%; 13.1MB, 60.78%
auto x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
public:
    int largestIsland(vector<vector<int>> &grid)
    {
        if (grid.empty()) return 0;
        int id = 2;
        unordered_map<int, int> area;
        area[0] = 0;
        for (int i = 0, row = grid.size(); i < row; ++i) {
            for (int j = 0, col = grid[0].size(); j < col; ++j) {
                if (grid[i][j] != 1) continue;
                area[id] = visit(grid, i, j, id);
                ++id;
            }
        }
        int maxArea = 0;
        for (int i = 0, row = grid.size(); i < row; ++i) {
            for (int j = 0, col = grid[0].size(); j < col; ++j) {
                if (grid[i][j] != 0) continue;
                set<int> tmp;
                if (i > 0) tmp.insert(grid[i - 1][j]);
                if (j > 0) tmp.insert(grid[i][j - 1]);
                if (i + 1 < grid.size()) tmp.insert(grid[i + 1][j]);
                if (j + 1 < grid[0].size()) tmp.insert(grid[i][j + 1]);
                int tmpArea = 1;
                for (auto x : tmp) tmpArea += area[x];
                maxArea = max(maxArea, tmpArea);
            }
        }
        return (maxArea ? maxArea : grid.size() * grid[0].size());
    }

private:
    int visit(vector<vector<int>> &grid, int i, int j, int id)
    {
        int ret = 1;
        grid[i][j] = id;
        if (i > 0 && grid[i - 1][j] == 1) ret += visit(grid, i - 1, j, id);
        if (j > 0 && grid[i][j - 1] == 1) ret += visit(grid, i, j - 1, id);
        if (i + 1 < grid.size() && grid[i + 1][j] == 1) ret += visit(grid, i + 1, j, id);
        if (j + 1 < grid[0].size() && grid[i][j + 1] == 1) ret += visit(grid, i, j + 1, id);
        return ret;
    }
};
