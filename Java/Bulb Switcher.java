// 0ms, 100.00%; 36.1MB, 77.33%
class Solution {
    public int bulbSwitch(int n) {
        int m = 1, count = 0;
        while (m * m <= n) {
            ++m;
            ++count;
        }
        return count;
    }
}
