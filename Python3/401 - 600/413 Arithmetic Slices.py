# 40ms, 67.10%; 12.6MB, 100.00%
class Solution:
    def numberOfArithmeticSlices(self, A: list) -> int:
        diff, count, res = None, 0, 0
        for i in range(1, len(A)):
            tmp = A[i] - A[i - 1]
            if tmp == diff:
                count += 1
            else:
                if count > 2: res += (count - 1) * (count - 2) >> 1
                diff = tmp
                count = 2
        else:
            if count > 2: res += (count - 1) * (count - 2) >> 1
        return res
