// 2ms, 28.59%
class Solution {
public:
    int uniquePaths(int m, int n) {
        int fac1 = m + n - 2, fac2 = min(m, n) - 1;
        double res = 1;
        for (; fac2 > 0; --fac1, --fac2)
            res *= double(fac1) / fac2;
        return int(res + 0.5);
    }
};
