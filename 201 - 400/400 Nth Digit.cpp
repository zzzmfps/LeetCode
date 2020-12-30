// 4ms, 58.82%
class Solution {
public:
    int findNthDigit(int n) {
        long base = 9, digits = 1;
        while (n > base * digits) {
            n -= base * digits;
            base *= 10;
            ++digits;
        }
        int index = n % digits;
        if (index == 0) index = digits;
        long num = pow(10, digits - 1);
        num += (index == digits) ? n / digits - 1 : n / digits;
        for (int i = index; i < digits; ++i)
            num /= 10;
        return num % 10;
    }
};
