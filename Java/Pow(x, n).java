// 1ms, 66.84%; 40.3MB, 5.01%
class Solution {
    public double myPow(double x, int n) {
        if (n < 0) {
            return 1.0 / helper(x, Math.abs((long) n));
        }
        return helper(x, n);
    }

    private double helper(double x, long n) {
        double ret = 1.0;
        if ((n & 1) == 1) {
            ret = x;
            --n;
        }
        return ret * (n == 0 ? 1.0 : n == 1 ? x : n == 2 ? x * x : helper(helper(x, n / 2), 2));
    }
}
