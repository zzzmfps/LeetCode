# 164ms, 84.97%; 13.8MB, 28.57%
class Solution:
    def kthSmallestPrimeFraction(self, A: list, K: int) -> list:
        size = len(A)
        l, r = 0.0, 1.0
        while True:
            m = (l+r) / 2
            j, cnt, p, q = 1, 0, 0, 1
            for i in range(size):
                while j < size and A[i] > m * A[j]:
                    j += 1
                cnt += size - j
                if cnt > K: break
                if j < size and p * A[j] < q * A[i]: p, q = A[i], A[j]
            if cnt == K: return [p, q]
            if cnt < K:
                l = m
            else:
                r = m
