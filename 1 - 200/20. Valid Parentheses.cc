// 2ms, 98.01%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        string par = "";
        for (auto x : s) {
            switch (x) {
                case '(': par += '('; break;
                case '[': par += '['; break;
                case '{': par += '{'; break;
                case ')':
                    if (par[par.length() - 1] != '(') return false;
                    par.erase(par.end() - 1);
                    break;
                case ']':
                    if (par[par.length() - 1] != '[') return false;
                    par.erase(par.end() - 1);
                    break;
                case '}':
                    if (par[par.length() - 1] != '{') return false;
                    par.erase(par.end() - 1);
                    break;
            }
        }
        if (par == "") return true;
        return false;
    }
};
