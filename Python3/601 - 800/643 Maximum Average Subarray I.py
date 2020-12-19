# 896ms, 81.33%; 16.2MB, 12.50%
class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        _sum = _max = sum(nums[:k])
        for i in range(k, len(nums)):
            _sum += nums[i] - nums[i - k]
            _max = max(_max, _sum)
        return _max / k
