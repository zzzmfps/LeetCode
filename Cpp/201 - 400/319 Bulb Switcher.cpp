// 0ms, 100.00%; 6.2MB, 5.13%
class Solution
{
public:
    int bulbSwitch(int n)
    {
        int m = 1, count = 0;
        while (m * m <= n) ++m, ++count;
        return count;
    }
};
