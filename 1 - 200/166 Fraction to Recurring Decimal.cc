// 6ms, 4.23%
static int x = []() {
    ios_base::sync_with_stdio(false); // toggles off the synchronization
    cin.tie(nullptr);                 // ties cin with nullptr, not cout
    return 0;
}();

class Solution
{
  public:
    string fractionToDecimal(long long numerator, long long denominator)
    {
        string res = numerator * denominator < 0 ? "-" : "";
        numerator = abs(numerator), denominator = abs(denominator);
        long long integer = numerator / denominator;
        res += to_string(integer);
        numerator -= integer * denominator;
        vector<pair<string, int>> decimal;

        while (numerator)
        {
            numerator *= 10;
            int res1 = numerator / denominator;
            int res2 = numerator - res1 * denominator;
            numerator = res2;
            auto p = make_pair(to_string(res1), res2);
            auto it = find(decimal.begin(), decimal.end(), p);
            if (it != decimal.end())
            {
                decimal.insert(it, make_pair("(", 0));
                decimal.push_back(make_pair(")", 0));
                break;
            }
            else
                decimal.push_back(p);
        }
        if (!decimal.empty())
        {
            res += ".";
            for (const auto &p : decimal)
                res += p.first;
        }
        return res;
    }
};
