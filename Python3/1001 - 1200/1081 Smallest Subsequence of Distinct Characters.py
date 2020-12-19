// 24ms, 97.67%; 12.7MB, 100.00%
class Solution:
    def smallestSubsequence(self, text: str) -> str:
        res = []
        last, seen = [0] * 26, [False] * 26
        for i, c in enumerate(text):
            last[ord(c) - 97] = i
        for i, c in enumerate(text):
            if seen[ord(c) - 97]: continue
            while res and res[-1] > c and i < last[ord(res[-1]) - 97]:
                seen[ord(res[-1]) - 97] = False
                res.pop()
            seen[ord(c) - 97] = True
            res.append(c)
        return ''.join(res)
