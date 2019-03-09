# 56ms, 43.40%; 13.2MB, 5.43%
class Solution:
    def removeDuplicates(self, nums: list) -> int:
        if not nums: return 0
        left = self.__find_first(nums)
        if left == -1: return len(nums)
        right = self.__find_next(nums, left)
        if right == -1: return left
        return self.__move_for_duplication(nums, left, right)


    def __find_first(self, nums: list) -> int:  # find first duplicate index
        last, count = nums[0], 0
        for i in range(len(nums)):
            if nums[i] == last:
                if count == 2: return i
                count += 1
            else:
                last, count = nums[i], 1
        return -1


    def __find_next(self, nums: list, i: int) -> int:   # find next different index
        j, length = i + 1, len(nums)
        while j < length and nums[j] == nums[i]:
            j += 1
        return j if j < length else -1


    def __move_for_duplication(self, nums: list, i: int, j: int) -> int:
        last, count, length = nums[j], 0, len(nums)
        while j < length:
            if nums[j] == last:
                if count == 2:
                    count, j = 0, self.__find_next(nums, j)
                    if j == -1: break
                else:
                    count += 1
                    nums[i] = nums[j]
                    i, j = i + 1, j + 1
            else:
                last, count = nums[j], 1
                nums[i] = nums[j]
                i, j = i + 1, j + 1
        return i
