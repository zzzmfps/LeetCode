# 392ms, 96.49%
class Solution:
    def numMatchingSubseq(self, S, words):
        """
        :type S: str
        :type words: List[str]
        :rtype: int
        """
        res, exist = 0, set()
        for word in words:
            if word in exist:
                res += 1
                continue
            i = -1
            for w in word:
                i = S.find(w, i + 1)
                if i == -1: break
            else:
                res += 1
        return res
