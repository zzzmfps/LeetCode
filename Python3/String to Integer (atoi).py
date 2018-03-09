# 68ms, 100.0%
class Solution:
    def myAtoi(self, s):
        num_str = re.findall(r'[ ]*([+-]?[0-9]*)', s)
        if not num_str or not num_str[0]: return 0
        num_str, sign, res = num_str[0], 1, 0
        if num_str[0] in '+-':
            if num_str[0] == '-': sign = -1
            num_str = num_str[1:]
        for ch in num_str:
            res = res * 10 + ord(ch) - ord('0')
        res *= sign
        if res < -2147483648: return -2147483648
        if res > 2147483647: return 2147483647
        return res
        
