// 9ms, 98.61%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false); // toggles off the synchronization
    cin.tie(nullptr);                 // ties cin with nullptr, not cout
    return 0;
}();

class Solution {
public:
    int maxCoins(vector<int> &nums) {
        int *nums2 = new int[nums.size() + 2];
        int end = 1;
        for (auto n : nums)
            if (n) nums2[end++] = n;
        nums2[0] = nums2[end++] = 1;
        int **dp = new int *[end];
        for (int i = 0; i < end; ++i) dp[i] = new int[end]();

        for (int k = 2; k < end; ++k)
            for (int left = 0; left < end - k; ++left)
                for (int i = left + 1, right = left + k; i < right; ++i)
                    dp[left][right] =
                        max(dp[left][right], nums2[left] * nums2[i] * nums2[right] + dp[left][i] + dp[i][right]);
        int res = dp[0][end - 1];

        delete[] nums2;
        for (int i = 0; i < end; ++i) delete[] dp[i];
        delete[] dp;
        return res;
    }
};
