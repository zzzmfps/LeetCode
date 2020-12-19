# 140ms
class Solution:
    def maxProfitAssignment(self, difficulty, profit, worker):
        """
        :type difficulty: List[int]
        :type profit: List[int]
        :type worker: List[int]
        :rtype: int
        """
        job = sorted([[d, p] for d, p in zip(difficulty, profit)])
        res, i, maxp, jlen = 0, 0, 0, len(job)
        for ab in sorted(worker):
            while i < jlen and ab >= job[i][0]:
                maxp = max(maxp, job[i][1])
                i += 1
            res += maxp
        return res
    
