# 56ms, 92.10%; 13.9MB, 20.00%
class Solution:
    def isOneBitCharacter(self, bits: list) -> bool:
        size, i = len(bits), 0
        while i < size:
            if i + 1 == size: return True
            i += 1 if bits[i] == 0 else 2
        return False
