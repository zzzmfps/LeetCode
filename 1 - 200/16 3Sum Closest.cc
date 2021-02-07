// 15ms, 14.58%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size() - 1;
        if (nums[0] >= target && nums[0] >= 0) return nums[0] + nums[1] + nums[2];
        if (nums[n] <= target && nums[n] <= 0) return nums[n] + nums[n - 1] + nums[n - 2];

        int ans = nums[0] + nums[1] + nums[2];
        int dev = target - ans;
        for (int i = 0; i < n - 1; ++i) {
            int left = i + 1;
            int right = n;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                int tmp = target - sum;
                if (tmp > 0)
                    ++left;
                else if (tmp < 0)
                    --right;
                else
                    return target;
                if (abs(tmp) < abs(dev)) dev = tmp, ans = sum;
            }
        }
        return ans;
    }
};
