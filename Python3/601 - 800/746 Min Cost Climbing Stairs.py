# 48ms, 65.90%; 13.3MB, 7.01%
class Solution:
    def minCostClimbingStairs(self, cost: list) -> int:
        cost.append(0)
        dp = [cost[0], cost[1]] + [0] * (len(cost) - 2)
        for i in range(2, len(cost)):
            dp[i] = cost[i] + min(dp[i - 2], dp[i - 1])
        return dp[-1]
