// 11ms, 18.66%
class Solution {
public:
    string reverseString(string s) {
        int index = s.size() - 1;
        string res = "";
        while (index >= 0)
            res += s[index--];
        return res;
    }
};
