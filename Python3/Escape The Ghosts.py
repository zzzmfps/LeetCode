# 40ms, 47.83%; 13.2MB, 5.88%
class Solution:
    def escapeGhosts(self, ghosts: list, target: list) -> bool:
        stp = abs(target[0]) + abs(target[1])
        for g in ghosts:
            if stp >= abs(g[0] - target[0]) + abs(g[1] - target[1]): return False
        return True
