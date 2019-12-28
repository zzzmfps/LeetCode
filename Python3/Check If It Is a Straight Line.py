# 64ms, 83.45%; 13.2MB, 100.00%
class Solution:
    def checkStraightLine(self, coordinates: list) -> bool:
        vertical = sum([1 if x == coordinates[-1][0] else 0 for x, _ in coordinates])
        if vertical > 1: return vertical == len(coordinates)
        dx, dy = coordinates.pop()
        slopes = [(y - dy) / (x - dx) for x, y in coordinates]
        return 1 == len(set(slopes))
