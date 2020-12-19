# 44ms, 100.0%
class Solution:
    def searchRange(self, nums, target):
        def find_target():
            beg, end = 0, len(nums) - 1
            while beg <= end:
                mid = (beg + end) // 2
                if nums[mid] == target:
                    return mid
                elif nums[mid] < target:
                    beg = mid + 1
                else:
                    end = mid - 1
            return -1
        
        def expand():
            end = len(nums) - 1
            left = right = index
            while left > 0 and nums[left - 1] == nums[index]:
                left -= 1
            while right < end and nums[right + 1] == nums[index]:
                right += 1
            return [left, right]
        
        index = find_target()
        if index == - 1: return [-1, -1]
        return expand()
    
