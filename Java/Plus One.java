// 0ms, 100.00%; 37.9MB, 5.64%
class Solution {
    public int[] plusOne(int[] digits) {
        int carry = 1;
        for (int i = digits.length - 1; i > -1; --i) {
            digits[i] += carry;
            if (digits[i] > 9) {
                digits[i] -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
        }
        if (carry == 0) {
            return digits;
        }
        int[] _new = new int[digits.length + 1];
        _new[0] = carry;
        System.arraycopy(digits, 0, _new, 1, digits.length);
        return _new;
    }
}
