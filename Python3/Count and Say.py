# 40ms, 100.0%
class Solution:
    def countAndSay(self, n):
        s = '1'
        for _ in range(n - 1):    // not really understand
            s = re.sub(r'(.)\1*', lambda m: str(len(m.group(0))) + m.group(1), s)
        return s
        
