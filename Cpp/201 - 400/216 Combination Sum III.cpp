// 2ms, 32.34%
class Solution
{
public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> res;
        vector<int> combination;
        combinationSum(n, res, combination, 1, k);
        return res;
    }
    
private:
    void combinationSum(int target, vector<vector<int>> &res, vector<int> &combination,
                        int begin, int k)
    {
        if(!target && !k)
        {
            res.push_back(combination);
            return;
        }
        for(int i = begin; i < 10 && i <= target; ++i)
        {
            combination.push_back(i);
            combinationSum(target - i, res, combination, i + 1, k - 1);
            combination.pop_back();
        }
    }
};
