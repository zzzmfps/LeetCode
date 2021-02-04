// 5ms, 86.17%
static int x = []() {
    ios_base::sync_with_stdio(false); // toggles off the synchronization
    cin.tie(nullptr);                 // ties cin with nullptr, not cout
    return 0;
}();

class Solution
{
  public:
    vector<int> grayCode(int n)
    {
        vector<int> result(1 << n, 0);
        for (int i = 0; i < n; ++i)
        {
            int cur, trav, incre;
            cur = trav = incre = 1 << i;
            while (cur)
                result[trav++] = result[--cur] | incre;
        }
        return result;
    }
};
