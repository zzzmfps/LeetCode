# 36ms, 100.0%
class Solution:
    def isValid(self, s):
        tmp, right, valid = s[0], ")]}", ["()", "[]", "{}"]
        for i in range(1, len(s)):
            if not tmp:
                if s[i] in right:
                    return False
                else:
                    tmp = s[i]
            elif tmp[-1] + s[i] in valid:
                tmp = tmp[:-1]
            else:
                tmp += s[i]
        return not tmp
    
