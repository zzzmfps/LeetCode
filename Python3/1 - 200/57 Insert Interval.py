# 56ms, 98.85%
# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution:
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[Interval]
        :type newInterval: Interval
        :rtype: List[Interval]
        """
        iter1, size = 0, len(intervals)
        while iter1 < size and intervals[iter1].end < newInterval.start:
            iter1 += 1
        iter2 = iter1
        while iter2 < size and intervals[iter2].start <= newInterval.end:
            iter2 += 1
            
        mid = Interval((newInterval.start if iter1 == size else min(newInterval.start, intervals[iter1].start)),
                       (newInterval.end if iter2 == iter1 else max(newInterval.end, intervals[iter2 - 1].end)))
        return intervals[:iter1] + [mid] + intervals[iter2:]
    
