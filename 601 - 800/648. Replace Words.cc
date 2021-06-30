// 20ms, 99.88%; 21.3MB, 93.40%
#include <bits/stdc++.h>
using namespace std;

auto x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    string replaceWords(vector<string> &dict, string &sentence) {
        prune(dict);
        stringstream ss(sentence);
        string res = "", tmp;
        while (ss >> tmp) {
            for (const auto &pre : dict)
                if (startwith(tmp, pre)) {
                    tmp = pre;
                    break;
                }
            res += tmp + " ";
        }
        res.pop_back();
        return res;
    }

private:
    void prune(vector<string> &dict) {
        sort(dict.begin(), dict.end());
        for (int i = 0; i < dict.size(); ++i)
            for (int j = i + 1; j < dict.size();) {
                if (!startwith(dict[j], dict[i])) break;
                dict.erase(dict.begin() + j);
            }
    }

    bool startwith(const string &x, const string &y) {
        for (int i = 0, j = y.size(); i < j; ++i)
            if (x[i] != y[i]) return false;
        return true;
    }
};
