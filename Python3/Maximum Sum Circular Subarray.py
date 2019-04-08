# 176ms, 87.83%; 16.2MB, 20.83%
class Solution:
    def maxSubarraySumCircular(self, A: list) -> int:
        dp_min = dp_max = all_min = all_max = A[0]
        for i in range(1, len(A)):
            dp_min = A[i] + min(0, dp_min)
            dp_max = A[i] + max(0, dp_max)
            if dp_min < all_min: all_min = dp_min
            if dp_max > all_max: all_max = dp_max
        return max(sum(A) - all_min, all_max) if all_max > 0 else all_max
