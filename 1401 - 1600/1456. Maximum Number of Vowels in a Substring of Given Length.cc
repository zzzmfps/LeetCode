// 32 ms, 40.00%; 9.4 MB, 99.28%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxVowels(const string &s, int k) const {
        vector<bool> record(s.size());
        for (int i = 0; i < s.size(); ++i) record[i] = this->isVowels(s[i]);

        int end = 0, curVowels = 0;
        while (end < k) curVowels += record[end++];

        int begin = 0, maxVowels = curVowels;
        while (end < s.size()) {
            curVowels += record[end++] - record[begin++];
            maxVowels = max(maxVowels, curVowels);
        }

        return maxVowels;
    }

private:
    static bool isVowels(char c) {
        static const string VOWELS = "aeiou";
        return VOWELS.find(c) != string::npos;
    }
};
