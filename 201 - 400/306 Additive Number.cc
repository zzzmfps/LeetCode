// 3ms, 47.72%
static int x = []() {
    ios_base::sync_with_stdio(false); // toggles off the synchronization
    cin.tie(nullptr);                 // ties cin with nullptr, not cout
    return 0;
}();

class Solution
{
  public:
    bool isAdditiveNumber(const string &num)
    {
        int size = num.size();
        for (int i = 1; i < size - 1; ++i)
            for (int j = i + 1; j < size; ++j)
            {
                string a = num.substr(0, i), b = num.substr(i, j - i);
                if (a[0] == '0' && i > 1)
                    return false;
                if (b[0] == '0' && j - i > 1)
                    break;
                int k = j;
                while (k < size)
                {
                    ostringstream oss;
                    oss << stoll(a) + stoll(b);
                    string c = oss.str();
                    if (c != num.substr(k, c.size()))
                        break;
                    k = k + c.size();
                    a = b, b = c;
                }
                if (k == size)
                    return true;
            }
        return false;
    }
};
