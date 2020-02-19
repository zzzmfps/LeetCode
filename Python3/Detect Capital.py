# 28sm, 69.33%; 12.7MB, 100.00%
class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        if word.isupper(): return True
        if word.islower(): return True
        if word.capitalize() == word: return True
        return False
