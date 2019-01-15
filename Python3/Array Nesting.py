# 104ms, 98.25%
class Solution:
    def arrayNesting(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        length = len(nums)
        is_visited, ret = [False] * length, 0
        for i in range(length):
            if is_visited[i]: continue
            tmp, j = 0, i
            while not is_visited[j]:
                tmp, is_visited[j] = tmp + 1, True
                j = nums[j]
            if tmp > ret: ret = tmp
        return ret
