# 64ms, 56.53%; 13.6MB, 100.0%
class Solution:
    def canPlaceFlowers(self, flowerbed: list, n: int) -> bool:
        tmp = ''.join([str(f) for f in [0] + flowerbed + [0]]).split('1')
        count = sum([(len(t) - 1) // 2 for t in tmp])
        return count >= n
