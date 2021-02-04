// 34ms, 86.55%
static int x = []() {
    ios_base::sync_with_stdio(false); // toggles off the synchronization
    cin.tie(nullptr);                 // ties cin with nullptr, not cout
    return 0;
}();

class Solution
{
  public:
    int findNumberOfLIS(const vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        int size = nums.size(), *dp[2];
        dp[0] = new int[size], dp[1] = new int[size];
        fill_n(dp[0], size, 1), fill_n(dp[1], size, 1);

        int max_for_all = 1, res = 0;
        for (int i = 0; i < size; ++i)
        {
            int max_len = 1, count = 0;
            for (int j = 0; j < i; ++j)
                if (nums[i] > nums[j])
                    if (max_len == dp[0][j] + 1)
                        count += dp[1][j];
                    else if (max_len < dp[0][j] + 1)
                    {
                        max_len = dp[0][j] + 1;
                        count = dp[1][j];
                    }
            dp[0][i] = max_len, dp[1][i] = count > dp[1][i] ? count : dp[1][i];
            max_for_all = max_len > max_for_all ? max_len : max_for_all;
        }

        for (int i = 0; i < size; ++i)
            if (dp[0][i] == max_for_all)
                res += dp[1][i];
        delete[] dp[0], delete[] dp[1];
        return res;
    }
};
