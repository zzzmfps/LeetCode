# 912ms, 40.85%
class Solution:
    def canPartition(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        nsum = sum(nums)
        if nsum & 1: return False
        nsum >>= 1
        dp = [True] + [False] * nsum
        for n in nums:
            for i in range(nsum, n - 1, -1):
                dp[i] |= dp[i - n]
        return dp[nsum]
    
