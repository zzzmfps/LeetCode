# 36ms, 72.60%; 13.3MB, 7.14%
class Solution:
    def optimalDivision(self, nums: list) -> str:
        res = [str(n) for n in nums]
        size = len(nums)
        if size == 1: return res[0]
        if size == 2: return '/'.join(res)
        res[1] = '(' + res[1]
        res[-1] += ')'
        return '/'.join(res)
