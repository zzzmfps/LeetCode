# 100ms, 100.00%; 17.6MB, 5.19%
from heapq import *

class KthLargest:
    def __init__(self, k: int, nums: list):
        self.arr = nums + [-float('inf')]
        heapify(self.arr)
        while k < len(self.arr):
            heappop(self.arr)

    def add(self, val: int) -> int:
        if val > self.arr[0]:
            heappushpop(self.arr, val)
        return self.arr[0]

# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)
