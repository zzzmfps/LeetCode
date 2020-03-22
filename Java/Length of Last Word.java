// 0ms, 100.00%; 37.4MB, 18.18%
class Solution {
    public int lengthOfLastWord(String s) {
        int res = 0;
        for (int i = s.length() - 1; i > -1; --i) {
            if (s.charAt(i) == ' ') {
                if (res > 0) {
                    break;
                }
            } else {
                res += 1;
            }
        }
        return res;
    }
}
