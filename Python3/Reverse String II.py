# 28ms, 80.10%; 12.9MB, 100.00%
class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        tmp = [s[k * i:k * (i + 1)] for i in range(1 + len(s) // k)]
        tmp = [x if i & 1 else x[::-1] for i, x in enumerate(tmp)]
        return ''.join(tmp)
