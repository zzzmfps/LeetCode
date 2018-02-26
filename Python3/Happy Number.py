# 52ms, 100.0%
class Solution:
    def isHappy(self, n):
        '''
        during the process:
            units: INcreasing: 0 (1) ~ +72 (9)
            tens: DEcreasing: -9 (1 or 9) ~ -25 (5)
            hundreds: DEcreasing: -99 (1) ~ -819 (9)
        the given number will finally decrease to no more than 162 (99)
        and it determines that the loop must be finite
        '''
        r = []
        while True:
            r.append(n)
            tmp_list = []
            while n:
                tmp_list.append(n % 10)
                n //= 10
            for num in tmp_list: n += num * num
            if n == 1: return True
            if n in r: return False
        
