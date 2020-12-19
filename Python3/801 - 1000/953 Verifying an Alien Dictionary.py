# 56ms, 97.28%
class Solution:
    def isAlienSorted(self, words, order):
        """
        :type words: List[str]
        :type order: str
        :rtype: bool
        """
        dist = dict()
        for i, c in enumerate(order):
            dist[c] = i
        for i in range(len(words) - 1):
            for s1, s2 in zip(words[i],words[i + 1]):
                if s1 == s2: continue
                if dist[s1] < dist[s2]: break
                return False
            else:
                if len(words[i]) > len(words[i + 1]): return False
        return True
