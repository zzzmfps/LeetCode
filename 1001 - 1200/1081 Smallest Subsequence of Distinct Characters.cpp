// 0ms, 100.00%; 8.6MB, 100.00%
class Solution
{
public:
    string smallestSubsequence(const string &text)
    {
        string res = "";
        int last[26], seen[26] = {}, n = text.size();
        for (int i = 0; i < n; ++i) last[text[i] - 97] = i;
        for (int i = 0; i < n; ++i) {
            if (seen[text[i] - 97]++) continue; // if `res` doesn't contain `text[i]`
            while (!res.empty() && res.back() > text[i] && i < last[res.back() - 97]) // then compare the values
                seen[res.back() - 97] = 0, res.pop_back();
            res.push_back(text[i]);
        }
        return res;
    }
};
