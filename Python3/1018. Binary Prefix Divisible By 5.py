# 128ms, 95.12%; 14.8MB, 100.00%
class Solution:
    def prefixesDivBy5(self, A: list) -> list:
        res = [False] * len(A)
        if A[0] == 0: res[0] = True
        cur = A[0]
        for i in range(1, len(A)):
            cur = ((cur << 1) + A[i]) % 5
            if cur == 0: res[i] = True
        return res
