// 4 ms, 93.56%; 9.4 MB, 28.41%
#include <bits/stdc++.h>
using namespace std;

using Range = pair<size_t, size_t>;

class Solution {
public:
    bool parseBoolExpr(const string &expression) {
        return this->parse(expression, 0, expression.size());
    }

private:
    bool parse(const string &expression, size_t l, size_t r) {
        char ex = expression[l];
        if (l + 1 == r) return 't' == ex;
        if ('!' == ex) return !this->parse(expression, l + 2, r - 1);

        auto spl = this->split(expression, l + 2, r - 1);
        bool res = this->parse(expression, spl[0].first, spl[0].second);
        for (size_t i = 1; i < spl.size(); ++i) {
            if ('&' == ex && !res || '|' == ex && res) return res;
            res = this->op(ex, res, this->parse(expression, spl[i].first, spl[i].second));
        }
        return res;
    }

    bool op(char ex, bool b1, bool b2) {
        return ('&' == ex) ? b1 & b2 : b1 | b2;
    }

    vector<Range> split(const string &expression, size_t l, size_t r) {
        vector<Range> ret;
        size_t count = 0, i = l, j;
        for (j = l + 1; j < r; ++j) {
            char c = expression[j];
            count += ('(' == c ? 1 : ')' == c ? -1 : 0);
            if (0 == count && ',' == c) {
                ret.emplace_back(i, j);
                i = j = j + 1;
            }
        }
        ret.emplace_back(i, j);
        return ret;
    }
};
