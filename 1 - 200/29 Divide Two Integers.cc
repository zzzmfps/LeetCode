// 24ms, 25.16%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (!divisor || dividend == INT_MIN && divisor == -1) return INT_MAX;
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        unsigned dvd = abs(dividend);
        unsigned dvs = abs(divisor);
        int res = 0;
        while (dvd >= dvs) {
            unsigned temp = dvs, multiple = 1;
            while (dvd - temp >= temp) {
                temp <<= 1;
                multiple <<= 1;
            }
            dvd -= temp;
            res += multiple;
        }
        return sign * res;
    }
};
