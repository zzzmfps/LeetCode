# 72ms, 84.14%; 13.4MB, 6.5%
class Solution:
    def findMaxConsecutiveOnes(self, nums: list) -> int:
        res = tmp = 0
        for n in nums:
            if n == 0:
                res = max(res, tmp)
                tmp = 0
            else:
                tmp += 1
        return max(res, tmp)
