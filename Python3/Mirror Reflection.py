# 36ms, 94.16%
class Solution:
    def mirrorReflection(self, p, q):
        """
        :type p: int
        :type q: int
        :rtype: int
        """
        while not (p & 1 or q & 1):
            p //= 2
            q //= 2
        return 1 - (p & 1) + (q & 1)
    
