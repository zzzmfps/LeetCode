# 328ms, 96.72%; 17.8MB, 10.00%
class Solution:
    def subarraysDivByK(self, A: list, K: int) -> int:
        nums = [0] * K
        res, _sum, nums[0] = 0, 0, 1
        for a in A:
            _sum = (_sum + a) % K
            res += nums[_sum]
            nums[_sum] += 1
        return res
