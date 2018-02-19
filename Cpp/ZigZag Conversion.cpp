// 35ms, 27.56%
class Solution
{
public:
    string convert(string s, int numRows)
    {
        if(s.empty() || s.length() == 1 || numRows == 1)
            return s;
        string ans[numRows];
        for(auto x : ans) x = "";
        
        bool incre = true;
        for(int idx = 0, row = 0; idx < s.length(); ++idx)
        {
            ans[row] += s[idx];
            row += incre ? 1 : -1;
            if(row == numRows - 1) incre = false;
            else if(row == 0) incre = true; 
        }
        for(int row = 1; row < numRows; ++row)
            ans[0] += ans[row];
        
        return ans[0];
    }
};
