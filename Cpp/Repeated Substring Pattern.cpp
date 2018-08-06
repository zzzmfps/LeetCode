// 16ms, 98.28%
static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
  public:
    bool repeatedSubstringPattern(const string &s)
    {
        int size = s.size(), limit = size / 2;
        for (int i = 1; i <= limit; ++i) {
            if (size % i != 0) continue;
            int count = size / i;
            string str = "", tmp = s.substr(0, i);
            while (count--) str += tmp;
            if (str == s) return true;
        }
        return false;
    }
};
