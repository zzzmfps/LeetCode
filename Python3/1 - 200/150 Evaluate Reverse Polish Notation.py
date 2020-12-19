# 48ms, 84.07%
class Solution:
    def __init__(self):
        self.valid = ['+', '-', '*', '/']
        self.stack = []
        # yapf: disable
        self.l = lambda num1, num2, token: (num1 + num2 if token == '+' else
                                            num1 - num2 if token == '-' else
                                            num1 * num2 if token == '*' else
                                            num1 // num2 if num1 * num2 >= 0 else
                                            -(abs(num1) // abs(num2)))
        # yapf: enable

    def evalRPN(self, tokens):
        """
        :type tokens: List[str]
        :rtype: int
        """
        index, tsize = 0, len(tokens)
        res = int(tokens[0])
        while index < tsize:
            ti = tokens[index]
            if ti not in self.valid:
                self.stack.append(int(ti))
            else:
                num2 = self.stack.pop()
                num1 = self.stack.pop()
                res = self.l(num1, num2, ti)
                self.stack.append(res)
            index += 1
        return res
    
