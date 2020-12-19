# 68ms, 54.53%
class Solution:
    def fizzBuzz(self, n):
        res = []
        for i in range(1, n + 1):
            mod3, mod5 = i % 3, i % 5
            if mod3 == 0 and mod5 == 0:
                res.append('FizzBuzz')
            elif mod3 == 0:
                res.append('Fizz')
            elif mod5 == 0:
                res.append('Buzz')
            else:
                res.append(str(i))
        return res
        
