// 0ms, 100.00%; 8.6MB, 100.00%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string seq = "123456789";
        int len1 = 1 + int(log10(low)), len2 = 1 + int(log10(high));
        vector<int> ret;
        for (int i = len1; i <= len2; ++i) {
            int start = stoi(seq.substr(0, i)), delta = stoi(string(i, '1'));
            for (int j = i, cur = start; j < 10; ++j) {
                if (cur >= low && cur <= high) ret.push_back(cur);
                cur += delta;
            }
        }
        return ret;
    }
};
