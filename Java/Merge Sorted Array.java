// 0ms, 100.00%; 39.8MB, 5.94%
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int k = nums1.length;
        while (m > 0 && n > 0) {
            nums1[--k] = (nums1[m - 1] > nums2[n - 1] ? nums1[--m] : nums2[--n]);
        }
        while (n > 0) {
            nums1[--k] = nums2[--n];
        }
    }
}
