# 44ms, 60.92%; 14MB, 100.00%
class Solution:
    def circularArrayLoop(self, nums: list) -> bool:
        is_visited = [False] * len(nums)
        for i in range(len(nums)):
            if not is_visited[i]:
                is_visited[i] = True
                if self.helper(nums, i, is_visited): return True
        return False

    def helper(self, nums: list, beg: int, is_visited: list) -> bool:
        length = len(nums)
        i, j, vals = beg, (beg + nums[beg]) % length, set([beg])
        while True:
            if i == j or nums[i] * nums[j] < 0: return False
            if is_visited[j] and j in vals: return True
            is_visited[j] = True
            vals.add(j)
            i, j = j, (j + nums[j]) % length
        return False
