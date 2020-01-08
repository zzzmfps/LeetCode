# 24ms, 83.93%; 12.7MB, 100.00%
class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        v1, v2 = list(map(int, version1.split('.'))), list(map(int, version2.split('.')))
        len_diff = len(v1) - len(v2)
        if len_diff < 0:
            v1 += [0] * (-len_diff)
        else:
            v2 += [0] * len_diff
        return 0 if v1 == v2 else 1 if v1 > v2 else -1
