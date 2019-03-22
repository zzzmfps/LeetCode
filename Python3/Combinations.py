# 124ms, 89.49%; 15.1MB, 7.73%
class Solution:
    def combine(self, n: int, k: int) -> list:
        res, tmp = [], [x for x in range(1, 1 + k)]
        i = k - 1
        while i >= 0:
            if tmp[i] > n - k + 1 + i:
                i -= 1
            elif i == k - 1:
                res.append(tmp[:])
            else:
                while i < k - 1:
                    tmp[i + 1] = 1 + tmp[i]
                    i += 1
                continue
            tmp[i] += 1
        return res
