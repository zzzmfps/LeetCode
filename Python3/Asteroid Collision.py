# 296ms, 4.73%
class Solution:
    def asteroidCollision(self, asteroids):
        """
        :type asteroids: List[int]
        :rtype: List[int]
        """
        size, idx = len(asteroids), [0, 0]
        while True:
            for i in range(idx[1], size - 1):
                if asteroids[i] > 0 and asteroids[i + 1] < 0:
                    idx[0], idx[1] = i, i + 1
                    break
            else:
                break
            while idx[0] >= 0 and idx[1] < size and asteroids[idx[0]] > 0 and asteroids[idx[1]] < 0:
                tmp = asteroids[idx[0]] + asteroids[idx[1]]
                if tmp <= 0:
                    asteroids[idx[0]] = 0
                    while idx[0] > 0 and asteroids[idx[0]] == 0:
                        idx[0] -= 1
                if tmp >= 0:
                    asteroids[idx[1]] = 0
                    idx[1] += 1
        return [x for x in asteroids if x != 0]
