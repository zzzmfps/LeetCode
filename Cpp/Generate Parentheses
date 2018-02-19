// 3ms, 9.67%
class Solution
{
private:
    vector<string> ans;
    string str = "";
    
public:
    vector<string> generateParenthesis(int n)
    {
        addParenthesis(n, 0);
        return ans;
    } 
    
    void addParenthesis(int n, int m)
    {
        if(!n && !m) ans.push_back(str);
        str.push_back('(');
        if(n > 0) addParenthesis(n - 1, m + 1);
        str.pop_back();
        str.push_back(')');
        if(m > 0) addParenthesis(n, m - 1);
        str.pop_back();
    }
};
