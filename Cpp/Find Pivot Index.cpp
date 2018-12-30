// 8ms, 100.0%
static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
  public:
    int pivotIndex(const vector<int> &nums)
    {
        if (nums.empty()) return -1;
        int size = nums.size();
        vector<int> sums;
        sums.resize(size);
        sums[0] = nums[0];
        for (int i = 1; i < size; ++i) sums[i] = sums[i - 1] + nums[i];

        --size;
        if (sums.back() == sums.front()) return 0;
        for (int i = 1; i < size; ++i)
            if (sums.back() - sums[i] == sums[i - 1]) return i;
        if (sums[size - 1] == 0) return size;
        return -1;
    }
};
