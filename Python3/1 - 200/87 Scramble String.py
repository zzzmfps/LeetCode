# 88ms, 32.42%; 13.4MB, 6.67%
from collections import Counter

class Solution:
    def isScramble(self, s1: str, s2: str) -> bool:
        if s1 == s2: return True
        t1, t2 = Counter(s1), Counter(s2)
        if t1 != t2: return False

        size = len(s1)
        for i in range(1, size):
            if self.isScramble(s1[:i], s2[:i]) and self.isScramble(s1[i:], s2[i:]):
                return True
            if self.isScramble(s1[:i], s2[size - i:]) and self.isScramble(s1[i:], s2[:size - i]):
                return True
        return False
