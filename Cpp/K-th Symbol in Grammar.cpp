// 0ms, 100.00%; 8.5MB, 8.33%
class Solution
{
public:
    int kthGrammar(int N, int K)
    {
        bool isNot = false;
        while (K > 2) {
            int row = ceil(log2(K));
            if (row & 1) {
                isNot ^= true;
                K -= (1 << (row - 1));
            } else {
                K = (1 << row) - K + 1;
            }
        }
        return (isNot ? 2 - K : K - 1);
    }
};
