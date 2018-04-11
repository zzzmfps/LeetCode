# 48ms, 36.07%
class Solution:
    def fractionToDecimal(self, numerator, denominator):
        """
        :type numerator: int
        :type denominator: int
        :rtype: str
        """
        sign = ['-'] if numerator * denominator < 0 else []
        numerator, denominator = abs(numerator), abs(denominator)
        
        integer = numerator // denominator
        numerator %= denominator
        decimal = []

        while numerator:
            numerator *= 10
            res1 = numerator // denominator
            res2 = numerator = numerator - res1 * denominator
            if decimal.count((res1, res2)):
                decimal.insert(decimal.index((res1, res2)), ('(', 0))
                decimal.append((')', 0))
                break
            else:
                decimal.append((res1, res2))
                
        integer = sign + [str(integer)] + (['.'] if decimal else [])
        return ''.join(integer + [str(d[0]) for d in decimal])
    
