// 1ms, 100.00%; 36.4MB, 5.00%
class Solution {
    public static int mySqrt(int x) {
        if (x < 2) {
            return x;
        }
        int cur = (x >> 1), next;
        while (cur > (next = (cur + x / cur) >> 1)) {
            cur = next;
        }
        return cur;
    }
}
