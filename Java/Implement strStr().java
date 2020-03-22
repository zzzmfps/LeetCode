// 3ms, 30.21%; 39.5MB, 6.10%
class Solution {
    public int strStr(String haystack, String needle) {
        if (needle.isEmpty()) {
            return 0;
        }
        if (haystack.length() < needle.length()) {
            return -1;
        }
        for (int i = 0; i < haystack.length() - needle.length() + 1; ++i) {
            boolean flag = true;
            for (int j = 0; j < needle.length(); ++j) {
                if (needle.charAt(j) != haystack.charAt(i + j)) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                return i;
            }
        }
        return -1;
    }
}
