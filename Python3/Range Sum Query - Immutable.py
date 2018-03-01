# 60ms, 100.0%
class NumArray:

    def __init__(self, nums):
        if nums:
            self.sums = [nums[0]]
            for i in range(1, len(nums)):
                self.sums.append(self.sums[-1] + nums[i])
        else:
            self.sums = []

    def sumRange(self, i, j):
        if not self.sums: return 0
        if i == 0: return self.sums[j]
        return self.sums[j] - self.sums[i - 1]
