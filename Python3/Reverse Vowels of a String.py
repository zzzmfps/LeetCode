# 68ms, 96.88%
class Solution:
    def reverseVowels(self, s):
        s = list(s)
        beg, end = 0, len(s) - 1
        vowels = 'aeiouAEIOU'
        for _ in s:
            if beg >= end: break
            if s[beg] not in vowels:
                beg += 1
                continue
            if s[end] not in vowels:
                end -= 1
                continue
            s[beg], s[end] = s[end], s[beg]
            beg += 1
            end -= 1
        return ''.join(s)
    
