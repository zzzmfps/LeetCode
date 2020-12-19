# 0, method 0, not understand at all QAQ, just use it:
# Lagrange's Four Square Theorem: there are only 4 possible results: 1, 2, 3, 4. 
# Legendre's Three Square Theorem: result is 4 if and only if n can be written in the form of (8 * m + 7) * (4 ^ k)
# 1, method 1 and 2:
# Python3 list: using append() every turn is much faster than pre-increase its length and modify.
# totally different from cpp, in which resize() and modify is faster than reserve() and push_back().
# 2, method 1 and 3:
# the 'static dp' following is kind of cheating, due to a feature of LeetCode.com that
# it will not clear your initialization in each testcase, in order to save computing.
# to be more 'honest' will make it much slower.


# 0, Mathematical Solution
# 52ms, 98.57%; 12.9MB, 38.40%
class Solution:
    def numSquares(self, n: int) -> int:
        if self.__is_square(n): return 1
        while (n & 3) == 0: # n % 4 == 0
            n >>= 2
        if (n & 7) == 7: return 4   # n % 8 == 7
        for i in range(1, 1 + int(n ** 0.5)):
            if self.__is_square(n - i ** 2): return 2
        return 3

    def __is_square(self, n: int) -> bool:
        sq = int(n ** 0.5)
        return sq ** 2 == n


# 1, 'static dp', cheating in fact, and using append()
# 200ms, 83.86%; 12.9MB, 38.78%
class Solution:
    rec = [0]
    def numSquares(self, n: int) -> int:
        """
        :type n: int
        :rtype: int
        """
        while len(Solution.rec) <= n:   # same in speed if use self.rec
            size = len(Solution.rec)
            Solution.rec.append(1 + min(Solution.rec[-i ** 2] for i in range(1, 1 + int(size ** 0.5))))
        return Solution.rec[n]


# 2, cheating, but trying to pre-increase its length to n + 1
# 5236ms, 24.95%, 13.3MB, 36.50%
class Solution:
    rec = [0]
    def numSquares(self, n: int) -> int:
        """
        :type n: int
        :rtype: int
        """
        Solution.rec.extend([n for _ in range(1, 2 + n - len(Solution.rec))])
        for i in range(1, 1 + n):
                Solution.rec[i] = 1 + min(Solution.rec[i - j ** 2] for j in range(1, 1 + int(i ** 0.5)))
        return Solution.rec[n]


# 3, honestly no 'static' and using append() (costs 8548ms if no append, omitted)
# 6712ms, 15.42%; 13.1MB, 37.26%
class Solution:
    def numSquares(self, n: int) -> int:
        """
        :type n: int
        :rtype: int
        """
        rec = [0]
        while len(rec) <= n:
            tmp, size = n, len(rec)
            for i in range(1, 1 + int(size ** 0.5)):
                tmp = min(tmp, 1 + rec[size - i ** 2])
            rec.append(tmp)
        return rec[n]
