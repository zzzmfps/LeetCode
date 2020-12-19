# 1, list comprehension in Python is faster than iteration(172ms)
# 2, as for square, x * x is faster than x ** 2
# 3, list.sort() is faster than sorted(), because the former doesn't create a new list(in place)

# 160ms, 74.94%; 15.1MB, 5.22%
class Solution:
    def sortedSquares(self, A: list) -> list:
        res = [x * x for x in A]
        res.sort()
        return res
