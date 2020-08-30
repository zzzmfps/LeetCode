# 88ms, 69.89%; 14.7MB, 63.64%
class Solution:
    def maxProfit(self, prices: list) -> int:
        buy1, sell1, buy2, sell2 = -float('inf'), 0, -float('inf'), 0
        for p in prices:
            sell2 = max(sell2, buy2 + p)
            buy2 = max(buy2, sell1 - p)
            sell1 = max(sell1, buy1 + p)
            buy1 = max(buy1, -p)
        return sell2
