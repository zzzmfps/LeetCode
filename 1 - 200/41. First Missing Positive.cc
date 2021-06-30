// 8ms, 6.04%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        if (nums.empty()) return 1;
        int end = nums.size(), i = 0;
        for (; i < end; ++i)
            while (nums[i] > 0 && nums[i] <= end && nums[nums[i] - 1] != nums[i]) swap(nums[i], nums[nums[i] - 1]);
        for (i = 0; i < end; ++i)
            if (nums[i] != i + 1) break;
        return i + 1;
    }
};
