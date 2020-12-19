# 64ms, 77.36%; 13.9MB, 25.00%
class Solution:
    def bagOfTokensScore(self, tokens: list, P: int) -> int:
        tokens.sort()
        i, j, point = 0, len(tokens) - 1, 0
        while True:
            while i <= j and tokens[i] <= P:
                P -= tokens[i]
                i += 1
                point += 1
            if i >= j or point == 0: break
            P += tokens[j]
            j -= 1
            point -= 1
        return point
