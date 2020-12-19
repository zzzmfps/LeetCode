# 24ms, 91.89%; 12.8MB, 100.00%
class Solution:
    def backspaceCompare(self, S: str, T: str) -> bool:
        p1, p2, cnt1, cnt2 = len(S) - 1, len(T) - 1, 0, 0
        while True:
            while p1 > -1 and (cnt1 or S[p1] == '#'):
                cnt1 += 1 if S[p1] == '#' else -1
                p1 -= 1
            while p2 > -1 and (cnt2 or T[p2] == '#'):
                cnt2 += 1 if T[p2] == '#' else -1
                p2 -= 1
            if p1 < 0 and p2 >= 0 or p2 < 0 and p1 >= 0: return False
            if p1 < 0 and p2 < 0: break
            if S[p1] != T[p2]: return False
            p1, p2 = p1 - 1, p2 - 1
        return True
