// 7ms, 7.22%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string cns("1");
        while (--n) {
            char temp = cns[0];
            int count = 0;
            string res = "";
            stringstream ss;
            for (auto x : cns)
                if (x == temp)
                    ++count;
                else {
                    ss << count;
                    res = res + ss.str() + temp;
                    count = 1;
                    temp = x;
                    ss.str("");
                }
            ss << count;
            cns = res + ss.str() + temp;
        }
        return cns;
    }
};
