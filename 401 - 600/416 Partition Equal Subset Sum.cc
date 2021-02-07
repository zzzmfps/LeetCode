// 22ms, 81.68%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition(const vector<int> &nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) return false;
        sum >>= 1;
        // bool dp[sum + 1] = {1};    // valid in C99 standard
        bool *dp = new bool[sum + 1](); // add '()' to initialize
        dp[0] = true;
        for (auto n : nums)
            for (int i = sum; i >= n; --i) dp[i] |= dp[i - n];
        return dp[sum];
    }
};
