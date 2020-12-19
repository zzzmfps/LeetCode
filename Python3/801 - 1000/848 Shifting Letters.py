# 136ms, 41.76%
class Solution:
    def shiftingLetters(self, S, shifts):
        """
        :type S: str
        :type shifts: List[int]
        :rtype: str
        """
        for i in range(len(shifts) - 2, -1, -1):
            shifts[i] += shifts[i + 1]
        res = []
        for i in range(len(shifts)):
            res += chr((ord(S[i]) - 97 + shifts[i]) % 26 + 97)
        return ''.join(res)
