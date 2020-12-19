# 76ms, 88.37%
class Solution:
    def makesquare(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        self.size = len(nums)
        if self.size < 4: return False
        perimeter = sum(nums)
        target = perimeter // 4
        if target * 4 != perimeter: return False
        edges = [0] * 4
        nums = sorted(nums)[::-1]
        return self.dfs(edges, nums, 0, target)

    def dfs(self, edges, nums, index, target):
        if index == self.size: return True
        for i in range(4):
            if edges[i] + nums[index] > target: continue
            j = 0
            while j < i:
                if edges[j] == edges[i]: break
                j += 1
            if j != i: continue
            edges[i] += nums[index]
            if self.dfs(edges, nums, index + 1, target): return True
            edges[i] -= nums[index]
        return False
    
