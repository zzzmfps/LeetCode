# 36ms, 82.14%; 13.1MB, 20.00%
class Solution:
    def isSelfCrossing(self, x: list) -> bool:
        length = len(x)
        if length < 4: return False

        for i in range(3, length):
            if x[i - 3] >= x[i - 1] and x[i - 2] <= x[i]:
                return True   # line 3 cross line 0
            if i < 4: continue
            if x[i - 4] + x[i] >= x[i - 2] and x[i - 3] == x[i - 1]:
                return True    # line 4 meet line 0
            if i < 5: continue
            if x[i - 5] + x[i - 1] >= x[i - 3] and x[i - 1] <= x[i - 3] and x[i - 2] > x[i - 4] and x[i - 4] + x[i] >= x[i - 2]:
                return True    # line 5 cross line 0

        return False
