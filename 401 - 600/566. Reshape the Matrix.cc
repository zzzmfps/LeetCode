// 28ms, 99.20%; 11.6MB, 96.00%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(const vector<vector<int>> &nums, int r, int c) {
        int row = nums.size(), col = nums[0].size();
        if (row * col != r * c) return nums;
        vector<vector<int>> ret(r, vector<int>(c));
        int i = 0, j = 0;
        for (const auto &x : nums) {
            for (auto y : x) {
                ret[i][j++] = y;
                if (j == c) ++i, j = 0;
            }
        }
        return ret;
    }
};
