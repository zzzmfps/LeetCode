// 20ms, 87.43%; 13MB, 100.00%
class Solution
{
public:
    string removeDuplicates(const string &S)
    {   // every duplicate removal consists of two adjacent and equal letters
        stack<char> q;
        for (auto c : S) {
            if (q.empty() || q.top() != c) {
                q.push(c);
            } else {
                q.pop();
            }
        }
        string ret = "";
        while (!q.empty()) {
            ret += q.top();
            q.pop();
        }
        return string(ret.rbegin(), ret.rend());
    }
};
