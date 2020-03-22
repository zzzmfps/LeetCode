// 1ms, 88.15%; 41.8MB, 5.16%
class Solution {
    public int maxSubArray(int[] nums) {
        int res = Integer.MIN_VALUE, cur = 0;
        for (int n : nums) {
            cur = n + (cur > 0 ? cur : 0);
            res = Integer.max(res, cur);
        }
        return res;
    }
}
