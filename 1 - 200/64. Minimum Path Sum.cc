// 8 ms, 94.94%; 9.9 MB, 71.53%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPathSum(const vector<vector<int>> &grid) {
        int row = grid.size(), col = grid[0].size();

        vector<int> pre(grid[0]);
        for (int i = 1; i < col; ++i) pre[i] += pre[i - 1];

        for (int i = 1; i < row; ++i) {
            vector<int> cur(grid[i]);
            cur[0] += pre[0];
            for (int j = 1; j < col; ++j) cur[j] += min(cur[j - 1], pre[j]);
            pre.swap(cur);
        }
        return pre[col - 1];
    }
};
