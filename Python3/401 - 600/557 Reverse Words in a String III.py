# 40ms, 98.40%
class Solution:
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        s_list = s.split()
        return ' '.join([str[::-1] for str in s_list])
    
