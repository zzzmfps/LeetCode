// 20ms, 79.79%; 17.5MB, 100.00%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kInversePairs(int n, int k) {
        int limit = n * (n - 1) / 2;
        if (k < 0 || k > limit) return 0;
        if (k * 2 > limit) k = limit - k;
        if (k == 0) return 1;
        if (k == 1) return n - 1;
        if (k == 2) return limit - 1;

        unsigned mod = 1e9 + 7;
        vector<unsigned> dp = {1, 1};
        for (int i = 3; i <= n; ++i) {
            int len1 = i * (i - 1) / 2, len2 = 1 + min(k, len1);
            vector<unsigned> cur(len2, 1);
            int j = 1, end2 = 1 + min(k, len1 / 2), end1 = min(1 + k, min(i, end2));
            for (; j < end1; ++j) cur[j] = (cur[j - 1] + dp[j]) % mod;
            for (; j < end2; ++j) cur[j] = (cur[j - 1] + dp[j] - dp[j - i] + mod) % mod;
            for (; j < len2; ++j) cur[j] = cur[len1 - j];
            dp.swap(cur);
        }
        return dp.back();
    }
};
