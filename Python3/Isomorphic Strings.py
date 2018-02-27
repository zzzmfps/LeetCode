# 60ms, 90.60%
class Solution:
    def isIsomorphic(self, s, t):
        m1 = m2 = ''
        for i in range(len(s)):
            si_in_m1, ti_in_m2 = s[i] in m1, t[i] in m2
            if not si_in_m1 and not ti_in_m2:
                m1 += s[i]
                m2 += t[i]
            elif si_in_m1 and ti_in_m2:
                if t[i] != m2[m1.find(s[i])]: return False
            else:
                return False
        return True
        
# 52ms, 100.0%
        # return len(set(zip(s,t))) == len(set(s)) == len(set(t))
        
