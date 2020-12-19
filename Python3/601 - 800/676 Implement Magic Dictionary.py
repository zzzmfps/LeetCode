# 36ms, 79.73%; 13.2MB, 9.09%
class MagicDictionary:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.map = dict()

    def buildDict(self, dic: list) -> None:
        """
        Build a dictionary through a list of words
        """
        for word in dic:
            size = len(word)
            if size in self.map:
                self.map[size].append(word)
            else:
                self.map[size] = [word]

    def search(self, word: str) -> bool:
        """
        Returns if there is any word in the trie that equals to the given word after modifying exactly one character
        """
        size = len(word)
        if size not in self.map: return False
        for s in self.map[size]:
            if self.__check(word, s): return True
        return False

    def __check(self, x: str, y: str) -> bool:
        flag = False
        for i in range(len(x)):
            if x[i] == y[i]: continue
            if flag: return False
            flag = True
        return flag

# Your MagicDictionary object will be instantiated and called as such:
# obj = MagicDictionary()
# obj.buildDict(dict)
# param_2 = obj.search(word)
