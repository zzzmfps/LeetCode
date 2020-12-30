// 7ms, 100.0%
static int x = []() {
    ios_base::sync_with_stdio(false); // toggles off the synchronization
    cin.tie(nullptr);                 // ties cin with nullptr, not cout
    return 0;
}();

class Solution
{
  public:
    string licenseKeyFormatting(string s, int k)
    {
        string res = "";
        int rev = s.size(), count = 0;
        while (--rev >= 0)
            if (s[rev] != '-')
            {
                if (count == k)
                {
                    res += '-';
                    count = 0;
                }
                res += toupper(s[rev]);
                ++count;
            }
        return string(res.rbegin(), res.rend());
    }
};
