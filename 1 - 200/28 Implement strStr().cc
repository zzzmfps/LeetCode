// 7ms, 26.76%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty())
            return 0;
        else if (haystack.empty())
            return -1;

        int len1 = haystack.length();
        int len2 = needle.length();
        int i = 0;
        int j = 0;
        for (; j < len2;)
            if (haystack[i] == needle[j])
                ++i, ++j;
            else {
                i = i - j + 1;
                if (len1 - len2 < i) return -1;
                j = 0;
            }
        return i - j;
    }
};
