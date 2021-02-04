// 4ms, 99.83%; 10MB, 42.82%
auto _ = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
public:
    int findDuplicate(const vector<int> &nums)
    {
        bool *tmp = new bool[nums.size()] {};
        for (auto n : nums) {
            if (tmp[n]) {
                delete[] tmp;
                return n;
            }
            tmp[n] = true;
        }
        return 0;
    }
};
