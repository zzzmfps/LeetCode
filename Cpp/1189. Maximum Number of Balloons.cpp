// 0ms, 100.00%; 8.7MB, 100.00%
class Solution
{
public:
    int maxNumberOfBalloons(const string &text)
    {
        int instance[26] = {}, tmp[26] = {};
        instance[0] = instance[1] = instance[13] = 1;
        instance[11] = instance[14] = 2;
        for (auto c : text) tmp[c - 97] += 1;
        int res = text.size();
        for (int i = 0; i < 26; ++i) {
            if (instance[i] == 0) continue;
            res = min(res, tmp[i] / instance[i]);
        }
        return res;
    }
};
