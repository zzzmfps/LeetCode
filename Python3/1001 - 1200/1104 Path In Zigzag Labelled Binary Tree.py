# 32ms, 88.37%; 13.9%, 100.00%
class Solution:
    def pathInZigZagTree(self, label: int) -> list:
        res = []
        while label:
            res.append(label)
            label //= 2
        res = res[::-1]
        i = len(res) & 1
        base = 1 + i
        while base <= res[-1]:
            res[i] = 3 * base - 1 - res[i]
            i += 2
            base <<= 2
        return res
