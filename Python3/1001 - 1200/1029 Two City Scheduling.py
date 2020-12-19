# 32ms, 94.27%; 12.9MB, 100.00%
class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        costs, res = sorted(costs, key=lambda x: x[0] - x[1]), 0
        for i in range(len(costs) >> 1):
            res += costs[i][0]
        for i in range(-len(costs) >> 1, 0):
            res += costs[i][1]
        return res
