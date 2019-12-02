# 72ms, 98.90%; 13.8 MB, 100.00%
class Solution:
    def findLengthOfLCIS(self, nums: list) -> int:
        max_len = 0
        cur_len, last = 0, -1
        for i in nums:
            if i > last:
                cur_len += 1
                max_len = max(max_len, cur_len)
            else:
                cur_len = 1
            last = i
        return max(max_len, cur_len)
