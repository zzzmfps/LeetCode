# 328ms, 76.17%; 16.2MB, 5.04%
class Solution:
    def arrayPairSum(self, nums: list) -> int:
        return sum([x for x in sorted(nums)[::2]])
        
