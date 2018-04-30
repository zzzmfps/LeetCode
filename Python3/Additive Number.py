# 36ms, 93.18%
class Solution:
    def isAdditiveNumber(self, num):
        import itertools
        n = len(num)
        for i, j in itertools.combinations(range(1, n), 2):
            a, b = num[:i], num[i:j]
            if a[0] == '0' and 1 < i: continue
            if b[0] == '0' and i + 1 < j: continue
            while j < n:
                c = str(int(a) + int(b))
                if not num.startswith(c, j): break
                j += len(c)
                a, b = b, c
            if j == n:
                return True
        return False
    
