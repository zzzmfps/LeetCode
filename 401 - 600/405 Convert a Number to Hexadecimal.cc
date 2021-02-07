// 4ms, 82.80%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        unsigned un_num = num;
        char hexalpha[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
        string res = "";
        while (un_num) {
            int tmp = un_num % 16;
            un_num /= 16;
            res += hexalpha[tmp];
        }
        return string(res.rbegin(), res.rend());
    }
};
