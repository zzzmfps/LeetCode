// 12ms, 53.87%
class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        int n = nums.size(), newSize = 1;
        while(n) newSize *= n--;
        vector<vector<int>> res;
        while(newSize--)
        {
            res.push_back(nums);
            next_permutation(nums.begin(), nums.end());
        }
        return res;
    }
};
