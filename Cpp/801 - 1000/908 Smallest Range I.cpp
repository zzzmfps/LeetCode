// 12ms, 99.06%; 9.6MB, 100.00%
static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
public:
    int smallestRangeI(const vector<int> &A, int K)
    {
        auto p = minmax_element(A.begin(), A.end());
        return max(0, int(*p.second - *p.first - 2 * K));
    }
};
