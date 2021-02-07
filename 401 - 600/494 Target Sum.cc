// 8ms, 87.51%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTargetSumWays(const vector<int> &nums, int s) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return sum < s || (sum + s) & 1 ? 0 : subsetSum(nums, (sum + s) >> 1);
    }

private:
    int subsetSum(const vector<int> &nums, int s) {
        // int dp[s + 1] = {1};    // valid in C99 standard
        bool *dp = new bool[s + 1](); // add '()' to initialize
        dp[0] = true;
        for (auto n : nums)              // select n
            for (int i = s; i >= n; --i) // for each number i in [n, s]
                dp[i] += dp[i - n];      // dp[i] up to the state of dp[i - n]
        return dp[s];                    // (with addend n selected)
    }
};
