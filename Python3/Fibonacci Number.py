# 32ms, 100.0%; 12.5MB, 100.0%
class Solution:
    def __init__(self):
        self.fibonacci = [0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233,
                          377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711,
                          28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040]

    def fib(self, N: int) -> int:
        return self.fibonacci[N]