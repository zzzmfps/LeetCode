# 528ms, 17.09%; 13.6MB, 20.00%
class Solution:

    def threeEqualParts(self, A: list) -> list:
        end = len(A) - 1
        i, j = 0, end
        lval, rval, mid = A[i], A[j], 0
        for k in range(1, end):
            mid = (mid << 1) | A[k]

        while i + 1 < j:
            if lval == rval:
                if mid == lval: return [i, j]
                if mid < lval: break
            elif lval < rval:
                i += 1
                lval = (lval << 1) | A[i]
                mid &= ((1 << (j - i - 1)) - 1)
                continue
            j -= 1
            rval |= (A[j] << (end - j))
            mid >>= 1
        return [-1, -1]
