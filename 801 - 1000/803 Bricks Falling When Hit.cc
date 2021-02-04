// 125ms
class Solution {
private:
    int m, n;
    
public:
    vector<int> hitBricks(vector<vector<int>> &grid, vector<vector<int>> &hits) {
        m = grid.size(), n = grid[0].size();
        int h = hits.size();
        auto l = [&] (int x, int y) {
            return x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 2;
        };
        
        for (auto h : hits)
            grid[h[0]][h[1]] -= 1;
        for (int j = 0; j < n; ++j)
            dfs(grid, 0, j);
        vector<int> res(h, 0);
        for (int k = h - 1; k >= 0; --k) {
            int i = hits[k][0];
            int j = hits[k][1];
            grid[i][j] += 1;
            if (grid[i][j] == 1 && 
                (i == 0 || l(i - 1, j) || l(i + 1, j) || l(i, j - 1) || l(i, j + 1)))
                res[k] = dfs(grid, i, j) - 1;
        }
        return res;
    }

private:
    int dfs(vector<vector<int>> &grid, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1)
            return 0;
        grid[i][j] = 2;
        return 1 + dfs(grid, i - 1, j) + dfs(grid, i + 1, j) + 
            dfs(grid, i, j - 1) + dfs(grid, i, j + 1);
    }
};
