// 0ms, 100.00%; 39.7MB, 12.38%
class Solution {
    public int maxProfit(int[] prices) {
        int res = 0, beg, end = -1;
        while (true) {
            beg = ascendUntil(prices, end + 1, false);
            end = ascendUntil(prices, beg, true);
            if (end == prices.length) {
                break;
            }
            res += prices[end] - prices[beg];
        }
        return res;
    }

    private static int ascendUntil(int[] arr, int beg, boolean isAscend) {
        int ret;
        for (ret = beg + 1; ret < arr.length; ++ret) {
            if (isAscend == (arr[ret - 1] > arr[ret])) {
                break;
            }
        }
        return ret - 1;
    }
}
