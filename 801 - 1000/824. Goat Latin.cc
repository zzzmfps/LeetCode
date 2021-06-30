// 4ms, 100.0%; 9.3MB, 98.11%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    string toGoatLatin(const string &S) {
        if (S.empty()) return "";

        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        stringstream sin(S);
        string res = "", tmp, post = "maa";
        while (sin >> tmp) {
            if (vowels.find(tmp[0]) != vowels.end()) {
                res += tmp + post;
            } else {
                res += tmp.substr(1) + tmp[0] + post;
            }
            post += 'a';
            if (!sin.eof()) res += ' ';
        }
        return res;
    }
};
