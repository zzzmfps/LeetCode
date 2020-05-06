// 1ms, 48.02%; 40.1MB, 5.22%
class Solution {
    public static int[] twoSum(int[] numbers, int target) {
        int[] idx = { 1, numbers.length };
        while (true) {
            int tmp = numbers[idx[0] - 1] + numbers[idx[1] - 1];
            if (tmp < target) {
                ++idx[0];
            } else if (tmp > target) {
                --idx[1];
            } else {
                break;
            }
        }
        return idx;
    }
}
