# 216ms, 42.86%; 18MB, 50.76%
class Solution:
    def replaceWords(self, dic: list, sentence: str) -> str:
        self.prune(dic)
        sentence = sentence.split(' ')
        for i, word in enumerate(sentence):
            for pre in dic:
                if word.startswith(pre):
                    sentence[i] = pre
                    break
        return ' '.join(sentence)

    def prune(self, dic: list) -> None:
        dic.sort()
        i = 0
        while i < len(dic):
            j = i + 1
            while j < len(dic):
                if not dic[j].startswith(dic[i]): break
                dic.pop(j)
            i = j
