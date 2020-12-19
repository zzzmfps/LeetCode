# 36ms, 97.67%
class Solution:
    def scoreOfParentheses(self, S):
        """
        :type S: str
        :rtype: int
        """
        res = layer = 0
        for i in range(0, len(S) - 1):
            if S[i] == '(':
                layer += 1
                if S[i + 1] == ')': res += 1 << (layer - 1)
            else:
                layer -= 1
        return res
