// 0 ms, 100.00%; 5.9 MB, 78.37%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = 0, full = numBottles, empty = 0;
        while (full) {
            res += full;
            full = numBottles / numExchange;
            empty = numBottles % numExchange;
            numBottles = full + empty;
        }
        return res;
    }
};
