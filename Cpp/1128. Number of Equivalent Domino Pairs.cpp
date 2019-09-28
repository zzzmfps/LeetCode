// 40ms, 88.91%; 23.3MB, 100.00%
class Solution
{
public:
    int numEquivDominoPairs(const vector<vector<int>> &dominoes)
    {
        int tmp[10][10] = {};
        int res = 0;
        for (auto p : dominoes) tmp[p[0]][p[1]] += 1;
        for (int i = 1; i < 10; ++i) {
            for (int j = i; j < 10; ++j) {
                int same = tmp[i][j] + tmp[j][i];
                if (i == j) same >>= 1;
                res += same * (same - 1) >> 1;
            }
        }
        return res;
    }
};
