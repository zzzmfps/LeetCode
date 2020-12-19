// 28ms, 99.56%; 9.8MB, 100.00%
static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
public:
    int smallestRangeII(vector<int> &A, int K)
    {
        sort(A.begin(), A.end());
        int _min = A[0], _max = A.back(), ret = _max - _min;
        for (int i = 0, size = A.size() - 1; i < size; ++i) {
            _max = max(A.back(), A[i] + 2 * K);
            _min = min(A[i + 1], A[0] + 2 * K);
            ret = min(ret, _max - _min);
        }
        return ret;
    }
};
