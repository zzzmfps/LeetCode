// 20ms, 94.19%; 10.4MB, 100.00%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalRectangle(const vector<vector<char>> &matrix) // dp
    {
        if (matrix.empty()) return 0;
        int row = matrix.size(), col = matrix[0].size();
        vector<int> left(col), right(col, col), height(col);
        int res = 0;
        for (int i = 0; i < row; ++i) {
            int cur_left = 0, cur_right = col;
            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] == '1') {
                    left[j] = max(left[j], cur_left);
                    height[j] += 1;
                } else {
                    left[j] = 0, cur_left = j + 1;
                    height[j] = 0;
                }
            }
            for (int j = col - 1; j > -1; --j) {
                if (matrix[i][j] == '1') {
                    right[j] = min(right[j], cur_right);
                    res = max(res, height[j] * (right[j] - left[j]));
                } else {
                    right[j] = col, cur_right = j;
                }
            }
        }
        return res;
    }
};
