// 8ms, 100.0%
static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
  public:
    vector<int> findErrorNums(const vector<int> &nums)
    {
        vector<int> res;
        bool *isExist = new bool[nums.size() + 1]{};
        for (const auto x : nums)
            if (isExist[x]) {
                res.push_back(x);
            } else {
                isExist[x] = true;
            }
        for (int i = 1, n = nums.size(); i <= n; ++i)
            if (!isExist[i]) {
                res.push_back(i);
                break;
            }
        return res;
    }
};
