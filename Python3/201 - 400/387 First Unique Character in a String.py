# 80ms, 90.29%
class Solution:
    def firstUniqChar(self, s):
        alphabet = 'abcdefghijklmnopqrstuvwxyz'
        res = [s.index(c) for c in alphabet if s.count(c) == 1]
        return min(res) if res else -1
    '''Time complexity
    above: T(n) ~ O(26n), costs 80ms
    below: T(n) = O(3n), costs 160ms ... WHY?
    '''
        x = [0] * 26
        s_int = [ord(c) - 97 for c in s]
        s_end = len(s_int)
        for c in s_int:
            x[c] += 1
        for i in range(s_end):
            if x[s_int[i]] == 1: return i
        return -1
    
