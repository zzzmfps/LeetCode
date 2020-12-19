# 52ms, 91.53%
class Solution:
    def plusOne(self, digits):
        i, is_carry = -1, False
        while i > -len(digits) - 1:
            if (i == -1 or is_carry) and digits[i] == 9:
                digits[i] = 0
                is_carry = True
                i -= 1
            else:
                digits[i] += 1
                return digits
        digits.insert(0, 1)
        return digits
        
