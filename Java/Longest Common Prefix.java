// 0ms, 100.00%; 37.3MB, 99.42%
class Solution {
    public static String longestCommonPrefix(final String[] strs) {
        if (strs.length == 0) {
            return "";
        }
        int index = strs[0].length();
        for (String str : strs) {
            if (str.length() < index) {
                index = str.length();
            }
        }
        for (int i = 0, j; i < index; ++i) {
            for (j = 1; j < strs.length; ++j) {
                if (strs[0].charAt(i) != strs[j].charAt(i)) {
                    break;
                }
            }
            if (j < strs.length) {
                return strs[0].substring(0, i);
            }
        }
        return strs[0].substring(0, index);
    }
}
