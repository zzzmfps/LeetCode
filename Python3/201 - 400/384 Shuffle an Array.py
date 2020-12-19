# 412ms, 99.50%
class Solution:
    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.origin = nums
        self.shuffled = nums[:]

    def reset(self):
        """
        Resets the array to its original configuration and return it.
        :rtype: List[int]
        """
        return self.origin

    def shuffle(self):
        """
        Returns a random shuffling of the array.
        :rtype: List[int]
        """
        # use random.SystemRandom and costs 1368ms
        random.shuffle(self.shuffled)
        return self.shuffled


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()
