// 3ms, 100.00%; 41.1MB, 5.48%
class Solution {
    static public int romanToInt(String s) {
        int res = 0, last = 0;
        for (int i = s.length() - 1; i > -1; --i) {
            int tmp = getValue(s.charAt(i));
            // any reverse order, like 'IV', means `valueOf('V') - valueOf('I')`
            res += tmp * (tmp >= last ? 1 : -1);
            last = tmp;
        }
        return res;
    }

    final static private String order = "IVXLCDM";
    final static private int[] vals = { 1, 5, 10, 50, 100, 500, 1000 };

    static private int getValue(char c) {
        return vals[order.indexOf(c)];
    }
}
