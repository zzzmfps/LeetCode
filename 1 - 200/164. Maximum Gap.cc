// 6ms, 100.0%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int maximumGap(vector<int> &nums) {
        if (nums.empty() || nums.size() < 2) return 0;
        sort(nums.begin(), nums.end());
        int size = nums.size(), maxGap = 0;
        for (int i = 1; i < size; ++i) maxGap = max(maxGap, nums[i] - nums[i - 1]);
        return maxGap;
    }
};
