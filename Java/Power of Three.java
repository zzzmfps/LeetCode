// 11ms, 78.97%; 39.6MB, 6.25%
class Solution {
    private static final int[][] pow3 = { {}, { 1, 81, 6561, 531441, 43046721 }, {},
            { 3, 243, 19683, 1594323, 129140163 }, {}, {}, {}, { 27, 2187, 177147, 14348907, 1162261467 }, {},
            { 9, 729, 59049, 4782969, 387420489 } };

    public static boolean isPowerOfThree(final int n) {
        if (n < 1) {
            return false;
        }
        final int index = n % 10;
        for (final int val : pow3[index]) {
            if (val == n) {
                return true;
            }
        }
        return false;
    }
}
