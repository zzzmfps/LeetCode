# 44ms, 99.32%
class Solution:
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        from collections import Counter
        tmp = Counter(nums).most_common(k)
        return [x for x, _ in tmp]
