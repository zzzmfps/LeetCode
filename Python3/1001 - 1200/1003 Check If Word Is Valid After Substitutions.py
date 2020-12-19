# 40ms, 100.0%; 13.3MB, 100.0%
class Solution:
    def isValid(self, S: str) -> bool:
        a = S
        while a:
            b = a.replace('abc','')
            if b == a: return False
            a = b
        return True
