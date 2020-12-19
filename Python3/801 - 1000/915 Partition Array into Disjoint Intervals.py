# 108ms, 56.00%
class Solution:
    def partitionDisjoint(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        mins, maxn = [10**6], A[0]
        for x in A[::-1]:
            mins.append(mins[-1] if mins[-1] < x else x)
        mins = mins[:0:-1]
        for i in range(1, len(A)):
            if maxn <= mins[i]: return i
            maxn = max(maxn, A[i])
