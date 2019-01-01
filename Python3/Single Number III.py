# 64ms, 34.51%
class Solution:
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        diff, ret = 0, [0, 0]
        for n in nums:
            diff ^= n
        diff &= ~(diff - 1)
        for n in nums:
            ret[0 if n & diff == 0 else 1] ^= n
        return ret
