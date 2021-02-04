// 4ms, 87.53%; 8.8MB, 100.00%
class Solution
{
public:
    string removeOuterParentheses(const string &S)
    {
        string res = "";
        int tmp = 0, beg = 1, i = 1, size = S.size();
        while (i < size) {
            if (tmp == 0 && S[i] == ')') {
                res += S.substr(beg, i - beg);
                beg = i = i + 2;
                tmp = 0;
                continue;
            }
            tmp += (S[i++] == '(' ? 1 : -1);
        }
        return res;
    }
};
