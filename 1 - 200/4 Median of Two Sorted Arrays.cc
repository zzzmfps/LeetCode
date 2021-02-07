// 82ms, 7.44%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int m = nums1.size(), n = nums2.size();
        if (m > n) swap(nums1, nums2), swap(m, n);

        int imin = 0, imax = m, halfLen = (m + n + 1) / 2;
        while (imin <= imax) {
            int i = (imin + imax) / 2;
            int j = halfLen - i;
            if (i < m && nums2[j - 1] > nums1[i])
                imin = i + 1;
            else if (i > 0 && nums1[i - 1] > nums2[j])
                imax = i - 1;
            else {
                int maxOfLeft, minOfRight;
                if (i == 0)
                    maxOfLeft = nums2[j - 1];
                else if (j == 0)
                    maxOfLeft = nums1[i - 1];
                else
                    maxOfLeft = max(nums1[i - 1], nums2[j - 1]);
                if ((m + n) % 2 == 1) return maxOfLeft;

                if (i == m)
                    minOfRight = nums2[j];
                else if (j == n)
                    minOfRight = nums1[i];
                else
                    minOfRight = min(nums1[i], nums2[j]);
                return (maxOfLeft + minOfRight) / 2.0;
            }
        }
    }
};
