// 12ms, 91.20%; 10.6MB, 100.00%
class Solution
{
public:
    string removeDuplicates(string s, int k)
    {
        vector<pair<char, int>> v;
        for (auto c : s) {
            if (v.empty() || v.back().first != c) {
                v.push_back(make_pair(c, 1));
            } else if (++v.back().second == k) {
                v.pop_back();
            }
        }
        string ret = "";
        for (auto &p : v) ret += string(p.second, p.first);
        return ret;
    }
};
