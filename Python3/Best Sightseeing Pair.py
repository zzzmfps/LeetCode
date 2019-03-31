# 244ms, 15.60%; 17MB, 100.00%
class Solution:
    def maxScoreSightseeingPair(self, A: list) -> int:
        dp = [0, A[0] + A[1] - 1]
        i, j = 0, 1
        for trav in range(2, len(A)):
            with_i = A[i] + i - trav
            with_j = A[j] + j - trav
            dp.append(max(dp[trav - 1], A[trav] + max(with_i, with_j)))
            if A[trav] > with_i or A[trav] > with_j:
                i = i if with_i > with_j else j
                j = trav
        return dp[-1]
