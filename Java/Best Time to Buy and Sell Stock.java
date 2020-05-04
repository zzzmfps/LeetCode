// 1ms, 99.26%; 39.4MB, 22.56%
class Solution {
    public static int maxProfit(int[] prices) {
        int res = 0, min = Integer.MAX_VALUE;
        for (int val : prices) {
            if (val < min) {
                min = val;
            } else {
                res = Math.max(res, val - min);
            }
        }
        return res;
    }
}
