// 8ms, 100.0%; 10MB, 90.65%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int minFallingPathSum(const vector<vector<int>> &A) {
        vector<int> dp(A[0].begin(), A[0].end());
        int row = A.size(), col = A[0].size();
        for (int i = 1; i < row; ++i) {
            for (int j = 0, last = 100; j < col; ++j) {
                int tmp = dp[j];
                dp[j] = A[i][j] + min({last, dp[j], dp[min(j + 1, col - 1)]});
                last = tmp;
            }
        }
        return *min_element(dp.begin(), dp.end());
    }
};
