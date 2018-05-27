class Solution:
    def integerBreak(self, n):
        """ method based on the derivative of product.
        :type n: int
        :rtype: int
        """
        if n == 2: return 1
        if n == 3: return 2
        max_product = 1
        while n > 4:
            max_product *= 3
            n -= 3
        return max_product * n
    
