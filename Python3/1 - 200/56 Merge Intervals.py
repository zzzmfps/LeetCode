# 68ms, 94.40%
class Solution:
    def merge(self, intervals):
        if not intervals: return []
        intervals.sort(key = lambda i: i.start)
        res = [intervals[0]]
        for i in range(1, len(intervals)):
            start, end = intervals[i].start, intervals[i].end
            if start <= res[-1].end and end > res[-1].end:
                res[-1].end = end
            elif start > res[-1].end:
                res.append(intervals[i])
        return res
    
