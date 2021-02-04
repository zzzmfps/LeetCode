// 0ms, 100.00%; 8.2MB, 52.61%
auto x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
public:
    bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2)
    {
        auto l = [](int r1b, int r1e, int r2b, int r2e) {
            return r1b < r2e && r1e > r2b;
        };
        return l(rec1[0], rec1[2], rec2[0], rec2[2]) && l(rec1[1], rec1[3], rec2[1], rec2[3]);
    }
};
