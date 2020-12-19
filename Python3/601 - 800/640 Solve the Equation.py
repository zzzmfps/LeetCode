# 60ms, 11.42%
class Solution:
    def solveEquation(self, equation):
        """
        :type equation: str
        :rtype: str
        """
        c = [0, 0]
        left, right = equation.split('=')
        
        self.helper(left, c)
        self.helper(right, c, -1)

        if c[0] == 0:
            return 'Infinite solutions' if c[1] == 0 else 'No solution'
        else:
            return ''.join(['x=', str(c[1] // c[0])])

        
    def helper(self, str, c, sign=1):
        i, j, length = 0, 0, len(str)
        while j != length:
            i, j = j, j + 1
            while j != length:
                if str[j] == '+' or str[j] == '-': break
                j += 1
            size = j - i
            if str[j - 1] == 'x':
                if size == 1: c[0] += sign
                elif size == 2 and str[i] == '+': c[0] += sign
                elif size == 2 and str[i] == '-': c[0] -= sign
                else: c[0] += sign * int(str[i:j - 1])
            else:
                c[1] -= sign * int(str[i:j])
