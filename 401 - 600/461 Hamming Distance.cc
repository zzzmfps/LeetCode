// 4ms, 99.96%
static int x = []() {
    ios_base::sync_with_stdio(false); // toggles off the synchronization
    cin.tie(nullptr);                 // ties cin with nullptr, not cout
    return 0;
}();

class Solution
{
  public:
    int hammingDistance(int x, int y)
    {
        int dist = x ^ y;
        int count = 0;
        while (dist)
        {
            count += 1;
            dist &= dist - 1;
        }
        return count;
    }
};
