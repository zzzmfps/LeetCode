# 44ms, 100.0%
class Solution:
    def maxProfit(self, prices):
        max_profit = beg = 0
        for i in range(1, len(prices)):
            if prices[i] <= prices[beg]:
                beg = i
            else:
                max_profit = max(max_profit, prices[i] - prices[beg])
        return max_profit
        
