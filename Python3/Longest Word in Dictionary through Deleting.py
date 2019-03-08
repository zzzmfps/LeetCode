# 72ms, 96.69%; 14.6MB, 5.36%
class Solution:
    def findLongestWord(self, s: str, d: list) -> str:
        d.sort(key=lambda x: (-len(x), x))
        for w in d:
            idx = 0
            for ww in w:
                tmp = s.find(ww, idx)
                if tmp == -1: break
                idx = tmp + 1
            else:
                return w
        return ''
