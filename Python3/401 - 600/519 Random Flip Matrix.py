# 68ms, 98.39%; 13.4MB, 13.3%
class Solution:

    def __init__(self, n_rows: int, n_cols: int):
        self.col = n_cols
        self.maxLength = n_rows * n_cols
        self.pts = set()
        

    def flip(self) -> List[int]:
        while True:
            opt = int(random.random() * self.maxLength)
            if opt not in self.pts: break
        self.pts.add(opt)
        return [opt // self.col, opt % self.col]
        

    def reset(self) -> None:
        self.pts.clear()


# Your Solution object will be instantiated and called as such:
# obj = Solution(n_rows, n_cols)
# param_1 = obj.flip()
# obj.reset()
