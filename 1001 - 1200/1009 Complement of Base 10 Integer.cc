// 4ms, 51.01%; 8.4MB, 33.33%
class Solution
{
public:
    int bitwiseComplement(int N)
    {
        if (N == 0) return 1;
        return pow(2, 1 + int(log2(N))) - 1 - N;
    }
};
