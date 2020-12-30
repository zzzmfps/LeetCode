// 0ms, 100.00%; 8.7MB, 76.92%
class Solution
{
public:
    int lengthLongestPath(const string &input)
    {
        stack<string> st;
        st.push(input.substr(0, input.find('\n')));
        int curLen = st.top().size(), maxLen = (st.top().find('.') != string::npos ? curLen : 0);
        for (int i = input.find('\n'), j; i++ != string::npos; i = j) {
            int level = 0; // equals to num of '\t'
            while (input[i] == '\t') i += 1, level += 1;
            while (st.size() > level) {
                curLen -= 1 + st.top().size(); // there will be '/' in path-string
                st.pop();
            }
            j = input.find('\n', i);
            st.push(input.substr(i, j - i));
            curLen += 1 + st.top().size();
            if (st.top().find('.') != string::npos) maxLen = max(maxLen, curLen);
        }
        return maxLen;
    }
};
