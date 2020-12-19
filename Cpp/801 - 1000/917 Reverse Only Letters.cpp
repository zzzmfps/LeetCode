// 0ms, 100.00%; 8.2MB, 100.00%
class Solution
{
public:
    string reverseOnlyLetters(string S)
    {
        int i = 0, j = S.size() - 1;
        while (i < j) {
            if (!isalpha(S[i])) {
                ++i;
            } else if (!isalpha(S[j])) {
                --j;
            } else {
                swap(S[i++], S[j--]);
            }
        }
        return S;
    }
};
