# 52ms, 100.0%
class MyQueue:

    def __init__(self):
        self.queue = []

    def push(self, x):
        self.push_helper(x)
    
    def push_helper(self, x):
        if not self.queue:
            self.queue.append(x)
        else:
            data = self.queue.pop()
            self.push_helper(x)
            self.queue.append(data)  

    def pop(self):
        return self.queue.pop()

    def peek(self):
        return self.queue[-1]

    def empty(self):
        return not self.queue
