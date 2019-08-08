# 932ms, 97.32%; 21.8MB, 16.67%
class Solution:
    def findMaxLength(self, nums: list) -> int:
        length = len(nums)
        res, record, index = 0, 0, {0:[-1]}
        for i, n in enumerate(nums):
            record += 1 if n == 0 else -1
            if record in index:
                tmp = index[record]
                if len(tmp) == 2:
                    tmp[1] = i
                else:
                    tmp.append(i)
            else:
                index[record] = [i]
        if record == 0: return length
        for i in index:
            res = max(res, index[i][-1] - index[i][0])
        return res
