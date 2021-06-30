// 9ms, 55.04%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compress(vector<char> &chars) {
        int index = 1, pre_char = 0, cur_num = 1;
        int i = 1;
        while (i < chars.size()) {
            if (chars[pre_char] == chars[i])
                cur_num += 1;
            else {
                if (cur_num == 1)
                    pre_char = i;
                else {
                    string tmp = to_string(cur_num);
                    replace(chars, index, i, cur_num);
                    index += tmp.size();
                    pre_char = i = index;
                }
                index += 1;
                cur_num = 1;
            }
            i += 1;
        }
        replace(chars, index, chars.size(), cur_num);
        return chars.size();
    }

private:
    void replace(vector<char> &chars, int beg, int end, int cur) {
        chars.erase(chars.begin() + beg, chars.begin() + end);
        if (cur == 1) return;
        string scur = to_string(cur);
        chars.insert(chars.begin() + beg, scur.begin(), scur.end());
    }
};
