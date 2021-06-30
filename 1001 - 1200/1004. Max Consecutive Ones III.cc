// 52 ms, 76.68%; 60.2 MB, 5.01%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(const vector<int> &nums, int k) {
        vector<int> dp(nums.begin(), nums.end());
        if (k && 0 == dp[0]) --k, ++dp[0];
        for (size_t i = 1; i < dp.size(); ++i) {
            if (k && 0 == dp[i]) --k, ++dp[i];
            if (1 == dp[i]) {
                dp[i] += dp[i - 1];
            } else {
                int j = i - dp[i - 1];
                while (j < i && nums[j]) ++j;
                if (i != j) dp[i] = i - j;
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
