# 60ms, 100.0%
class Solution:
    def divide(self, dividend, divisor):
        def force_border(res):
            if res > 2147483647: return 2147483647
            if res < -2147483648: return -2147483648
            return res
        
        sign = 1 if dividend * divisor > 0 else -1
        dividend, divisor = abs(dividend), abs(divisor)
        res, count, tmp = 0, 1, divisor
        while True:
            if dividend > divisor:
                divisor <<= 1
                count <<= 1
            elif dividend < divisor:
                if count == 1: return force_border(sign * res)
                res += count >> 1
                dividend -= divisor >> 1
                divisor, count = tmp, 1
            else:
                return force_border(sign * (res + count))
    
