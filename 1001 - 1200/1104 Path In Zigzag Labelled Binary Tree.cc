// 0ms, 100.00%; 8.2MB, 100.00%
auto x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
public:
    vector<int> pathInZigZagTree(int label)
    {
        vector<int> res;
        while (label) {
            res.push_back(label);
            label /= 2;
        }
        reverse(res.begin(), res.end());
        for (int i = res.size() & 1, base = 1 + i; base <= res.back(); i += 2, base <<= 2)
            res[i] = base * 3 - 1 - res[i];
        return res;
    }
};
