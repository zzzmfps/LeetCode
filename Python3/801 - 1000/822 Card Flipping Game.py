# 104ms, 88.89%; 12.9MB, 100.00%
class Solution:
    def flipgame(self, fronts: List[int], backs: List[int]) -> int:
        record = set([x for x, y in zip(fronts, backs) if x == y])
        available = set(fronts + backs).difference(record)
        return 0 if not available else min(available)
