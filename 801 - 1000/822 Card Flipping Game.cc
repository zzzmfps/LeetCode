// 20ms, 70.29%; 10.7MB, 33.33%
class Solution
{
public:
    int flipgame(const vector<int> &fronts, const vector<int> &backs)
    {
        unordered_set<int> record;  // a vector cannot perform better, maybe because fronts.size() is small
        for (int i = 0, size = fronts.size(); i < size; ++i)
            if (fronts[i] == backs[i]) record.insert(fronts[i]);
        int ret = 2001;
        for (auto f : fronts)
            if (f < ret && record.find(f) == record.end()) ret = f;
        for (auto b : backs)
            if (b < ret && record.find(b) == record.end()) ret = b;
        return (ret == 2001 ? 0 : ret);
    }
};
