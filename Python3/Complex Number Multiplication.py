# 36ms, 13.25%; 12.7MB, 100.00%
class Solution:
    def complexNumberMultiply(self, a: str, b: str) -> str:
        a1, a2 = map(int, a.rstrip('i').split('+'))
        b1, b2 = map(int, b.rstrip('i').split('+'))
        x, y = str(a1 * b1 - a2 * b2), str(a1 * b2 + a2 * b1)
        return x + '+' + y + 'i'
