// 28ms, 100.00%; 12.9MB, 94.44%
static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
public:
    int maxSubarraySumCircular(const vector<int> &A)
    {
        int dp_min, dp_max, all_min, all_max;
        dp_min = dp_max = all_min = all_max = A[0];
        for (int i = 1, size = A.size(); i < size; ++i) {
            dp_min = A[i] + min(0, dp_min);
            dp_max = A[i] + max(0, dp_max);
            if (dp_min < all_min) all_min = dp_min;
            if (dp_max > all_max) all_max = dp_max;
        }
        return (all_max > 0) ? max(accumulate(A.begin(), A.end(), 0) - all_min, all_max) : all_max;
    }
};
