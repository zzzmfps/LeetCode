// 0ms, 100.00%; 36.6MB, 5.51%
class Solution {
    public int fib(int N) {
        if (N < 2) {
            return N;
        }
        int[] a = new int[N + 1];
        a[0] = 0;
        a[1] = 1;
        for (int i = 2; i <= N; ++i) {
            a[i] = a[i - 1] + a[i - 2];
        }
        return a[N];
    }
}
