# 40ms, 96.54%
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        if obstacleGrid[0][0]: return 0
        m, n = len(obstacleGrid), len(obstacleGrid[0])
        paths = [[0] * n for _ in range(m)]
        paths[0][0] = 1
        for i in range(1, m):
            paths[i][0] = 0 if obstacleGrid[i][0] else paths[i - 1][0]
        for j in range(1, n):
            paths[0][j] = 0 if obstacleGrid[0][j] else paths[0][j - 1]
        for i in range(1, m):
            for j in range(1, n):
                paths[i][j] = (0 if obstacleGrid[i][j] else
                               paths[i][j - 1] + paths[i - 1][j])
        return paths[-1][-1]
    
