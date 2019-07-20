// 4ms, 96.38%; 10MB, 62.89%
auto _ = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
public:
    int nthUglyNumber(int n)
    {
        vector<int> res = { 1 };
        res.resize(n);
        int t1 = 0, t2 = 0, t3 = 0;
        for (int i = 1; i < n; ++i) {
            res[i] = min({ 2 * res[t1], 3 * res[t2], 5 * res[t3] });
            if (res[i] == 2 * res[t1]) ++t1;
            if (res[i] == 3 * res[t2]) ++t2;
            if (res[i] == 5 * res[t3]) ++t3;
        }
        return res.back();
    }
};
