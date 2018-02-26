# 240ms, 100.0%
class Solution:
    def countPrimes(self, n):
        primes = [True] * n
        primes[: 2] = [False] * 2
        for i in range(2, int(n ** 0.5) + 1):
            if primes[i]:
                square = i * i
                # [a: b: c]: interval [a, b), every c elements
                # eg. [1: 9: 2]: 1, 3, 5, 7
                # so, [(square: n): i]: i * i, i * (i + 1), ... (< n)
                # (n - square - 1) // i + 1 == len(primes[square: n: i])
                primes[square: n: i] = [False] * ((n - square - 1) // i + 1)
        return sum(primes)
    
