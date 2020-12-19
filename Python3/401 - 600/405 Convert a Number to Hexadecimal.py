# 36ms, 98.77%
class Solution:
    def toHex(self, num):
        if num == 0: return '0'
        num &= 0xFFFFFFFF
        hexalpha = ['0', '1', '2', '3', '4', '5', '6', '7',
                    '8', '9', 'a', 'b', 'c', 'd', 'e', 'f']
        res = []
        while num:
            tmp = num % 16
            num //= 16
            res.append(hexalpha[tmp])
        return ''.join(res[::-1])
    
