# 48ms, 97.39%
class Solution:
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        def separate():
            sep, tmp = [], []
            for n in nums:
                if n != 0:
                    tmp.append(n)
                elif tmp:
                    sep.append(tmp)
                    tmp = []
            return sep + [tmp] if tmp else sep

        sep = separate()
        max_p = nums[0] if len(sep) == 1 else 0
        for s in sep:
            left = right = whole = 1
            i, j, neg_cnt = 0, len(s) - 1, 0
            for n in s:
                whole *= n
                if n < 0: neg_cnt += 1
            if neg_cnt % 2 and j > 0:
                while i < len(s):
                    left *= s[i]
                    if s[i] < 0: break
                    i += 1
                while -1 < j:
                    right *= s[j]
                    if s[j] < 0: break
                    j -= 1
            max_p = max(max_p, whole, whole // left, whole // right)
        return max_p
