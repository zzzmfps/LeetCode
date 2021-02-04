// 4ms, 99.94%; 11MB, 44.69%
auto x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int res = 0;
        for (int i = 0, row = grid.size(); i < row; ++i) {
            for (int j = 0, col = grid[0].size(); j < col; ++j) {
                if (grid[i][j] != '1') continue;
                ++res;
                visit(grid, i, j);
            }
        }
        return res;
    }

private:
    void visit(vector<vector<char>> &grid, int i, int j)
    {
        grid[i][j] = '2';
        if (i > 0 && grid[i - 1][j] == '1') visit(grid, i - 1, j);
        if (j > 0 && grid[i][j - 1] == '1') visit(grid, i, j - 1);
        if (i + 1 < grid.size() && grid[i + 1][j] == '1') visit(grid, i + 1, j);
        if (j + 1 < grid[0].size() && grid[i][j + 1] == '1') visit(grid, i, j + 1);
    }
};
