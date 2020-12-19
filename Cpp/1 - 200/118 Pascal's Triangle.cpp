// 3ms, 1.76%
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        if(!numRows) return vector<vector<int>>();
        
        vector<vector<int>> ans;
        ans.push_back(vector<int>({1}));
        int index = 0;
        while(++index < numRows)
        {
            vector<int> tmp(index + 1, 1);
            for(int i = index - 1; i > 0; --i)
                tmp[index - i] = ans[index - 1][index - i - 1] + ans[index - 1][index - i];
            ans.push_back(tmp);
        }
        
        return ans;
    }
};
