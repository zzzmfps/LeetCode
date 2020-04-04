// 0ms, 100.00%; 36.3MB, 5.26%
class Solution {
    public static int climbStairs(int n) {
        if (n < 4) {
            return n;
        }
        int a = 2, b = 3;
        for (int i = 3; i < n; ++i) {
            int tmp = b;
            b += a;
            a = tmp;
        }
        return b;
    }
}
