// 0ms, 100.00%; 41MB, 5.41%
class Solution {
    public int searchInsert(int[] nums, int target) {
        /* find first element that >= target */
        int left = 0, right = nums.length;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
}
