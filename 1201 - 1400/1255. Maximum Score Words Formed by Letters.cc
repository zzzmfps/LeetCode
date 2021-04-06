// 8 ms, 62.03%; 9.9 MB, 61.45%
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScoreWords(const vector<string> &words, const vector<char> &letters, const vector<int> &score) {
        vector<int> iLetters = this->counts(letters, score);
        vector<vector<int>> iWords;
        for (auto &&w : words) {
            auto tmp = this->counts(w, score);
            if (this->check(iLetters, tmp)) iWords.push_back(move(tmp));
        }
        if (iWords.empty()) return 0;

        int total = iLetters.back(), maxScore = 0;
        auto dfs = [&](auto &&self, int _next) {
            if (_next == iWords.size()) {
                maxScore = max(maxScore, total - iLetters.back());
                return;
            }
            self(self, 1 + _next);
            if (this->check(iLetters, iWords[_next])) {
                this->update(iLetters, iWords[_next], minus<int>());
                self(self, 1 + _next);
                this->update(iLetters, iWords[_next], plus<int>());
            }
        };
        dfs(dfs, 0);

        return maxScore;
    }

private:
    template <typename T>
    vector<int> counts(const T &container, const vector<int> &score) {
        vector<int> cnt(27);
        for (auto &&c : container) {
            ++cnt[c - 97];
            cnt[26] += score[c - 97];
        }
        return cnt;
    }

    template <typename T>
    void update(vector<int> &v1, const vector<int> &v2, const T &op) {
        for (int i = 0; i < 27; ++i) v1[i] = op(v1[i], v2[i]);
    }

    bool check(const vector<int> &v1, const vector<int> &v2) {
        for (int i = 0; i < 26; ++i)
            if (v1[i] < v2[i]) return false;
        return true;
    }
};
