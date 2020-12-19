# 64ms, 9.02%; 13.2MB, 5.45%
from collections import Counter

class Solution:
    def reorganizeString(self, S: str) -> str:
        cnt, length = Counter(S), len(S)
        if cnt.most_common(1)[0][1] > (length + 1) // 2: return ''

        res = []
        for _ in range(length):
            tmp = cnt.most_common(2)
            res += tmp[0][0] if not res or tmp[0][0] != res[-1] else tmp[1][0]    
            cnt[res[-1]] -= 1
            
        return ''.join(res)
