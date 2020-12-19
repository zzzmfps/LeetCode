# 60ms, 35.82%
class Solution:
    def largestTimeFromDigits(self, A):
        """
        :type A: List[int]
        :rtype: str
        """

        def pop_limit_max(arr, limit):  # from a descending array
            for i in range(len(arr)):
                if arr[i] <= limit:
                    d, arr[i] = arr[i], 10
                    return d

        A = sorted(A, reverse=1)
        if A[3] > 2 or A[3] == 2 and (A[2] > 3 or A[1] > 5) or A[3] != 2 and A[2] > 5: return ''

        B = [0, 0, ':', 0, 0]
        if A[1] > 5:
            (B[0], B[3]) = (A[2], A[3]) if A[2] < 2 else (A[3], A[2])
            B[1], B[4] = A[0], A[1]
        else:
            B[0] = pop_limit_max(A, 2)
            B[1] = pop_limit_max(A, 3 if B[0] == 2 else 9)
            B[3] = pop_limit_max(A, 5)
            B[4] = pop_limit_max(A, 9)
        return ''.join([str(d) for d in B])
