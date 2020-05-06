// 0ms, 100.00%; 36.5MB, 5.13%
class Solution {
    public static String convertToTitle(int n) {
        StringBuilder sb = new StringBuilder();
        while (n > 0) {
            int x = (n - 1) % 26;
            sb.append((char) (x + 65));
            n = (n - x) / 26;
        }
        return sb.reverse().toString();
    }
}
