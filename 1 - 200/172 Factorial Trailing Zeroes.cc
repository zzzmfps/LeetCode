// 4ms, 7.04%
class Solution
{
public:
    int trailingZeroes(int n)
    {
        int zeroes = 0;
        while(n >= 5)
        {
            int tmp = n / 5;
            zeroes += tmp;
            n = tmp;
        }
        return zeroes;
    }
};
