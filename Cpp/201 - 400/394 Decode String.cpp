// 0ms, 100.00%; 8.9MB, 70.59%
class Solution
{
public:
    string decodeString(const string &s)
    {
        string res = "";
        stack<pair<int, string>> st;
        for (int i = 0, idx1, idx2; i < s.size();) { // 1, string ends with ']'
            idx1 = s.find_first_of("[]123456789", i);
            if (idx1 == string::npos) { // 2, string ends with alpha
                res += s.substr(i);
                break;
            } else if (s[idx1] == ']') {
                auto p = st.top();
                p.second += s.substr(i, idx1 - i);
                st.pop();
                auto &str = (st.empty() ? res : st.top().second);
                while (p.first--) str += p.second;
                i = idx1 + 1;
            } else { // isdigit(s[idx1])
                if (i < idx1) (st.empty() ? res : st.top().second) += s.substr(i, idx1 - i);
                idx2 = s.find('[', idx1 + 1);
                st.emplace(stoi(s.substr(idx1, idx2 - idx1)), "");
                i = idx2 + 1;
            }
        }
        return res;
    }
};
