// 3ms, 98.26%
static int x = []() {
    ios_base::sync_with_stdio(false); // toggles off the synchronization
    cin.tie(nullptr);                 // ties cin with nullptr, not cout
    return 0;
}();

class Solution
{
  public:
    int numTilings(int n)
    {
        if (n == 1)
            return 1;
        long long res[] = {1, 1, 2};
        for (int i = 2; i < n; ++i)
        {
            int temp = res[0];
            res[0] = res[1];
            res[1] = res[2];
            res[2] = (res[2] * 2 + temp) % 1000000007;
        }
        return res[2];
    }
};
