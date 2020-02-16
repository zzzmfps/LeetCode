# 36ms, 13.25%; 12.6MB, 100.00%
class Solution:
    def complexNumberMultiply(self, a: str, b: str) -> str:
        a1, a2 = map(int, a.rstrip('i').split('+'))
        b1, b2 = map(int, b.rstrip('i').split('+'))
        x, y = a1 * b1 - a2 * b2, a1 * b2 + a2 * b1
        return f'{x}+{y}i'
