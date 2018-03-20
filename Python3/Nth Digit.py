# 40ms, 93.20%
class Solution:
    def findNthDigit(self, n):
        base, digits = 9, 1
        while n > base * digits:
            n -= base * digits
            base *= 10
            digits += 1
        index = n % digits
        num = 10 ** (digits - 1) + n // digits
        if index == 0:
            num -= 1
            index = digits
        for _ in range(index, digits):
            num //= 10
        return num % 10
    
