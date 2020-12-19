# 76ms, 100.0%
class Solution:
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        nums, ops = [], []
        res, num, sign = 0, 0, 1
        for c in s:
            if c >= '0' and c <= '9':
                num = num * 10 + int(c)
            else:
                res += sign * num
                num = 0
                if c == '+':
                    sign = 1
                elif c == '-':
                    sign = -1
                elif c == '(':
                    nums.append(res)
                    ops.append(sign)
                    res, sign = 0, 1
                elif ops:
                    res = nums.pop() + ops.pop() * res
        return res + sign * num
    
