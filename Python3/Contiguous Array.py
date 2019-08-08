# 964ms, 89.26%; 21.9MB, 16.67%
class Solution:
    def findMaxLength(self, nums: list) -> int:
        length = len(nums)
        res, record, index = 0, 0, {0:[-1]}
        for i, n in enumerate(nums):
            record += 1 if n == 0 else -1
            if record in index:
                index[record].append(i)
            else:
                index[record] = [i]
        if record == 0: return length
        for i in index:
            res = max(res, max(index[i]) - min(index[i]))
        return res
