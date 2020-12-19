// 20ms, 9.72%; 8.5MB, 100.00%
class Solution
{
public:
    vector<int> sumZero(int n)
    {
        vector<int> res(n);
        n &= 0x7FFFFFFE;
        while (n) {
            res[n - 1] = n, res[n - 2] = -n;
            n -= 2;
        }
        return res;
    }
};
