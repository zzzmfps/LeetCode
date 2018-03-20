// 6ms, 71.60%
class Solution {
public:
    char findTheDifference(const string &s, const string &t) const {
        char check = 0;
        for (const auto ss : s) check ^= ss;
        for (const auto tt : t) check ^= tt;
        return check;
    }
};
