// 8ms, 71.54%; 9.2MB, 93.14%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(const vector<int> &nums) {
        int tmp = nums[0], res = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            tmp = (tmp > 0 ? tmp + nums[i] : nums[i]);
            if (tmp > res) res = tmp;
        }
        return res;
    }
};
