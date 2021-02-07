// 3ms, 9.71%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        int slow = n, fast = n;
        do {
            slow = calculate(slow);
            fast = calculate(fast);
            fast = calculate(fast);
        } while (slow != fast);
        if (slow == 1) return true;
        return false;
    }

private:
    int calculate(int n) {
        int res = 0;
        while (n) {
            int tmp = n % 10;
            res += tmp * tmp;
            n /= 10;
        }
        return res;
    }
};
