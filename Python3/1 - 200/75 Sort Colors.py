# 40ms, 62.41%; 13.2MB, 5.06%
class Solution:
    def sortColors(self, nums: list) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        self.length = len(nums)
        if self.length < 2: return
        index = self.__find_first_index(nums, 0)
        index = self.__sort_color(nums, 0, 1 + index, 1)
        index = self.__find_first_index(nums, 1, index)
        self.__sort_color(nums, 1, 1 + index, 1)

    def __find_first_index(self, nums: list, n: int, hint: int=0) -> int:
        for index in range(hint, self.length):
            if nums[index] != n: break
        return index

    def __sort_color(self, nums: list, n: int, index: int, delta: int) -> int:
        for i in range(index, self.length):
            if nums[i] != n:
                delta += 1
            else:
                nums[i], nums[i - delta] = nums[i - delta], nums[i]
        return self.length - delta
