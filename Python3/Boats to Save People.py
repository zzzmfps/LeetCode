# 156ms, 98.49%; 17.9MB, 14.29%
class Solution:
    def numRescueBoats(self, people: list, limit: int) -> int:
        p = sorted(people)
        i, j, res = 0, len(p) - 1, 0
        while i <= j:
            if p[i] + p[j] <= limit: i += 1
            j -= 1
            res += 1
        return res
