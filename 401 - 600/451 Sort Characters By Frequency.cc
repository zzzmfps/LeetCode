// 4ms, 100.0%
static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
  public:
    string frequencySort(const string &s)
    {
        vector<pair<char, int>> sol;
        int tmp[127]{};
        for (const auto &c : s) ++tmp[c];
        for (int i = 32; i < 127; ++i)  // 32 for ' ', 126 for '~'
            if (tmp[i]) sol.push_back(make_pair(char(i), tmp[i]));
        sort(sol.begin(), sol.end(),
             [](const pair<char, int> &x, const pair<char, int> &y) { return x.second > y.second; });
        string res = "";
        for (const auto &p : sol) res += string(p.second, p.first);
        return res;
    }
};
