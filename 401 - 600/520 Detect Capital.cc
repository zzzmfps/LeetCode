// 0ms, 100.00%; 8.3MB, 37.50%
class Solution
{
public:
    bool detectCapitalUse(const string &word)
    {
        if (word.size() == 1) return true;
        auto p1 = [](char c) { return islower(c); };
        auto p2 = [](char c) { return isupper(c); };
        if (islower(word[0])) return all_of(word.begin() + 1, word.end(), p1);
        if (islower(word[1])) return all_of(word.begin() + 2, word.end(), p1);
        return all_of(word.begin() + 2, word.end(), p2);
    }
};
