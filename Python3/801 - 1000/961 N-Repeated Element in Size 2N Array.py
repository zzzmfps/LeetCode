# 72ms, 97.07%
class Solution:
    def repeatedNTimes(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        tmp = set()
        for a in A:
            if a in tmp: return a
            tmp.add(a)
