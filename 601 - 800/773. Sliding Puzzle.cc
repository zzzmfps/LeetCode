// 8 ms, 88.32%; 8.2 MB, 86.68%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int slidingPuzzle(const vector<vector<int>> &board) {
        string target = "123450";
        vector<vector<int>> pos = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};

        string given = "";
        for (size_t i = 0; i < 2; ++i)
            for (size_t j = 0; j < 3; ++j) given += char(48 + board[i][j]);

        unordered_set<string> record;
        queue<string> q;
        record.insert(given);
        q.push(given);

        for (int res = 0; !q.empty(); ++res) {
            for (size_t i = q.size(); i > 0; --i) {
                auto &f = q.front();
                if (f == target) return res;
                int idx = f.find('0');
                for (auto &&p : pos[idx]) {
                    string n = this->swap(f, idx, p);
                    if (record.find(n) != record.end()) continue;
                    record.insert(n);
                    q.push(n);
                }
                q.pop();
            }
        }

        return -1;
    }

private:
    string swap(const string &str, int i, int j) {
        string ret = str;
        char tmp = ret[i];
        ret[i] = ret[j];
        ret[j] = tmp;
        return ret;
    }
};
