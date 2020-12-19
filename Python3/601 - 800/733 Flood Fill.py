# 92ms, 12.78%; 12.9MB, 100.00%
from copy import deepcopy


class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        // return the result, not change the list in-place
        row, col, oldColor = len(image), len(image[0]), image[sr][sc]
        visited, st, res = [[False] * col for _ in range(row)], [(sr, sc)], deepcopy(image)
        while st:
            r, c = st.pop()
            visited[r][c], res[r][c] = True, newColor
            if r and not visited[r - 1][c] and image[r - 1][c] == oldColor: st.append((r - 1, c))
            if c and not visited[r][c - 1] and image[r][c - 1] == oldColor: st.append((r, c - 1))
            if r + 1 < row and not visited[r + 1][c] and image[r + 1][c] == oldColor: st.append((r + 1, c))
            if c + 1 < col and not visited[r][c + 1] and image[r][c + 1] == oldColor: st.append((r, c + 1))
        return res
