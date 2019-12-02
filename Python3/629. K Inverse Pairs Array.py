# 372ms, 87.68%; 12.8MB, 100.00%
class Solution:
    def kInversePairs(self, n: int, k: int) -> int:
        limit = n * (n - 1) // 2
        if k < 0 or k > limit: return 0
        if k * 2 > limit: k = limit - k
        if k == 0: return 1
        if k == 1: return n - 1
        if k == 2: return limit - 1

        mod = int(1e9) + 7
        dp = [1, 1]
        for i in range(3, n + 1):
            len1 = i * (i - 1) // 2
            len2 = 1 + min(len1, k)
            cur = [1] * len2
            j = 1
            end2 = 1 + min(k, len1 // 2)
            end1 = min(1 + k, i, end2)
            while j < end1:
                cur[j] = (cur[j - 1] + dp[j]) % mod
                j += 1
            while j < end2:
                cur[j] = (cur[j - 1] + dp[j] - dp[j - i] + mod) % mod
                j += 1
            while j < len2:
                cur[j] = cur[len1 - j]
                j += 1
            dp = cur
        return dp[-1]

