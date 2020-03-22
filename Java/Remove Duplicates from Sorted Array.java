// 0ms, 100.00%; 41.5MB, 17.02%
class Solution {
    public int removeDuplicates(int[] nums) {
        int last = Integer.MIN_VALUE, j = 0;
        for (int i = 0; i < nums.length; ++i) {
            if (last != nums[i]) {
                nums[j++] = nums[i];
                last = nums[i];
            }
        }
        return j;
    }
}
