# 0, dfs: 320ms, 6.23%; 19.1MB, 50.00%
class Solution:
    def lexicalOrder(self, n: int) -> list:
        res = []
        for i in range(1, 10):
            self.helper(res, i, n)
        return res

    def helper(self, arr: list, target: int, n: int) -> None:
        if target > n: return
        arr.append(target)
        target *= 10
        for i in range(10):
            self.helper(arr, target + i, n)


# 1, bruce sort: 128ms, 67.40%; 20.3MB, 50.00%
class Solution:
    def lexicalOrder(self, n: int) -> list:
        return [x for x in sorted(range(1, n + 1), key=lambda x: str(x))]
