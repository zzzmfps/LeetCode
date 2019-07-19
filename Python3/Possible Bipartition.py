# 724ms, 5.26%; 19.1MB, 32.35%
class Solution:
    def possibleBipartition(self, N: int, dislikes: list) -> bool:
        if not dislikes: return True
        dislikes.sort(key=lambda x: (x[0], x[1]))
        arr = [0] * (N + 1)
        arr[dislikes[0][0]] = 1

        while dislikes:
            tmp = []
            for d in dislikes:
                x, y = d[0], d[1]
                if arr[x] == arr[y]:
                    if arr[x]: return False
                    tmp.append(d)
                elif arr[x]:
                    arr[y] = 3 - arr[x]
                else:
                    arr[x] = 3 - arr[y]
            if len(dislikes) == len(tmp): arr[dislikes[0][0]] = 1
            dislikes = tmp
        return True
