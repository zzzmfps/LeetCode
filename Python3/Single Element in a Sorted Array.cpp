# 36ms, 78.76%; 14MB, 6.00%
class Solution:
    def singleNonDuplicate(self, nums: list) -> int:
        res = 0
        for n in nums:
            res ^= n
        return res
