// 3ms, 6.48%; 40.6MB, 14.67%
class Solution {
    public static void nextPermutation(int[] nums) {
        int index = inverseLastOrderPair(nums);
        Arrays.parallelSort(nums, index + 1, nums.length);
    }

    private static int inverseLastOrderPair(int[] nums) {
        int last = nums.length - 1, cur = last;
        while (--cur >= 0) {
            for (int i = last; i > cur; --i) {
                if (nums[cur] < nums[i]) {
                    int tmp = nums[cur];
                    nums[cur] = nums[i];
                    nums[i] = tmp;
                    return cur;
                }
            }
        }
        return -1;
    }
}
