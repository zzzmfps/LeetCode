// 1ms, 100.00%; 37.9MB, 5.62%
class Solution {
    public static String addBinary(String a, String b) {
        StringBuilder sb = new StringBuilder();
        int i = a.length() - 1, j = b.length() - 1, carry = 0;
        while (i > -1 || j > -1) {
            if (i > -1) {
                carry += a.charAt(i--) - 48;
            }
            if (j > -1) {
                carry += b.charAt(j--) - 48;
            }
            sb.append(carry & 1);
            carry >>= 1;
        }
        if (carry == 1) {
            sb.append(carry);
        }
        return sb.reverse().toString();
    }
}
