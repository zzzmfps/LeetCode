# 360ms, 87.75%; 25.2MB, 20.00%
class Solution:
    def __init__(self, N: int, blacklist: list):
        self.N = N
        self.blacklist = set(blacklist)
        if 2 * len(blacklist) > N or N < 10000:
            self.available = [x for x in range(N) if x not in self.blacklist]
        else:
            self.available = []

    def pick(self) -> int:
        if self.available:
            return self.available[random.randrange(0, len(self.available), 1)]
        while True:
            ret = random.randrange(0, self.N, 1)
            if ret not in self.blacklist: return ret


# Your Solution object will be instantiated and called as such:
# obj = Solution(N, blacklist)
# param_1 = obj.pick()
