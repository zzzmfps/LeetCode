// 4 ms, 84.90%; 8.3 MB, 50.12%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSatisfaction(vector<int> &satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());

        int n = satisfaction.size();
        vector<int> rsum(1 + n);
        for (int i = n - 1; i > -1; --i) rsum[i] = rsum[i + 1] + satisfaction[i];

        int res = 0, i = n - 1;
        while (i > -1 && rsum[i] > 0) res += rsum[i--];
        return res;
    }
};
