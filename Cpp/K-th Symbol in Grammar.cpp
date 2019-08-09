// 4ms, 55.25%; 8.2MB, 83.33%
class Solution
{
public:
    int kthGrammar(int N, int K)
    {
        bool isNot = false;
        while (K > 2) {
            int row = 1 + ceil(log2(K));
            if (row & 1) {
                K = (1 << (row - 1)) - K + 1;
            } else {
                isNot ^= true;
                K -= (1 << (row - 2));
            }
        }
        return (isNot ? 2 - K : K - 1);
    }
};
