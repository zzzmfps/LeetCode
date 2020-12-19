# 36ms, 100.0%
class Solution:
    def grayCode(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        res = [0] * (1 << n)
        for i in range(n):
            cur = trav = incre = 1 << i
            while cur:
                cur -= 1
                res[trav] = res[cur] | incre
                trav += 1
        return res
    
