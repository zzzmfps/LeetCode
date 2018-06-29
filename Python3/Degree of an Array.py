# 124ms, 34.92%
class Solution:
    def findShortestSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        record, maxNum, tmp = {}, [], 0
        for i, n in enumerate(nums):
            if n in record:
                record[n] += [i]
            else:
                record[n] = [i]
            if tmp < len(record[n]):
                tmp = len(record[n])
                maxNum = []
            if tmp == len(record[n]):
                maxNum += [n]
        tmp = len(nums)
        for mn in maxNum:
            tmp = min(tmp, record[mn][-1] - record[mn][0] + 1)
        return tmp
