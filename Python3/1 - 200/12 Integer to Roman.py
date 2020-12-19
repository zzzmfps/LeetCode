# 128ms, 100.0%
class Solution:
    def intToRoman(self, num):
        def helper(s, delta, tmp=1):
            res.append(s * tmp)
            return delta * tmp
        
        res = []
        if num >= 1000: num -= helper('M', 1000, num // 1000)
        if num >= 900: num -= helper('CM', 900)
        if num >= 500: num -= helper('D', 500)
        if num >= 400: num -= helper('CD', 400)
        if num >= 100: num -= helper('C', 100, num // 100)
        if num >= 90: num -= helper('XC', 90)
        if num >= 50: num -= helper('L', 50)
        if num >= 40: num -= helper('XL', 40)
        if num >= 10: num -= helper('X', 10, num // 10)
        if num == 9: num -= helper('IX', 9)
        else:
            if num >= 5: num -= helper('V', 5)
            if num == 4: num -= helper('IV', 4)
            else: num -= helper('I', 1, num)
        return ''.join(res)
    
