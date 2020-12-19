# 192ms, 18.10%; 17.4MB, 5.56%
class Solution:
    def sumEvenAfterQueries(self, A: list, queries: list) -> list:
        tmp = sum(x for x in A if (x & 1) == 0)
        res = []
        for q in queries:
            val, idx = q[0], q[1]
            ev, et = (val & 1), (A[idx] & 1)
            if ev == et:
                tmp += (val if ev == 0 else val + A[idx])
            elif et == 0:
                tmp -= A[idx]
            A[idx] += val
            res.append(tmp)
        return res
