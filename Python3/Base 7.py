# 40ms, 61.92%; 13.2MB, 5.55%
class Solution:
    def convertToBase7(self, num: int) -> str:
        if num == 0: return '0'
        res, pos = [], abs(num)
        while pos:
            tmp = pos // 7
            res.append(pos - 7 * tmp)
            pos = tmp
        if num < 0: res.append('-')
        return ''.join([str(r) for r in res[::-1]])
