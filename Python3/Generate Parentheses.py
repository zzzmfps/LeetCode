# 44ms, 100.0%
class Solution:
    def generateParenthesis(self, n):
        def add_parentheses(n, m):    # same runtime when nested class is not used
            if not n and not m: res.append(''.join(s))
            s.append('(')
            if n: add_parentheses(n - 1, m + 1)
            s.pop()
            s.append(')')
            if m: add_parentheses(n, m - 1)
            s.pop()
        
        res, s = [], []
        add_parentheses(n, 0)
        return res
    
