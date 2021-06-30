// 4ms, 99.10%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false); // toggles off the synchronization
    cin.tie(nullptr);                 // ties cin with nullptr, not cout
    return 0;
}();

class Solution {
public:
    int uniquePathsWithObstacles(const vector<vector<int>> &obstacleGrid) {
        if (obstacleGrid[0][0]) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        int **paths = new int *[m];
        for (int i = 0; i < m; ++i) paths[i] = new int[n];

        paths[0][0] = 1;
        for (int i = 1; i < m; ++i) paths[i][0] = obstacleGrid[i][0] ? 0 : paths[i - 1][0];
        for (int j = 1; j < n; ++j) paths[0][j] = obstacleGrid[0][j] ? 0 : paths[0][j - 1];
        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j) paths[i][j] = obstacleGrid[i][j] ? 0 : paths[i - 1][j] + paths[i][j - 1];

        int res = paths[m - 1][n - 1];
        for (int i = 0; i < m; ++i) delete[] paths[i];
        delete[] paths;
        return res;
    }
};
