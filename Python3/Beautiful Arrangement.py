# 64ms, 89.90%
class Solution:
    def __init__(self):
        self.cache = {}

    def countArrangement(self, n):
        """
        :type n: int
        :rtype: int
        """

        def helper(i, arr):
            if i == 1: return 1
            if arr in self.cache: return self.cache[arr]

            total = 0
            for j in range(len(arr)):
                if arr[j] % i == 0 or i % arr[j] == 0:
                    total += helper(i - 1, arr[:j] + arr[j + 1:])
            self.cache[arr] = total
            return total

        return helper(n, tuple(range(1, n + 1)))
