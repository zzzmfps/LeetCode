# 56ms, 79.16%
class Solution(object):
    def nextGreatestLetter(self, letters, target):
        """
        :type letters: List[str]
        :type target: str
        :rtype: str
        """
        target = ord(target)
        beg, end = 0, len(letters) - 1
        while beg < end:
            mid = beg + (end - beg) // 2
            if ord(letters[mid]) <= target:
                beg = mid + 1
            else:
                end = mid
        return letters[beg] if ord(letters[beg]) > target else letters[0]
    
