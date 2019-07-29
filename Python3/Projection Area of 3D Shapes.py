# 84ms, 84.62%; 13.9MB, 6.52%
class Solution:
    def projectionArea(self, grid: list) -> int:
        arr1 = [max(x) for x in grid]
        arr2 = [max([x[i] for x in grid]) for i in range(len(grid))]
        arr3 = [1 for x in grid for y in x if y]
        return sum(arr1) + sum(arr2) + sum(arr3)
    
