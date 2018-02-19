// 6ms, 2.03%
class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int res = 0;
        while(n)
        {
            n &= n - 1;
            ++res;
        }
        return res;
    }
};
