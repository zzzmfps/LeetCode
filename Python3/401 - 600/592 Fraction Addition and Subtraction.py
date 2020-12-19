# 36ms, 100.0%
class Solution:
    def fractionAddition(self, expression):
        """
        :type expression: str
        :rtype: str
        """
        import re, math
        is_num = re.compile('[+-]?[0-9]+')
        nums = re.findall(is_num, expression)
        A, B = 0, 1
        for i in range(len(nums) // 2):
            a, b = int(nums[2 * i]), int(nums[2 * i + 1])
            A = a * B + A * b
            B *= b
        # math.gcd(m, n): guaranteed to return a positive integer,
        # and there's no lcm() in module math
        g = math.gcd(A, B)
        return str(A // g) + '/' + str(B // g)
        
