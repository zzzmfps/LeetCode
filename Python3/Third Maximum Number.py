# 44ms, 85.00%
class Solution:
    def thirdMax(self, nums):
        n_inf = float('-inf')
        v = [n_inf, n_inf, n_inf]
        for num in nums:
            if num not in v:
                if num > v[0]:
                    v = [num, v[0], v[1]]
                elif num > v[1]:
                    v = [v[0], num, v[1]]
                elif num > v[2]:
                    v = [v[0], v[1], num]
        return v[0] if n_inf in v else v[2]
    
