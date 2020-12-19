# 40ms, 91.16%
class Solution:
    def checkRecord(self, s):
        """
        :type s: str
        :rtype: bool
        """
        total_A = conti_L = 0
        for c in s:
            if c == 'L':
                conti_L += 1
            else:
                conti_L = 0
                if c == 'A': total_A += 1
            if total_A > 1 or conti_L > 2: return False
        return True
    
