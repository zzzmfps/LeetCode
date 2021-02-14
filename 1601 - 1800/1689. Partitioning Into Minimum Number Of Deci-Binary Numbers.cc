// 32 ms, 91.68%; 11.7 MB, 100.00%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPartitions(const string &n) {
        char res = '0';
        for (auto &&c : n) {
            res = max(res, c);
            if ('9' == res) break;
        }
        return res - 48;
    }
};
