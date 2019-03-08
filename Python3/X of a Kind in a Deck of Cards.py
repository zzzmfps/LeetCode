# 48ms, 74.29%; 13.3MB, 8.16%
from collections import Counter

class Solution:
    def hasGroupsSizeX(self, deck: list) -> bool:
        if(len(deck) < 2): return False
        rec = Counter(deck)

        x = rec.most_common()[-1][-1]
        tmp = [t for t in range(2, 1 + x) if x % t == 0]
        
        for t in tmp:
            for r in rec.values():
                if r % t != 0: break
            else:
                return True
        return False
