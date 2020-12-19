# 52ms, 100.0%
class Solution:
    def isPalindrome(self, s):
        s = re.sub(r'[^a-zA-Z0-9]', '', s).lower()
        return s == s[::-1]
    
