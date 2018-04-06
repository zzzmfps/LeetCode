// 22ms, 81.68%
class Solution {
public:
    bool canPartition(const vector<int> &nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) return false;
        sum >>= 1;
        bool dp[sum + 1] = {1};
        for (auto n : nums)
            for (int i = sum; i >= n; --i)
                dp[i] |= dp[i - n];
        return dp[sum];
    }
};
