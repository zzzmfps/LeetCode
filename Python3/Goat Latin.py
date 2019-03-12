# 40ms, 48.27%; 13.1MB, 5.88%
class Solution:
    def toGoatLatin(self, S: str) -> str:
        vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'}
        words, ret = S.split(' '), []
        for i, w in enumerate(words):
            if w[0] in vowels:
                ret.append(w + 'maa' + 'a' * i)
            else:
                ret.append(w[1:] + w[0] + 'maa' + 'a' * i)
        return ' '.join(ret)
