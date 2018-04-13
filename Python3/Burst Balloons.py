# 472ms, 71.28%
class Solution:
    def maxCoins(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums2 = [1] + [n for n in nums if n] + [1]
        end = len(nums2)
        dp = [[0] * end for _ in range(end)]

        for k in range(2, end):
            for left in range(0, end - k):
                right = left + k
                for i in range(left + 1, right):
                    dp[left][right] = max(dp[left][right],
                                          nums2[left] * nums2[i] * nums2[right] + dp[left][i] + dp[i][right])
        return dp[0][-1]
    
