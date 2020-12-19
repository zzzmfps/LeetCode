# 44ms, 98.50%; 14MB, 20.00%
class Solution:
    def numSpecialEquivGroups(self, A: list) -> int:
        tmp = set()
        for a in A:
            x = ''.join(sorted(a[0::2]))
            y = ''.join(sorted(a[1::2]))
            tmp.add((x, y))
        return len(tmp)
