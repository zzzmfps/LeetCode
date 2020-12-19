# 64m, 48.60%; 14.5MB, 21.98%
class Solution:
    def findPairs(self, nums: list, k: int) -> int:
        arr = sorted(list(set(nums)))
        ret = 0 if k else sum(1 for a in arr if nums.count(a) > 1)
        i, j, size = 0, 1, len(arr)
        while j < size:
            tmp = arr[j] - arr[i]
            if tmp == k:
                ret += 1
                i += 1
                j += 1
            elif tmp < k:
                j += 1
            else:
                i += 1
                if i == j: j += 1
        return ret
