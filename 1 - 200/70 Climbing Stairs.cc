// 3ms, 0.93%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int fib1 = 1, fib2 = 1;
        while (--n) fib1 = (fib2 += fib1) - fib1;
        return fib2;
    }
};
