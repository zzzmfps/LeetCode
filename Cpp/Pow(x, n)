// 10ms, 12.95%
class Solution
{
public:
    double myPow(double x, int n)
    {
        if(n == 0) return 1;
        if(n < 0)
        {
            x = 1 / x;
            if(n == INT_MIN)
                return x * myPow(x, INT_MAX);
            n = -n;
        }
        int tmp = n / 2;
        return (n == tmp * 2) ? myPow(x * x, tmp) : x * myPow(x * x, tmp);
    }
};
