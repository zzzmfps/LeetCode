# 80ms, 95.65%
class Solution:
    def findTargetSumWays(self, nums, s):
        """
        :type nums: List[int]
        :type S: int
        :rtype: int
        """
        nsum = sum(nums)
        if nsum < s or (nsum + s) & 1: return 0
        nsum = (nsum + s) >> 1
        dp = [1] + [0] * nsum
        for n in nums:
            for i in range(nsum, n - 1, -1):
                dp[i] += dp[i - n]
        return dp[nsum]
    
