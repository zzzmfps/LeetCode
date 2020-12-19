# 476ms, 89.29%
class Solution:
    def palindromePairs(self, words):
        """
        :type words: List[str]
        :rtype: List[List[int]]
        """
        words = {word: i for i, word in enumerate(words)}
        valid = []
        for word, i in words.items():
            for j in range(len(word) + 1):
                pre, suf = word[:j], word[j:]
                erp, fus = pre[::-1], suf[::-1]
                if pre == erp:
                    if fus != word and fus in words:
                        valid.append([words[fus], i])
                if j != len(word) and suf == fus:
                    if erp != word and erp in words:
                        valid.append([i, words[erp]])
        return valid
