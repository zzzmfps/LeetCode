# 56ms, 95.16%
class Solution:
    def selfDividingNumbers(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: List[int]
        """
        res = []
        for i in range(left, right + 1):
            n = i
            while n:
                r = n % 10
                if r == 0 or i % r != 0: break
                n //= 10
            if n == 0: res.append(i)
        return res
    
