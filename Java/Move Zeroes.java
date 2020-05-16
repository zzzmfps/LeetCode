// 0ms, 100.00%; 39.7MB, 14.69%
class Solution {
    public static void moveZeroes(int[] nums) {
        int i = 0;
        for (int j = 1; j < nums.length; ++j) {
            if (nums[i] != 0) {
                ++i;
            } else if (nums[j] != 0) {
                nums[i++] = nums[j];
                nums[j] = 0;
            }
        }
    }
}
