# 108ms, 89.98%; 19.9MB, 5.85%
class Solution:
    def maxSlidingWindow(self, nums: list, k: int) -> list:
        if not nums: return []

        limit = len(nums) - k + 1
        res = [max(nums[:k])]

        for i in range(limit - 1):
            j = i + k
            if nums[j] >= res[-1]:
                nxt = nums[j]
            elif nums[i] != res[-1]:
                nxt = res[-1]
            else:
                nxt = max(nums[i + 1:j + 1])
            res.append(nxt)
        return res
