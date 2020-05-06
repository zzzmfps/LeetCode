// 0ms, 100.00%; 36.8MB, 7.69%
class Solution {
    public int trailingZeroes(int n) {
        int ret = 0;
        while ((n /= 5) > 0) {
            ret += n;
        }
        return ret;
    }
}
