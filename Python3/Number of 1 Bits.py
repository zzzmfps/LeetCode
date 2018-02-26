# 36ms, 45.97%
class Solution:
    def hammingWeight(self, n):
        count = 0
        while n:
            n &= n - 1
            count += 1
        return count
        '''
        ### 37ms, 45.97%
        count = 0
        while n:
            count += n & 1
            n >>= 1
        return count
        '''
