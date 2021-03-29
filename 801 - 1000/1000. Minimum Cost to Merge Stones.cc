// 4 ms, 72.76%; 8.4 MB, 25.45%
#include <bits/stdc++.h>
using namespace std;

static constexpr int INF = 0x3f3f3f3f;

class Solution {
public:
    int mergeStones(vector<int> &stones, size_t k) {
        size_t n = stones.size();
        if ((n - 1) % (k - 1)) return -1;

        vector<int> sums(n + 1);
        for (size_t i = 0; i < n; ++i) sums[i + 1] = sums[i] + stones[i];

        vector<vector<int>> dp(n, vector<int>(n));
        for (size_t m = k; m <= n; ++m) {         // length
            for (size_t i = 0; i + m <= n; ++i) { // start
                size_t j = i + m - 1;             // end
                dp[i][j] = INF;
                for (size_t mid = i; mid < j; mid += k - 1) {
                    int tmp = dp[i][mid] + dp[mid + 1][j];
                    dp[i][j] = min(dp[i][j], tmp);
                }
                if (0 == (j - i) % (k - 1)) dp[i][j] += sums[j + 1] - sums[i];
            }
        }
        return dp[0][n - 1];
    }
};
