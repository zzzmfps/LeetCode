// 8ms, 21.92%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int profit = 0;
        int day = 0, end = prices.size() - 1;
        while (day < end) {
            if (prices[day] > prices[day + 1]) {
                ++day;
                continue;
            }
            int count = 1;
            while (day + count < end && prices[day + count] < prices[day + count + 1]) ++count;
            profit += prices[day + count] - prices[day];
            day += count + 1;
        }
        return profit;
    }
};
