// 21ms, 99.89%
static int x = []() {
    ios_base::sync_with_stdio(false); // toggles off the synchronization
    cin.tie(nullptr);                 // ties cin with nullptr, not cout
    return 0;
}();

class Solution
{
  private:
    vector<int> max_min = vector<int>(5);

  public:
    int maximumProduct(const vector<int> &nums)
    {
        partial_sort_copy(nums.cbegin(), nums.cend(),
                          max_min.begin(), max_min.begin() + 3, greater<int>());
        partial_sort_copy(nums.cbegin(), nums.cend(),
                          max_min.end() - 2, max_min.end());
        int res1 = max_min[0] * max_min[1] * max_min[2];
        int res2 = max_min[0] * max_min[3] * max_min[4];
        return res1 > res2 ? res1 : res2;
    }
};
