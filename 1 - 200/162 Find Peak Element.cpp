// 8ms, 52.73%; 8.5MB, 95.45%
class Solution
{
public:
    int findPeakElement(const vector<int> &nums)
    {
        int size = nums.size();
        if (size == 1 || nums[0] > nums[1]) return 0;
        if (nums[size - 2] < nums[size - 1]) return size - 1;

        int left = 1, right = size - 1, mid;
        while (true) {
            mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) break;
            if (nums[mid] < nums[mid - 1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return mid;
    }
};
