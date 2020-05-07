// 0ms, 100.00%; 39.8MB, 5.77%
class Solution {
    public static void rotate(int[] nums, int k) {
        if ((k %= nums.length) == 0) {
            return;
        }
        int beg = 0, last = nums[0];
        for (int i = k, j = 1; i != beg || j != nums.length; i = (i + k) % nums.length, ++j) {
            int tmp = nums[i];
            nums[i] = last;
            last = tmp;
            if (i == beg) {
                last = nums[(i = ++beg)];
            }
        }
        nums[beg] = last;
    }
}
