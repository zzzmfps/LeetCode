# 108ms, 68.77%
class Solution:
    def numFriendRequests(self, ages):
        """
        :type ages: List[int]
        :rtype: int
        """
        from collections import Counter
        ages1, nums1 = zip(*Counter(ages).items())
        ages2 = [0.5 * x + 7 for x in ages1]
        length, ret = len(ages1), 0
        for i in range(length):
            for j in range(i, length):
                if i == j:
                    if ages1[i] > ages2[i]: ret += nums1[i] * (nums1[i] - 1)
                else:
                    if ages1[i] > ages2[j] and ages1[i] < ages1[j]: ret += nums1[i] * nums1[j]
                    elif ages1[j] > ages2[i] and ages1[j] < ages1[i]: ret += nums1[i] * nums1[j]
        return ret
