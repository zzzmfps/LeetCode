# 144ms, 70.60%
class Solution:
    def groupAnagrams(self, strs):
        grouped = {}
        for s in strs:
            grouped.setdefault(''.join(sorted(s)), []).append(s)
        return list(grouped.values())
    
