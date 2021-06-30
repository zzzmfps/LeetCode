// 12ms, 80.45%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        int beg = -1, end = s.size();
        string vowels = "aeiouAEIOU";
        while (beg < end) {
            beg = s.find_first_of(vowels, beg + 1);
            end = s.find_last_of(vowels, end - 1);
            if (beg < end) swap(s[beg], s[end]);
        }
        return s;
    }
};
