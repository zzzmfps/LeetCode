# 36ms, 100.0%; 13.5MB, 100.0%
class Solution:
    def reverseWords(self, s: str) -> str:
        return ' '.join(x for x in s.split(' ')[::-1] if x)
