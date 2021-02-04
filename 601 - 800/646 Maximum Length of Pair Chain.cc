// 52ms, 92.65%; 17.1MB, 100.00%
class Solution
{
public:
    int findLongestChain(vector<vector<int>> &pairs)
    {
        auto cmp0 = [](const auto &x, const auto &y) { return x[0] < y[0]; };
        auto cmp1 = [](const auto &x, const auto &y) { return x[1] < y[1]; };

        sort(pairs.begin(), pairs.end(), cmp0);
        int length = pairs.size(), last = INT_MIN, idx = 0;
        int res = 0;
        while (true) {
            while (idx < length && pairs[idx][0] <= last) ++idx;
            if (idx == length) break;
            res += 1;
            auto it = min_element(pairs.begin() + idx, pairs.end(), cmp1);
            last = (*it)[1], idx = distance(pairs.begin(), it);
        }
        return res;
    }
};
