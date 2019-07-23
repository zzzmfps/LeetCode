# 32ms, 92.90%; 13.7MB, 5.93%
from math import ceil, log

class Solution:
    def powerfulIntegers(self, x: int, y: int, bound: int) -> list:
        x_exp = [1] if x == 1 else [x ** i for i in range(ceil(log(bound, x)))]
        y_exp = [1] if y == 1 else [y ** i for i in range(ceil(log(bound, y)))]
        res = [x1 + y1 for x1 in x_exp for y1 in y_exp if x1 + y1 <= bound]
        return list(set(res))
