# 84ms, 98.94%
class Solution:
    def ladderLength(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: int
        """
        wordList = set(wordList)
        if endWord not in wordList:
            return 0
        head, tail = set([beginWord]), set([endWord])
        chars = 'abcdefghijklmnopqrstuvwxyz'
        dist = 2
        while head:
            temp_set = set()
            for word in head:
                for i in range(len(word)):
                    for c in chars:
                        tmp = word[:i] + c + word[i + 1:]
                        if tmp in tail: return dist
                        if tmp in wordList: temp_set.add(tmp)
            head = temp_set
            wordList -= wordList & head
            if len(head) > len(tail):
                head, tail = tail, head
            dist += 1
        return 0
    
