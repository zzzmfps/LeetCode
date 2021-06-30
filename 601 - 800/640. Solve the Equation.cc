// 0ms, 100.0%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    string solveEquation(const string &equation) {
        int cx = 0, cn = 0;
        int delim = equation.find('=');
        helper(equation.substr(0, delim), cx, cn);
        helper(equation.substr(delim + 1), cx, cn, -1);

        if (cx == 0) {
            return (cn == 0) ? "Infinite solutions" : "No solution";
        } else {
            return "x=" + to_string(cn / cx);
        }
    }

private:
    void helper(const string &str, int &cx, int &cn, int sign = 1) {
        int i, j = 0, length = str.size();
        do {
            i = j;
            j = str.find_first_of("+-", i + 1);
            if (j == string::npos) j = length;
            int size = j - i;
            if (str[j - 1] == 'x') {
                if (size == 1)
                    cx += sign;
                else if (size == 2 && str[i] == '+')
                    cx += sign;
                else if (size == 2 && str[i] == '-')
                    cx -= sign;
                else
                    cx += sign * stoi(str.substr(i, size));
            } else {
                cn += -sign * stoi(str.substr(i, size));
            }
        } while (j != length);
    }
};
