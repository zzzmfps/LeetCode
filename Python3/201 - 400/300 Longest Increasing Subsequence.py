# 56ms, 97.18%
class Solution:
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        res = []
        for n in nums:
            it = self.lower_bound(res, n)
            if it == -1:
                res.append(n)
            else:
                res[it] = n
        return len(res)

           
    def lower_bound(self, arr, x):
        if not arr or arr[-1] < x: return -1
        left, right = 0, len(arr) - 1
        while left < right:
            mid = (left + right) // 2
            if arr[mid] < x:
                left = mid + 1
            else:
                right = mid
        return left
