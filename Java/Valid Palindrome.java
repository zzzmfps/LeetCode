// 2ms, 97.59%; 39.2MB, 27.68%
class Solution {
    public static boolean isPalindrome(String s) {
        for (int i = 0, j = s.length() - 1;; ++i, --j) {
            while (i < j && !Character.isLetterOrDigit(s.charAt(i))) {
                ++i;
            }
            while (i < j && !Character.isLetterOrDigit(s.charAt(j))) {
                --j;
            }
            if (i >= j) {
                break;
            }
            if ((s.charAt(i) | 0x20) != (s.charAt(j) | 0x20)) {
                return false;
            }
        }
        return true;
    }
}
