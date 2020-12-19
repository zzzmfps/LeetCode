# 36ms, 99.38%
class Solution:
    def maxChunksToSorted(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """

        def check(left, right):
            """ check whether arr[left:right] contains all x in [left, right)
            """
            for elem in arr[left:right]:
                if elem < left or elem >= right: return False
            return True

        count = 0
        left, right = 0, 1
        while left < len(arr):
            if check(left, right):
                count += 1
                left, right = right, right + 1
            else:
                right += 1
                if right == len(arr):
                    count += 1
                    break
        return count
