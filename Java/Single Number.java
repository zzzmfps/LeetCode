// 0ms, 100.00%; 40.6MB, 77.78%
class Solution {
    public static int singleNumber(int[] nums) {
        int ret = 0;
        for (int val : nums) {
            ret ^= val;
        }
        return ret;
    }
}
