# 44ms, 92.31%
class Solution:
    def nearestPalindromic(self, n):
        def mirror(mid, d):
            prefix = str(mid + d)
            return int(prefix + prefix[:lenn // 2][::-1])
        
        lenn = len(n)
        mid = int(n[:(lenn + 1) // 2])
        candidates = [10 ** (lenn - 1) - 1,
                      mirror(mid, -1), mirror(mid, 0), mirror(mid, 1),
                      10 ** lenn + 1]
        num, dif, res = int(n), float('inf'), 0
        if num in candidates: candidates.remove(num)
        for c in candidates:
            tmp = abs(num - c)
            if tmp < dif: dif, res = tmp, c
        return str(res)
    
