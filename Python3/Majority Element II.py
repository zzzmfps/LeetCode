# 44ms, 99.80%
class Solution:
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        num1, num2, count1, count2, limit = 1, 0, 0, 0, len(nums) // 3
        for n in nums:
            if n == num1:
                count1 += 1
            elif n == num2:
                count2 += 1
            elif count1 == 0:
                num1, count1 = n, 1
            elif count2 == 0:
                num2, count2 = n, 1
            else:
                count1, count2 = count1 - 1, count2 - 1
        return [n for n in (num1, num2) if nums.count(n) > limit]
