# 168ms, 100.0%
from heapq import heappush
from heapq import heappushpop


class MedianFinder:
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.lhalf = []
        self.rhalf = []

    def addNum(self, num):
        """
        :type num: int
        :rtype: void
        """
        if len(self.lhalf) == len(self.rhalf):
            heappush(self.rhalf, - heappushpop(self.lhalf, - num))
        else:
            heappush(self.lhalf, - heappushpop(self.rhalf, num))
            

    def findMedian(self):
        """
        :rtype: float
        """
        if len(self.lhalf) == len(self.rhalf):
            return(self.rhalf[0] - self.lhalf[0]) / 2
        return self.rhalf[0]
        


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()
