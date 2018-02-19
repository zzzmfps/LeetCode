// 3ms, 0.55%
class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> ans(rowIndex + 1, 1);
        int num = 0;
        while(++num < rowIndex)
            for(int i = num; i > 0; --i)
                ans[i] += ans[i - 1];
        return ans;
    }
};
