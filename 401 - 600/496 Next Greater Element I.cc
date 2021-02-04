// 4ms, 100.0%
static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
  public:
    vector<int> nextGreaterElement(const vector<int> &findNums, const vector<int> &nums)
    {
        if (findNums.empty()) return vector<int>();
        
        int size1 = findNums.size(), size2 = nums.size();

        unordered_map<int, int> index(size2 * 2);
        for (int i = 0; i < size2; ++i) index[nums[i]] = i;

        vector<int> revMax;
        revMax.resize(size2);
        revMax.back() = nums.back() - 1;
        for (int i = size2 - 2; i >= 0; --i) revMax[i] = max(revMax[i + 1], nums[i + 1]);

        vector<int> res;
        res.resize(size1, -1);
        for (int i = 0; i < size1; ++i) {
            auto idx = index[findNums[i]];
            if (revMax[idx] > findNums[i])
                for (int j = idx + 1; j < size2; ++j)
                    if (nums[j] > findNums[i]) {
                        res[i] = nums[j];
                        break;
                    }
        }
        return res;
    }
};
