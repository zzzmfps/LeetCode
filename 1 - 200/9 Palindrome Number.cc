// 159ms, 60.26%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || x != 0 && x % 10 == 0) return false;
        if (x >= 0 && x <= 9) return true;

        int ptr1 = log(x) / log(10) + 1;
        int ptr2 = 1;
        int cnt = ptr1 / 2;

        while (cnt-- > 0) {
            int fac1 = pow(10, ptr1 - 1);
            int fac2 = pow(10, ptr2 - 1);
            if (x / fac1 % 10 != x / fac2 % 10) return false;
            --ptr1;
            ++ptr2;
        }
        return true;
    }
};
