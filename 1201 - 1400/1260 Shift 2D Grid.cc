// 68ms, 76.12%; 13.5MB, 100.00%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(const vector<vector<int>> &grid, int k) {
        int row = grid.size(), col = grid[0].size();
        if ((k %= row * col) == 0) return grid;
        vector<vector<int>> res(row, vector<int>(col));
        int gi = 0, gj = 0, ri = k / col, rj = k % col;
        while (ri < row) {
            res[ri][rj++] = grid[gi][gj++];
            if (gj == col) gi += 1, gj = 0;
            if (rj == col) ri += 1, rj = 0;
        }
        ri = 0;
        while (gi < row) {
            res[ri][rj++] = grid[gi][gj++];
            if (gj == col) gi += 1, gj = 0;
            if (rj == col) ri += 1, rj = 0;
        }
        return res;
    }
};
