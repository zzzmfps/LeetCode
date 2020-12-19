# 48ms, 77.49%; 13.3MB, 35.09%
class Solution:
    def combinationSum4(self, nums: list, target: int) -> int:
        tmp = [1] + [0] * target
        for i in range(1, 1 + target):
            for n in nums:
                if i >= n: tmp[i] += tmp[i - n];
        return tmp[-1]
