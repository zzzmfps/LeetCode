// 24ms, 23.29%; 8.9MB, 100.00%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.size() == k) return "0";
        while (k--) {
            auto it = prev(is_sorted_until(num.begin(), num.end()));
            num.erase(it);
        }
        auto it = num.find_first_not_of('0');
        if (it == string::npos) return "0";
        return num.substr(it);
    }
};
