// 1ms, 95.17%; 35.9MB, 5.88%
class Solution {
    public static boolean checkPerfectNumber(int num) {
        if (num < 6) {
            return false;
        }
        int target = num - 1;
        for (int i = 2, j = (int) Math.sqrt(num); i <= j; ++i) {
            int k = num / i;
            if (i * k != num) {
                continue;
            }
            target -= i + k;
            if (target < 0 || target > 0 && target < i + j) {
                break;
            }
        }
        return 0 == target;
    }
}
