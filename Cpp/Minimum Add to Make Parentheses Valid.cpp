// 0ms, 100.00%; 8.6MB, 46.15%
class Solution
{
public:
    int minAddToMakeValid(const string &S)
    {
        stack<char> st;
        for (auto c : S) {
            if (!st.empty() && st.top() == '(' && c == ')') {
                st.pop();
            } else {
                st.push(c);
            }
        }
        return st.size();
    }
};
