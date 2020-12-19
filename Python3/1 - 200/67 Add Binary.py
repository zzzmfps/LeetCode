# 48ms, 100.0%
class Solution:
    def addBinary(self, a, b):
        if len(a) == 0: return b
        if len(b) == 0: return a
        if a[-1] == '1' and b[-1] == '1':
            return self.addBinary(self.addBinary(a[0: -1], b[0: -1]), '1') + '0'
        else:
            return self.addBinary(a[0: -1], b[0: -1]) + str(int(a[-1]) + int(b[-1]))
    
