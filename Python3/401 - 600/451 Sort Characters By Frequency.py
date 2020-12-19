# 52ms, 65.34%
class Solution:
    def frequencySort(self, s):
        """
        :type s: str
        :rtype: str
        """
        freq = {}
        for c in s:
            if c in freq:
                freq[c] += 1
            else:
                freq[c] = 1
        freq = sorted(freq.items(), key=lambda x: x[1], reverse=True)
        return ''.join([key * val for key, val in freq])
    
