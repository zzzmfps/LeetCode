# 64ms, 83.33%
class Solution:
    def findErrorNums(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        res, is_exist = [], [False] * (len(nums) + 1)
        for n in nums:
            if is_exist[n]:
                res.append(n)
            else:
                is_exist[n] = True
        for i, e in enumerate(is_exist[1:], 1):
            if not e:
                res.append(i)
                break
        return res
    
