# 36ms, 100.0%
class Solution:
    def binaryGap(self, N):
        """
        :type N: int
        :rtype: int
        """
        if N & (N - 1) == 0: return 0
        bin_num = bin(N).strip('0b')
        ret, last_idx = 1, 0
        while True:
            idx1 = bin_num.find('0', last_idx)
            if idx1 == -1: break
            idx2 = bin_num.find('1', idx1 + 1)
            if idx2 == -1: break
            ret = max(ret, idx2 - idx1 + 1)
            last_idx = idx2 + 1
        return ret
