# 40ms, 98.71%; 13.7MB, 15.44%
class Solution:
    def minimumTotal(self, triangle: list) -> int:
        for i in range(1, len(triangle)):
            cur, last = triangle[i], triangle[i-1]
            cur[0] += last[0]
            cur[-1] += last[-1]
            for j in range(1, len(cur) - 1):
                cur[j] += min(last[j - 1], last[j])
        return min(triangle[-1])
