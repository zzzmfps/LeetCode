# 76ms, 82.03%
class Solution:
    def combinationSum2(self, candidates, target):
        candidates.sort()
        res, com = [], []
        self.calculate(candidates, target, res, com, 0)
        return res
    
    def calculate(self, candidates, target, res, com, begin):
        if not target and com not in res:
            res.append(com[:])
            return
        for i in range(begin, len(candidates)):
            if candidates[i] > target: break
            com.append(candidates[i])
            self.calculate(candidates, target - candidates[i], res, com, i + 1)
            com.pop()
    
