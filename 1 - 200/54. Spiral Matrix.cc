// 4ms, 0.36%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(const vector<vector<int>> &matrix) {
        if (matrix.empty()) return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<int> spiral(m * n);
        int u = 0, r = n - 1, d = m - 1, l = 0, k = 0;
        while (true) {
            for (int col = l; col <= r; ++col) spiral[k++] = matrix[u][col]; // up
            if (++u > d) break;
            for (int row = u; row <= d; ++row) spiral[k++] = matrix[row][r]; // right
            if (--r < l) break;
            for (int col = r; col >= l; --col) spiral[k++] = matrix[d][col]; // down
            if (--d < u) break;
            for (int row = d; row >= u; --row) spiral[k++] = matrix[row][l]; // left
            if (++l > r) break;
        }
        return spiral;
    }
};
