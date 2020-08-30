// 0ms, 100.00%; 36.8MB, 5.41%
public class Solution {
    private static final int[] digits = { 0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4 };

    // you need to treat n as an unsigned value
    public static int hammingWeight(int n) {
        int ret = (n < 0 ? 1 : 0);
        if (n < 0) {
            n = Integer.MAX_VALUE + n + 1;
        }
        for (; n > 0; n >>= 4) {
            ret += digits[n & 0xf];
        }
        return ret;
    }
}
