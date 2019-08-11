// 0ms, 100.00%; 8.1MB, 100.00%
class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        for (int i = 0, limit = 1 + sqrt(c / 2); i < limit; ++i) {
            int tmp = c - i * i;
            if (tmp == pow(int(sqrt(tmp)), 2)) return true;
        }
        return false;
    }
};
