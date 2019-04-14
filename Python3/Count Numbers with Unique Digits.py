# 0, exhaustion method: 36ms, 71.66%; 13.1MB, 8.70%
class Solution:
    def __init__(self):
        self.res = [1, 10, 91, 739, 5275, 32491, 168571, 712891, 2345851, 5611771, 8877691]

    def countNumbersWithUniqueDigits(self, n: int) -> int:
        return self.res[min(n, 10)]


# 1, normal: 36ms, 71.66%; 13.1MB, 8.70%
class Solution:
    def __init__(self):
        self.choices = [9, 9, 8, 7, 6, 5, 4, 3, 2, 1]

    def countNumbersWithUniqueDigits(self, n: int) -> int:
        res, product = 1, 1
        for i in range(min(n, 10)):
            product *= self.choices[i]
            res += product
        return res
