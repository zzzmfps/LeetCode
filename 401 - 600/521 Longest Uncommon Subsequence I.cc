// 0ms, 100.00%; 8.3MB, 60.00%
class Solution
{
public:
    int findLUSlength(const string &a, const string &b)
    {
        if (a == b) return -1;
        return max(a.size(), b.size());
    }
};
