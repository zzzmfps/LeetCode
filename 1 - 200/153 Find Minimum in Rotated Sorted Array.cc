// 0ms, 100.0%
static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
  public:
    int findMin(const vector<int> &nums)
    {
        if (nums.front() < nums.back()) return nums.front();
        int left = 0, right = nums.size() - 1, mid;
        while (right - left > 1) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[left]) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return nums[right];
    }
};
