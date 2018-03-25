# 48ms, 55.12%
class Solution:
    def getPermutation(self, n, k):
        cand = [chr(i + 48) for i in range(1, n + 1)]
        fact = [1] * (n - 1)
        for i in range(2, n):
            fact[n - i - 1] = fact[n - i] * i
        
        k, res = k - 1, []
        for f in fact:
            idx = k // f
            res.append(cand.pop(idx))
            k -= f * idx
        res += cand
        return ''.join(res)
        
