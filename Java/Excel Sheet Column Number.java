// 1ms, 100.00%; 37.9MB, 5.88%
class Solution {
    public static int titleToNumber(String s) {
        int ret = 0;
        for (int i = 0; i < s.length(); ++i) {
            ret = ret * 26 + s.charAt(i) - 64;
        }
        return ret;
    }
}
