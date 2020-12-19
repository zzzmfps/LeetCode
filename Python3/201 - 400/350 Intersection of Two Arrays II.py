# 36ms, 100.0%
class Solution:
    def intersect(self, nums1, nums2):
        memo, res = {}, []
        for n1 in nums1:
            if n1 not in memo:
                memo[n1] = 1
            else:
                memo[n1] += 1
        for n2 in nums2:
            if n2 in memo and memo[n2]:
                res.append(n2)
                memo[n2] -= 1
        return res
    
