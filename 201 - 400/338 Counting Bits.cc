// 52ms, 92.30%; 9.6MB, 58.54%
class Solution
{
public:
    vector<int> countBits(int num)
    {
        vector<int> res(num + 1, 0);
        for (int i = 1; i <= num; ++i) {
            if (res[i]) continue;
            res[i] = count(i);
            int j = i << 1;
            while (j <= num) {
                res[j] = res[i];
                j <<= 1;
            }
        }
        return res;
    }

private:
    int count(int n)
    {
        int cnt = 0;
        while (n) {
            if (n & 1) cnt += 1;
            n >>= 1;
        }
        return cnt;
    }
};
