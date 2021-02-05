// 12 ms, 18.55%; 7.6 MB, 51.75%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDistinct(const string &s, const string &t) const {
        int x = t.size(), y = s.size();
        vector<vector<long>> dp = vector<vector<long>>(1 + x, vector<long>(1 + y));
        for (int j = 0; j < y; ++j) dp[0][j] = 1;
        for (int i = 1; i <= x; ++i) {
            for (int j = 1; j <= y; ++j) {
                dp[i][j] = (t[i - 1] == s[j - 1]) ? dp[i - 1][j - 1] : 0;
                dp[i][j] += dp[i][j - 1];
            }
        }
        return dp[x][y];
    }
};
