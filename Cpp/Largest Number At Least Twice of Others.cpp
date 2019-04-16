// 4ms, 100.00%; 8.6MB, 100.00%
static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
public:
    int dominantIndex(const vector<int> &nums)
    {
        int size = nums.size();
        if (size == 1) return 0;
        int maxIdx = 0, second = 1;
        if (nums[0] < nums[1]) swap(maxIdx, second);
        for (int i = 2; i < size; ++i) {
            if (nums[i] > nums[maxIdx]) {
                second = maxIdx;
                maxIdx = i;
            } else if (nums[i] > nums[second]) {
                second = i;
            }
        }
        return (nums[maxIdx] >= 2 * nums[second]) ? maxIdx : -1;
    }
};
