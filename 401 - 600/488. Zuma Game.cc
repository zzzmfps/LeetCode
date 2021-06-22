// 1032 ms, 7.14%; 15.1 MB, 74.72%
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    static constexpr int MAX = 6;

public:
    int findMinStep(const string &board, const string &hand) {
        unordered_map<char, int> cnts;
        for (auto &&c : hand) ++cnts[c];

        int _min = MAX;
        this->dfs(board, cnts, 0, _min);
        return (_min == MAX ? -1 : _min);
    }

private:
    void dfs(const string &board, unordered_map<char, int> &cnts, int level, int &_min) {
        if (level == _min) return;
        if (board.empty()) _min = level;
        for (size_t i = 0; i < board.size(); ++i) {
            if (i && board[i] == board[i - 1]) continue;
            for (auto &&p : cnts) {
                if (0 == p.second) continue;
                --p.second;
                string inserted = board.substr(0, i + 1) + p.first + board.substr(i + 1);
                this->removeConsecutive(inserted);
                this->dfs(inserted, cnts, 1 + level, _min);
                ++p.second;
            }
        }
    }

    void removeConsecutive(string &str) {
        int i = 0, j = 1;
        while (true) {
            while (j < str.size() && str[j] == str[i]) ++j;
            if (j - i > 2) {
                str.erase(i, j - i);
                i = max(0, i - 2), j = i + 1;
                continue;
            }
            if (j >= str.size()) break;
            i = j;
        }
    }
};
