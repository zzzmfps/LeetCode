// 4ms, 58.21%; 8.2MB, 100.00%
class Solution
{
public:
    int dayOfYear(const string &date)
    {
        const int days[12] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
        int y = stoi(date.substr(0, 4)), m = stoi(date.substr(5, 2)), d = stoi(date.substr(8, 2));
        int ret = 0;
        if (m > 2 && (y % 400 == 0 || y % 100 != 0 && y % 4 == 0)) ret = 1;
        return ret + days[m - 1] + d;
    }
};
