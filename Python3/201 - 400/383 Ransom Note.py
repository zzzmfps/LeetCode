# 48ms, 97.93%
class Solution:
    def canConstruct(self, ransomNote, magazine):
        return all(ransomNote.count(ch) <= magazine.count(ch)
                   for ch in set(ransomNote))
    
