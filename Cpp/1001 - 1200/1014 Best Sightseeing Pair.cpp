// 36ms, 98.87%; 15MB, 100.00%
static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
public:
    int maxScoreSightseeingPair(const vector<int> &A)
    {
        int i = 0, j = 1, size = A.size();
        vector<int> dp(size);
        dp[1] = A[0] + A[1] - 1;
        for (int k = 2; k < size; ++k) {
            int with_i = A[i] + i - k;
            int with_j = A[j] + j - k;
            dp[k] = max(dp[k - 1], A[k] + max(with_i, with_j));
            if (A[k] > with_i || A[k] > with_j) {
                if (with_i < with_j) i = j;
                j = k;
            }
        }
        return dp.back();
    }
};
