// 1ms, 99.87%; 41.8MB, 68.38%
class Solution {
    public int majorityElement(int[] nums) {
        int res = nums[0], count = 1;
        for (int i = 1; i < nums.length; ++i) {
            count += (nums[i] == res ? 1 : -1);
            if (count == 0) {
                res = nums[i];
                count = 1;
            }
        }
        return res;
    }
}
