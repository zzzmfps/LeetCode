# 56ms, 17.72%; 13.4MB, 28.57%
class Solution:
    def canTransform(self, start: str, end: str) -> bool:
        def check(s1: str, i1: int, s2: str, i2: int) -> bool:
            return s1 != s2 or s1 == 'R' and i1 > i2 or s1 == 'L' and i1 < i2

        arr1 = [(x, i) for i, x in enumerate(start) if x != 'X']
        arr2 = [(x, i) for i, x in enumerate(end) if x != 'X']
        if len(arr1) != len(arr2): return False
        return not any([check(s1, i1, s2, i2) for (s1, i1), (s2, i2) in zip(arr1, arr2)])
