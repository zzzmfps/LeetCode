// 0ms, 100.00%; 38.1MB, 5.05%
class Solution {
    public int removeElement(int[] nums, int val) {
        int length = 0;
        for (int i = 0; i < nums.length; ++i) {
            if (nums[i] != val) {
                nums[length++] = nums[i];
            }
        }
        return length;
    }
}
