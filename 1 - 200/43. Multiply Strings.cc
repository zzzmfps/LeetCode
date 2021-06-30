// 12ms, 24.77%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        string sum(num1.size() + num2.size(), 0);
        for (int i = num1.size() - 1; 0 <= i; --i) {
            int carry = 0;
            for (int j = num2.size() - 1; 0 <= j; --j) {
                int tmp = sum[i + j + 1] + (num1[i] - '0') * (num2[j] - '0') + carry;
                carry = tmp / 10;
                sum[i + j + 1] = tmp - carry * 10;
            }
            sum[i] += carry;
        }

        size_t startpos = sum.find_first_not_of('\0');
        if (startpos != string::npos) {
            for (int i = startpos; i < sum.size(); ++i) sum[i] += '0';
            return sum.substr(startpos);
        }
        return "0";
    }
};
