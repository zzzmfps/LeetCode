// 1ms, 100.00%; 36.1MB, 99.31%
class Solution {
    public static int divide(int dividend, int divisor) {
        if (dividend == divisor) { // divisor will never be 0
            return 1;
        }
        if (dividend == 0 || divisor == Integer.MIN_VALUE) {
            return 0;
        }
        if (dividend == Integer.MIN_VALUE && divisor == -1) {
            return Integer.MAX_VALUE;
        }
        boolean negative = ((dividend < 0) ^ (divisor < 0));
        dividend = (dividend < 0 ? dividend : -dividend);
        divisor = (divisor < 0 ? divisor : -divisor);

        int res = 0, exp = maxExp(dividend, divisor);
        while (dividend <= divisor) {
            res += (1 << exp);
            dividend -= (divisor << exp);
            while (exp > 0 && dividend > (divisor << exp)) {
                exp -= 1;
            }
        }
        return (negative ? -1 : 1) * res;
    }

    private static int maxExp(int dividend, int divisor) {
        int maxLimit = Math.max(-1073741825, dividend);
        int count = 0;
        while (maxLimit < divisor) {
            divisor <<= 1;
            count += 1;
        }
        return Math.max(0, count - 1);
    }
}
