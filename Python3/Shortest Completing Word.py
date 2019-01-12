# 104ms, 61.29%
class Solution:
    def shortestCompletingWord(self, licensePlate, words):
        """
        :type licensePlate: str
        :type words: List[str]
        :rtype: str
        """
        from collections import Counter
        lp = Counter([c.lower() for c in licensePlate if c.isalpha()])

        last, ret = 16, ''
        for word in words:
            if len(word) >= last: continue
            tmp = Counter(word)
            for c, i in lp.items():
                if tmp.get(c, 0) < i: break
            else:
                last, ret = len(word), word
        return ret
