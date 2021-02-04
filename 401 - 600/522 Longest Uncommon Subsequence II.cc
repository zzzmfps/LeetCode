// 4ms, 70.47%; 8.7MB, 50.00%
class Solution
{
public:
    int findLUSlength(vector<string> &strs)
    {
        auto sortRule = [](const string &x, const string &y) { return x.size() > y.size(); };
        auto isSubseq = [](const string &x, const string &y) {
            int i = 0, size = y.size();
            for (auto c : x) {
                while (i < size && y[i] != c) ++i;
                if (i == size) return false;
                ++i;
            }
            return true;
        };
        sort(strs.begin(), strs.end(), sortRule);
        for (int i = 0, size = strs.size(); i < size; ++i) {
            bool flag = true;
            for (int j = 0; j < size; ++j) {
                if (i == j) continue;
                if (strs[j].size() < strs[i].size()) break;
                if (isSubseq(strs[i], strs[j])) {
                    flag = false;
                    break;
                }
            }
            if (flag) return strs[i].size();
        }
        return -1;
    }
};
