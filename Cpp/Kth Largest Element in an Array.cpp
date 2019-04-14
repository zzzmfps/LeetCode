// 4ms, 100.00%; 9.1MB, 99.68%
static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
public:
    int findKthLargest(const vector<int> &nums, int k)
    {
        auto p = minmax_element(nums.begin(), nums.end());
        int _min = *p.first, _max = *p.second, size = nums.size();
        if (k == 1) return _max;
        if (k == size) return _min;
        while (_min < _max) {
            int _mid = _min + (_max - _min) / 2;
            int lt = 0, le = 0;
            for (auto n : nums) {
                if (n >= _mid) {
                    le += 1;
                    if (n > _mid) lt += 1;
                }
            }
            if (lt < k && le >= k) return _mid;
            if (lt >= k) {
                _min = _mid + 1;
            } else {
                _max = _mid - 1;
            }
        }
        return _min;
    }
};
