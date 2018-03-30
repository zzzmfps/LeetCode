# 96ms, 96.40%
class Solution:
    def isMatch(self, s, p):
        sidx = pidx = 0
        tmp_sidx = tmp_pidx = -1
        lens, lenp = len(s), len(p)
        while sidx < lens:
            if pidx < lenp and (p[pidx] == '?' or p[pidx] == s[sidx]):
                pidx, sidx = pidx + 1, sidx + 1
            elif pidx < lenp and p[pidx] == '*':
                tmp_pidx = pidx
                tmp_sidx = sidx
                pidx += 1
            elif tmp_pidx != -1:
                pidx = tmp_pidx + 1
                tmp_sidx += 1
                sidx = tmp_sidx
            else:
                return False
        while pidx < lenp and p[pidx] == '*':
            pidx += 1
        return pidx == lenp
    
