# 36ms, 99.68%
class Solution:
    def findComplement(self, num):
        """
        :type num: int
        :rtype: int
        """
        ex = 1
        while ex < num:
            ex = (ex << 1) + 1
        return ex - num
    
