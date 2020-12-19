# 60ms, 80.08%
class Solution:
    def addStrings(self, num1, num2):
        if not num1: return num2
        if not num2: return num1
        
        len1, len2 = len(num1), len(num2)
        end = (len1 if len1 > len2 else len2) - 1
        dif = len1 - len2
        if dif < 0:
            num1 = '0' * (-dif) + num1
        else:
            num2 = '0' * dif + num2
        
        carry, res = 0, []
        for i in range(end + 1):
            tmp = ord(num1[end - i]) + ord(num2[end - i]) - 96 + carry
            if tmp > 9:
                tmp, carry = tmp - 10, 1
            else:
                carry = 0
            res.append(str(tmp))
        if carry: res.append(str('1'))
        return ''.join(res[::-1])
        
