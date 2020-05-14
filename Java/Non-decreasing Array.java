// 1ms, 72.28%; 40.4MB, 100.00%
class Solution {
    public static boolean checkPossibility(int[] nums) {
        int count = 1;
        int[] prev = { Integer.MIN_VALUE, Integer.MIN_VALUE };
        for (int n : nums) {
            if (prev[1] > n) {
                if (count-- == 0) {
                    return false;
                }
                if (prev[0] <= n) {
                    prev[1] = n;
                }
            } else {
                prev[0] = prev[1];
                prev[1] = n;
            }
        }
        return true;
    }
}
