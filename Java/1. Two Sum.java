// 1ms, 99.88%; 37.6MB, 98.82%
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] newNums = nums.clone();
        Arrays.sort(newNums);
        int i = 0, j = newNums.length - 1;
        while (true) {
            int tmp = newNums[i] + newNums[j];
            if (tmp == target) {
                break;
            } else if (tmp < target) {
                ++i;
            } else {
                --j;
            }
        }
        int v1 = newNums[i], v2 = newNums[j];
        for (int k = 0;; ++k) {
            if (nums[k] == v1) {
                i = k;
                break;
            }
        }
        for (int k = nums.length - 1;; --k) {
            if (nums[k] == v2) {
                j = k;
                break;
            }
        }
        int[] res = { i, j };
        return res;
    }
}
