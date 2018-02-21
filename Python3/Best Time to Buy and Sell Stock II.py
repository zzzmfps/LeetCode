# 40ms, 100.0%
class Solution:
    def maxProfit(self, prices):
        beg, end, profit, length = 0, 0, 0, len(prices) - 1
        while True:
            while beg < length and prices[beg] >= prices[beg + 1]: beg += 1    # increasing sequence
            end = beg + 1
            while end < length and prices[end + 1] >= prices[end]: end += 1    # decreasing sequence
            if end > length: break
            profit += prices[end] - prices[beg]
            beg, end = end + 1, end + 2
        return profit
        
