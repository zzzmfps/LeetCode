// 76ms, 48.94%; 16.1MB, 100.00%
class Solution
{
public:
    int islandPerimeter(const vector<vector<int>> &grid)
    {
        int ret = 0;
        for (int i = 0, row = grid.size(); i < row; ++i) {
            for (int j = 0, col = grid[0].size(); j < col; ++j) {
                if (grid[i][j] == 0) continue;
                ret += 4;
                if (i > 0 && grid[i - 1][j] == 1) ret -= 2;
                if (j > 0 && grid[i][j - 1] == 1) ret -= 2;
            }
        }
        return ret;
    }
};
