# 60ms, 97.90%
class Solution:
    memo = {}
    def isMatch(self, s, p):
        if (s, p) in self.memo:
            return self.memo[s, p]
        last = p[-1:]
        if last == "*":
            if self.isMatch(s, p[:-2]):
                self.memo[s, p] = True
                return True
            last = p[-2]
            init = p
        else:
            init = p[:-1]
        if not s:
            return not p
        elif (s[-1] == last or last == ".") and self.isMatch(s[:-1], init):
            self.memo[s, p] = True
            return True
        else:
            self.memo[s, p] = False
            return False
        
