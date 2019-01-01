# 64ms, 35.75%
class Solution:
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ones = twos = 0
        for n in nums:
            ones ^= ~twos & n
            twos ^= ~ones & n
        return ones
