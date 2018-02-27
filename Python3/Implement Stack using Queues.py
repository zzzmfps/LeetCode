# 40ms, 100.0%
class MyStack:

    def __init__(self):
        self.stack = []

    def push(self, x):
        self.stack.append(x)

    def pop(self):
        for _ in range(1, len(self.stack)):
            self.push(self.stack[0])
            self.stack.pop(0)
        x = self.stack.pop(0)
        return x

    def top(self):
        x = self.pop()
        self.push(x)
        return x

    def empty(self):
        return not self.stack
