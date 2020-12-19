# 36ms, 90.17%; 13MB, 7.84%
class Solution:
    def isLongPressedName(self, name: str, typed: str) -> bool:
        idx = 0
        for n in name:
            tmp = typed.find(n, idx)
            if tmp == -1: return False
            idx = tmp + 1
        return True
