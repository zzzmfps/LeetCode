// 12ms, 97.65%; 10.4MB, 98.77%
#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    string simplifyPath(string &path) {
        path += '/';
        vector<string> vec;
        vec.reserve(path.size() / 2);
        int next = 0;
        while (true) {
            int idx = path.find_first_not_of('/', next);
            if (idx == string::npos) break;
            next = path.find_first_of('/', idx);
            string tmp = path.substr(idx, next - idx);
            if (tmp == "..") {
                if (!vec.empty()) vec.pop_back();
            } else if (tmp != ".") {
                vec.push_back(tmp);
            }
        }
        if (vec.empty()) return "/";
        string res = "";
        for (const auto &s : vec) res += "/" + s;
        return res;
    }
};
