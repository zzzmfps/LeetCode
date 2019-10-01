# 44ms, 87.41%; 13.8MB, 25.00%
class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        res1, res2 = 0, 0
        cnt1, cnt2 = [0] * 10, [0] * 10
        for x, y in zip(secret, guess):
            if x == y:
                res1 += 1
            else:
                cnt1[int(x)] += 1
                cnt2[int(y)] += 1
        for x, y in zip(cnt1, cnt2):
            res2 += min(int(x), int(y))
        return ''.join([str(res1), 'A', str(res2), 'B'])
