// 202ms, 96.02%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distributeCandies(vector<int> &candies) {
        int half = candies.size() / 2, kinds = 0;
        int kind[200001] = {};
        for (auto c : candies)
            if (kind[c + 100000] == 0) {
                kind[c + 100000] += 1;
                kinds += 1;
            }
        return min(half, kinds);
    }
};
