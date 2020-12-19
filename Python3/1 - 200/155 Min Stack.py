# 60ms, 100.0%
class MinStack:

    def __init__(self):
        self.min_stack = list()    # 'self.min_stack = self.min_record = []' is NOT correct
        self.min_record = list()   # that will make them two names of the same list
        
    def push(self, x):
        self.min_stack.append(x)
        if not self.min_record or x <= self.min_record[-1]: self.min_record.append(x)
        
    def pop(self):
        popped = self.min_stack.pop()
        if popped == self.min_record[-1]: self.min_record.pop()
        
    def top(self):
        return self.min_stack[-1]
        
    def getMin(self):
        return self.min_record[-1]
        
