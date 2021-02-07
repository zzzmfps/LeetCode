// 6ms, 34.66%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for (int i = 1; i <= n; ++i) {
            int mod3 = i % 3, mod5 = i % 5;
            if (mod3 == 0 && mod5 == 0)
                res.push_back("FizzBuzz");
            else if (mod3 == 0)
                res.push_back("Fizz");
            else if (mod5 == 0)
                res.push_back("Buzz");
            else
                res.push_back(to_string(i));
        }
        return res;
    }
};
