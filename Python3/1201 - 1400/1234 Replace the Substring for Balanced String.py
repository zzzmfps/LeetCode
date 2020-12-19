# 256ms, 78.86%; 13.3MB, 100.00%
class Solution:
    def balancedString(self, s: str) -> int:
        def to_int(c: str) -> int:
            return 'QWER'.index(c)

        a, ret = [-(len(s) >> 2)] * 4, len(s)
        for c in s:
            a[to_int(c)] += 1
        a = [x if x > 0 else 0 for x in a]
        if all([x == 0 for x in a]): return 0
        i = 0
        for j, c in enumerate(s):
            index = to_int(c)
            a[index] -= 1
            if a[index] == 0 and all([x <= 0 for x in a]):
                while True:
                    tmp = to_int(s[i])
                    a[tmp], i = a[tmp] + 1, i + 1
                    if a[tmp] > 0: break
                ret = min(ret, j - i + 2)
        return ret
    
