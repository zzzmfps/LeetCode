// 4ms, 99.05%; 9.4MB, 41.49%
auto x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
public:
    int projectionArea(const vector<vector<int>> &grid)
    {
        int res = 0;
        for (const auto &x : grid) {
            int tmp = 0;
            for (auto y : x) {
                if (y) {
                    res += 1;
                    tmp = max(tmp, y);
                }
            }
            res += tmp;
        }
        for (int i = 0, size = grid.size(); i < size; ++i) {
            int tmp = 0;
            for (const auto &x : grid) {
                tmp = max(tmp, x[i]);
            }
            res += tmp;
        }
        return res;
    }
};
