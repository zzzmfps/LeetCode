# 64ms, 99.18%
class Solution:
    def largestNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        from functools import cmp_to_key
        comp = lambda a, b: 1 if a + b < b + a else -1 if a + b > b + a else 0
        return str(int(''.join(sorted([str(x) for x in nums], key=cmp_to_key(comp)))))
