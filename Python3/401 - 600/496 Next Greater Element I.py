# 72ms, 52.18%
class Solution:
    def nextGreaterElement(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        if not nums1: return []

        res = [-1] * len(nums1)
        num_idx = self.__get_nums_index(nums2)
        rev_max = self.__get_rev_largest_array(nums2, len(nums2))

        for i, n in enumerate(nums1):
            if rev_max[num_idx[n]] > n:
                for j in range(num_idx[n] + 1, len(nums2)):
                    if nums2[j] > n:
                        res[i] = nums2[j]
                        break
        return res

    def __get_nums_index(self, nums):
        return {n: i for i, n in enumerate(nums)}

    def __get_rev_largest_array(self, nums, length):
        ret = [0] * (length - 1) + [nums[-1] - 1]
        for i in range(length - 2, -1, -1):
            ret[i] = max(ret[i + 1], nums[i + 1])
        return ret
    
