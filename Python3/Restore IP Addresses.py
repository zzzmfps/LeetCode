# 44ms, 97.16%
class Solution:
    def restoreIpAddresses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        def check(s):
            if not s: return False
            if len(s) == 1: return True
            if s[0] == '0': return False
            if int(s) > 255: return False
            return True
            
        res = []
        for a in range(1, 4):
            A = s[0: a]
            if not check(A): continue
            for b in range(a + 1, a + 4):
                B = s[a: b]
                if not check(B): continue
                for c in range(b + 1, b + 4):
                    C = s[b: c]
                    if not check(C): continue
                        
                    d = len(s)
                    if d <= c: break
                    if d - c > 3: continue
                    D = s[c: d]
                    if not check(D): continue
                    
                    res.append(A + '.' + B + '.' + C + '.' + D)
        return res
