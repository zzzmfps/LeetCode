# 80ms, 80.92%
class Solution:
    def findPoisonedDuration(self, timeSeries, duration):
        """
        :type timeSeries: List[int]
        :type duration: int
        :rtype: int
        """
        if not timeSeries or duration == 0: return 0
        total, beg = 0, timeSeries[0]
        for i in range(1, len(timeSeries)):
            if timeSeries[i - 1] + duration < timeSeries[i]:
                total += duration + timeSeries[i - 1] - beg
                beg = timeSeries[i]
        total += duration + timeSeries[-1] - beg
        return total
    
