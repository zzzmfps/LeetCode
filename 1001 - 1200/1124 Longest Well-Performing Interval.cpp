// 32ms, 77.62%; 12.2MB, 100.00%
class Solution
{
public:
    int longestWPI(const vector<int> &hours)
    {
        int res = 0, score = 0;
        unordered_map<int, int>tmp;
        for (int i = 0, size = hours.size(); i < size; ++i) {
            score += (hours[i] > 8 ? 1 : -1);
            if (score > 0) res = i + 1;
            auto it = tmp.find(score);
            if (it == tmp.end()) tmp[score] = i;
            it = tmp.find(score - 1);
            if (it != tmp.end()) res = max(res, i - it->second);
        }
        return res;
    }
};
