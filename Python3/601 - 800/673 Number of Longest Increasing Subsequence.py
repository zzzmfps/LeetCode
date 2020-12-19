# 584ms, 90.70%
class Solution:
    def findNumberOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        dp = [[1, 1] for _ in range(len(nums))]
        max_for_all, res = 1, 0
        for i, num in enumerate(nums):
            max_len, count = 1, 0
            for j in range(i):
                if nums[j] < num:
                    if max_len == dp[j][0] + 1:
                        count += dp[j][1]
                    elif max_len < dp[j][0] + 1:
                        max_len = dp[j][0] + 1
                        count = dp[j][1]
            dp[i] = [max_len, max(count, dp[i][1])]
            max_for_all = max(max_len, max_for_all)
        return sum([item[1] for item in dp if item[0] == max_for_all])
    
