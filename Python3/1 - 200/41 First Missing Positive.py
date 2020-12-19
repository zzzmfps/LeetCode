# 44ms, 82.19%
class Solution:
    def firstMissingPositive(self, nums):
        record, res = 0, 1
        for n in nums:
            if n > 0: record |= 1 << (n - 1)
        while record:
            if record & 1 == 0: return res
            res += 1
            record >>= 1
        return res
        
