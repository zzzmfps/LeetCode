// 15ms, 26.32%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int> &nums) {
        if (nums.empty() || nums.size() == 1) return 0;
        int n = nums.size();
        int level = 0, currentMax = 0, i = 0, nextMax = 0;

        while (currentMax - i + 1 > 0) {
            ++level;
            for (; i <= currentMax; ++i) {
                nextMax = max(nextMax, nums[i] + i);
                if (nextMax >= n - 1) return level;
            }
            currentMax = nextMax;
        }
    }
};
